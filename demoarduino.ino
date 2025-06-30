#include <LMotorController.h>
#include <PID_v1.h>
#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
  #include "Wire.h"
#endif

//───────────────────────────//
// 1. KHAI BÁO & STATE MACHINE
//───────────────────────────//

#define MIN_ABS_SPEED    35

// --- MPU6050 variables ---
MPU6050 mpu;
bool    dmpReady     = false;
uint8_t mpuIntStatus;
uint8_t devStatus;
uint16_t packetSize;
uint16_t fifoCount;
uint8_t fifoBuffer[64];
Quaternion  q;
VectorFloat gravity;
float       ypr[3];
volatile bool mpuInterrupt = false;

// --- PID variables ---
double originalSetpoint   = 176.77;
double setpoint           = originalSetpoint;
double movingAngleOffset  = 6;
double input, output;
double Kp = 40, Ki = 150, Kd = 1.5;
PID    pid(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT);

// --- Motor variables ---
double motorSpeedFactorLeft  = 0.5;
double motorSpeedFactorRight = 0.5;
int ENA = 11, IN1 = 7, IN2 = 6;
int IN3 = 5,  IN4 = 4,  ENB = 10;
LMotorController motorController(
  ENA, IN1, IN2,
  ENB, IN3, IN4,
  motorSpeedFactorLeft,
  motorSpeedFactorRight
);

// --- State machine ---
enum Mode {
  MODE_BALANCE,
  MODE_FORWARD,
  MODE_BACKWARD,
  MODE_TURN_LEFT,
  MODE_TURN_RIGHT
};
Mode currentMode = MODE_BALANCE;

// Ngưỡng cho phép trong khi di chuyển (độ)
const double BALANCE_THRESHOLD = 20.0;

//───────────────────────────//
// 2. HÀM HỖ TRỢ & SETUP
//───────────────────────────//

// gọi khi MPU phát interrupt
void dmpDataReady() {
  mpuInterrupt = true;
}

// các lệnh thay đổi setpoint / motor factor
void moveForward() {
  setpoint = originalSetpoint - movingAngleOffset;
}
void moveBackward() {
  setpoint = originalSetpoint + movingAngleOffset;
}
void turnLeft() {
  // setpoint = originalSetpoint - movingAngleOffset;
  setpoint = originalSetpoint;
  motorController.setMotorSpeedFactors(0.6, 0.4);
}
void turnRight() {
  // setpoint = originalSetpoint - movingAngleOffset;
  setpoint = originalSetpoint;
  motorController.setMotorSpeedFactors(0.4, 0.6);
}
void stopMoving() {
  setpoint = originalSetpoint;
  motorController.setMotorSpeedFactors(0.5, 0.5);
}

// Thiết lập ban đầu
void setup() {
  Serial.begin(115200);

  #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    Wire.begin();
    TWBR = 24; // I2C 400kHz
  #endif

  mpu.initialize();
  devStatus = mpu.dmpInitialize();

  mpu.setXGyroOffset(0);
  mpu.setYGyroOffset(0);
  mpu.setZGyroOffset(0);
  mpu.setZAccelOffset(0);

  if (devStatus == 0) {
    mpu.setDMPEnabled(true);
    attachInterrupt(0, dmpDataReady, RISING);
    mpuIntStatus = mpu.getIntStatus();
    dmpReady    = true;
    packetSize  = mpu.dmpGetFIFOPacketSize();

    pid.SetMode(AUTOMATIC);
    pid.SetSampleTime(10);
    pid.SetOutputLimits(-255, 255);
  } else {
    Serial.print(F("DMP Initialization failed (code "));
    Serial.print(devStatus);
    Serial.println(F(")"));
  }
}

//───────────────────────────//
// 3. LOOP VỚI STATE MACHINE
//───────────────────────────//

void loop() {
  if (!dmpReady) return;

  // 1) Nếu có byte Serial mới, cập nhật mode
  if (Serial.available()) {
    char cmd = Serial.read();
    switch (cmd) {
      case 'F': currentMode = MODE_FORWARD;     moveForward();   break;
      case 'B': currentMode = MODE_BACKWARD;    moveBackward();  break;
      case 'L': currentMode = MODE_TURN_LEFT;   turnLeft();      break;
      case 'R': currentMode = MODE_TURN_RIGHT;  turnRight();     break;
      case 'S': currentMode = MODE_BALANCE;     stopMoving();    break;
    }
    Serial.print("Mode: ");
    Serial.println(cmd);
  }

  // 2) Chờ interrupt hoặc FIFO đủ packet để đọc
  while (!mpuInterrupt && fifoCount < packetSize) {
    pid.Compute();
    motorController.move(output, MIN_ABS_SPEED);
  }

  // 3) Xử lý data DMP
  mpuInterrupt = false;
  mpuIntStatus = mpu.getIntStatus();
  fifoCount    = mpu.getFIFOCount();

  if ((mpuIntStatus & 0x10) || fifoCount == 1024) {
    mpu.resetFIFO();
    Serial.println(F("FIFO overflow!"));
    return;
  }

  if (mpuIntStatus & 0x02) {
    while (fifoCount < packetSize)
      fifoCount = mpu.getFIFOCount();

    mpu.getFIFOBytes(fifoBuffer, packetSize);
    fifoCount -= packetSize;
    mpu.dmpGetQuaternion(&q,     fifoBuffer);
    mpu.dmpGetGravity(&gravity, &q);
    mpu.dmpGetYawPitchRoll(ypr, &q, &gravity);
    input = ypr[1] * 180.0 / M_PI + 180.0;

    double error = abs(input - originalSetpoint);

    // 4) State machine xử lý
    switch (currentMode) {
      case MODE_FORWARD:
      case MODE_BACKWARD:
      case MODE_TURN_LEFT:
      case MODE_TURN_RIGHT:
        // Nếu vẫn trong ngưỡng an toàn thì tiếp tục PID + move
        if (error < BALANCE_THRESHOLD) {
          pid.Compute();
          motorController.move(output, MIN_ABS_SPEED);
          break;
        }
        // Nếu lệch quá, tự trở về balance
        currentMode = MODE_BALANCE;
        stopMoving();
        Serial.println("Auto-Switch -> BALANCE");
        __attribute__((fallthrough));
      case MODE_BALANCE:
      default:
        pid.Compute();
        motorController.move(output, MIN_ABS_SPEED);
        break;
    }

    Serial.print(F("ANGLE: "));
    Serial.println(input);
  }
}

#pragma once

namespace demoktlt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::Threading;
	using namespace System::Net::Sockets;
	using namespace System::Net;
	using namespace System::IO::Ports;
	using namespace System::IO;
	/// <summary>
	/// Summary for FormGestureControl
	/// </summary>
	public ref class FormGestureControl : public System::Windows::Forms::Form
	{
	public:
		FormGestureControl(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormGestureControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ buttonConnect;
	private: System::Windows::Forms::Label^ labelStatus;

	// Các thành phần mạng
	TcpClient^ videoClient;
	NetworkStream^ videoStream;
	// Thêm thành phần SerialPort
	private:
		SerialPort^ serialPort;
		String^ receivedData;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::ComponentModel::IContainer^ components;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormGestureControl::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->buttonConnect = (gcnew System::Windows::Forms::Button());
			this->labelStatus = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 92);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(539, 565);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Red;
			this->button1->Location = System::Drawing::Point(64, 36);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 29);
			this->button1->TabIndex = 1;
			this->button1->Text = L"START";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &FormGestureControl::button1_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(763, 144);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 2;
			// 
			// buttonConnect
			// 
			this->buttonConnect->BackColor = System::Drawing::Color::Red;
			this->buttonConnect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->buttonConnect->Location = System::Drawing::Point(763, 92);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(121, 46);
			this->buttonConnect->TabIndex = 3;
			this->buttonConnect->Text = L"Connect";
			this->buttonConnect->UseVisualStyleBackColor = false;
			this->buttonConnect->Click += gcnew System::EventHandler(this, &FormGestureControl::buttonConnect_Click);
			// 
			// labelStatus
			// 
			this->labelStatus->AutoSize = true;
			this->labelStatus->Location = System::Drawing::Point(630, 303);
			this->labelStatus->Name = L"labelStatus";
			this->labelStatus->Size = System::Drawing::Size(77, 16);
			this->labelStatus->TabIndex = 4;
			this->labelStatus->Text = L"STATUS.....";
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 33;
			this->timer1->Tick += gcnew System::EventHandler(this, &FormGestureControl::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->label1->Location = System::Drawing::Point(760, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(76, 22);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Angle: 0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->label2->Location = System::Drawing::Point(354, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(269, 29);
			this->label2->TabIndex = 6;
			this->label2->Text = L"GESTURE CONTROL";
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(794, 532);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(158, 140);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 7;
			this->pictureBox2->TabStop = false;
			// 
			// FormGestureControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(946, 669);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->labelStatus);
			this->Controls->Add(this->buttonConnect);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"FormGestureControl";
			this->Text = L"FormGestureControl";
			this->Load += gcnew System::EventHandler(this, &FormGestureControl::FormGestureControl_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		// Chạy script Python
		void RunPythonScript() {
			Process^ process = gcnew Process();
			process->StartInfo->FileName = "python";
			process->StartInfo->Arguments = "\"D:\\newversion\\Finger_Counter.py\""; // Đường dẫn tới file Python
			process->StartInfo->UseShellExecute = false;
			process->StartInfo->CreateNoWindow = true;
			process->Start();
			Threading::Thread::Sleep(5000); // Đợi 2 giây để Python khởi động
		}
		// Kết nối đến luồng video qua TCP
		void ConnectVideoStream() {
			try {
				videoClient = gcnew TcpClient("127.0.0.1", 9999);
				videoStream = videoClient->GetStream();
			}
			catch (Exception^) {
				videoClient = nullptr;
				videoStream = nullptr;
			}
		}
		// Cập nhật hình ảnh từ luồng video
		void UpdateImageLoop() {
			try {
				while (true) {
					Bitmap^ bmp = SafeLoadBitmap("h");
					if (bmp != nullptr) {
						this->BeginInvoke(gcnew Action<Bitmap^>(this, &FormGestureControl::UpdateImage), bmp);
					}
					Threading::Thread::Sleep(1); // Tránh vòng lặp bận rộn
				}
			}
			catch (Exception^) {
				// Bỏ qua lỗi
			}
		}
		// Đọc và tải hình ảnh từ luồng video
			Bitmap ^ SafeLoadBitmap(String ^ path) {
			if (videoStream == nullptr) return nullptr;

			try {
				array<Byte>^ lenBytes = gcnew array<Byte>(4);
				int read = videoStream->Read(lenBytes, 0, 4);
				if (read < 4) return nullptr;
				int len = (lenBytes[0] << 24) | (lenBytes[1] << 16) | (lenBytes[2] << 8) | lenBytes[3];

				array<Byte>^ imgBytes = gcnew array<Byte>(len);
				int offset = 0;
				while (offset < len) {
					int n = videoStream->Read(imgBytes, offset, len - offset);
					if (n == 0) return nullptr;
					offset += n;
				}

				MemoryStream^ ms = gcnew MemoryStream(imgBytes);
				Bitmap^ bmp = gcnew Bitmap(ms);
				ms->Close();
				return bmp;
			}
			catch (Exception^) {
				return nullptr;
			}
		}
			// Cập nhật hình ảnh lên PictureBox
			void UpdateImage(Bitmap^ image) {
				if (pictureBox1 != nullptr) {
					pictureBox1->Image = image;
					pictureBox1->SizeMode = PictureBoxSizeMode::Zoom;
				}
			}
			// Tải danh sách cổng COM
			void LoadCOMPorts() {
				array<String^>^ ports = SerialPort::GetPortNames();
				comboBox1->Items->Clear();
				for each (String ^ port in ports) {
					comboBox1->Items->Add(port);
				}
				if (comboBox1->Items->Count > 0) {
					comboBox1->SelectedIndex = 0; // Chọn cổng đầu tiên mặc định
				}
			}
	private: System::Void FormGestureControl_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadCOMPorts();
		timer1 = gcnew System::Windows::Forms::Timer();
		timer1->Interval = 33; // ~30 FPS
		timer1->Tick += gcnew System::EventHandler(this, &FormGestureControl::timer1_Tick);
		timer1->Start();
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		RunPythonScript();
		ConnectVideoStream();
		if (videoClient == nullptr || videoStream == nullptr) {
			labelStatus->Text = "Failed to connect to video stream";
			return;
		}
		//if (serialPort == nullptr || !serialPort->IsOpen) {
		//	labelStatus->Text = "Please connect to Arduino first";   // Mơr ComBox từ button connect
		//	return;
		//}
		Thread^ t = gcnew Thread(gcnew ThreadStart(this, &FormGestureControl::UpdateImageLoop));
		t->IsBackground = true;
		t->Start();
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (File::Exists("gesture1.txt")) {
				String^ content = File::ReadAllText("gesture1.txt")->Trim();
				int fingerCount;
				if (!Int32::TryParse(content, fingerCount)) {
					labelStatus->Text = "Invalid data in gesture.txt";
					return;
				}
				// Gửi tín hiệu qua Serial dựa trên số ngón tay
				if (serialPort != nullptr && serialPort->IsOpen) {
					switch (fingerCount) {
					case 1:
						serialPort->Write("F"); // Gửi "F" cho Moving forward
						labelStatus->Text = "Moving forward";
						break;
					case 2:
						serialPort->Write("B"); // Gửi "B" cho Moving backward
						labelStatus->Text = "Moving backward";
						break;
					case 3:
						serialPort->Write("L"); // Gửi "L" cho Turning left
						labelStatus->Text = "Turning left";
						break;
					case 4:
						serialPort->Write("R"); // Gửi "R" cho Turning right
						labelStatus->Text = "Turning right";
						break;
					default:
						serialPort->Write("S"); // Gửi "S" cho Stop/Idle
						labelStatus->Text = "Idle";
						break;
					}
				}
				else {
					labelStatus->Text = "Serial port not open";
				}
			}
			else {
				labelStatus->Text = "gesture1.txt not found";
			}
		}

		catch (IOException^ ex) {
			labelStatus->Text = "I/O Error: " + ex->Message;
		}
		catch (Exception^ ex) {
			labelStatus->Text = "Error: " + ex->Message;
		}
	}
	//private: System::Void SerialPort_DataReceived(System::Object^ sender, SerialDataReceivedEventArgs^ e) {
	//	try {
	//		String^ data = serialPort->ReadLine(); // Đọc dòng dữ liệu từ Arduino
	//		if (data->StartsWith("ANGLE:")) {
	//			String^ angleStr = data->Substring(6); // Lấy phần sau "ANGLE:"
	//			double angle;
	//			if (Double::TryParse(angleStr, angle)) {
	//				// Cập nhật label1 trên luồng giao diện
	//				this->BeginInvoke(gcnew Action<double>(this, &FormGestureControl::UpdateAngleLabel), angle);
	//			}
	//		}
	//	}
	//	catch (Exception^ ex) {
	//		// Log the exception message to the label or debug output
	//		Debug::WriteLine("Exception caught: " + ex->Message);
	//		labelStatus->Text = "Error: " + ex->Message; // Update the label with the error message
	//	}

	//}
	//	   // Cập nhật giá trị góc lên label1
	//private: System::Void UpdateAngleLabel(double angle) {
	//	label1->Text = "Angle: " + angle.ToString("F2"); // Hiển thị với 1 chữ số thập phân
	//}

	private: System::Void SerialPort_DataReceived(System::Object^ sender, SerialDataReceivedEventArgs^ e) {
		try {
			String^ data = serialPort->ReadExisting();
			receivedData += data;

			int newLineIndex;
			while ((newLineIndex = receivedData->IndexOf('\n')) != -1) {
				String^ line = receivedData->Substring(0, newLineIndex)->Trim();
				receivedData = receivedData->Substring(newLineIndex + 1);

				if (line->StartsWith("ANGLE:")) {
					String^ angleStr = line->Substring(6);
					double angle;
					if (Double::TryParse(angleStr, angle)) {
						this->BeginInvoke(gcnew Action<double>(this, &FormGestureControl::UpdateAngleLabel), angle);

					}
				}
			}
		}
		catch (Exception^ ex) {
			Console::WriteLine("Exception occurred: " + ex->Message);
		}
	}



	private: System::Void UpdateAngleLabel(double angle) {
		label1->Text = "Angle: " + angle.ToString("F2"); // Hiển thị với 2 chữ số thập phân
	}

		   // Xử lý sự kiện khi nhấn nút Connect
	private: System::Void buttonConnect_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			if (serialPort != nullptr && serialPort->IsOpen) {
				serialPort->Close();
				MessageBox::Show("Serial port disconnected", "Connection Status", MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			if (comboBox1->SelectedItem == nullptr) {
				MessageBox::Show("Please select a COM port", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			String^ selectedPort = comboBox1->SelectedItem->ToString();
			serialPort = gcnew SerialPort(selectedPort,115200); 
			serialPort->DataReceived += gcnew SerialDataReceivedEventHandler(this, &FormGestureControl::SerialPort_DataReceived);
			serialPort->ReadTimeout = 500; // Thời gian timeout đọc
			serialPort->Open();
			MessageBox::Show("Connected to " + selectedPort, "Connection Status", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Connection error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
};
}

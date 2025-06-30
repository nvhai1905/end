#pragma once

namespace demoktlt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;

	/// <summary>
	/// Summary for FormButtonControl
	/// </summary>
	public ref class FormButtonControl : public System::Windows::Forms::Form
	{
	public:
		FormButtonControl(void)
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
		~FormButtonControl()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ buttonF;
	protected:
	private: System::Windows::Forms::Button^ buttonL;
	private: System::Windows::Forms::Button^ buttonB;
	private: System::Windows::Forms::Button^ buttonR;
	private: System::Windows::Forms::Button^ buttonS;
	private: System::Windows::Forms::Label^ labelStatus;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Button^ buttonConnect;
	private: System::Windows::Forms::Label^ label1;

	private:
		SerialPort^ serialPort;
		String^ receivedData;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;



	protected:






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormButtonControl::typeid));
			this->buttonF = (gcnew System::Windows::Forms::Button());
			this->buttonL = (gcnew System::Windows::Forms::Button());
			this->buttonB = (gcnew System::Windows::Forms::Button());
			this->buttonR = (gcnew System::Windows::Forms::Button());
			this->buttonS = (gcnew System::Windows::Forms::Button());
			this->labelStatus = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->buttonConnect = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// buttonF
			// 
			this->buttonF->BackColor = System::Drawing::Color::IndianRed;
			this->buttonF->Location = System::Drawing::Point(372, 104);
			this->buttonF->Name = L"buttonF";
			this->buttonF->Size = System::Drawing::Size(143, 53);
			this->buttonF->TabIndex = 1;
			this->buttonF->Text = L"Foward";
			this->buttonF->UseVisualStyleBackColor = false;
			this->buttonF->Click += gcnew System::EventHandler(this, &FormButtonControl::buttonF_Click);
			// 
			// buttonL
			// 
			this->buttonL->BackColor = System::Drawing::SystemColors::Highlight;
			this->buttonL->Location = System::Drawing::Point(143, 215);
			this->buttonL->Name = L"buttonL";
			this->buttonL->Size = System::Drawing::Size(131, 62);
			this->buttonL->TabIndex = 2;
			this->buttonL->Text = L"Left";
			this->buttonL->UseVisualStyleBackColor = false;
			this->buttonL->Click += gcnew System::EventHandler(this, &FormButtonControl::buttonL_Click);
			// 
			// buttonB
			// 
			this->buttonB->BackColor = System::Drawing::Color::Chocolate;
			this->buttonB->Location = System::Drawing::Point(372, 351);
			this->buttonB->Name = L"buttonB";
			this->buttonB->Size = System::Drawing::Size(140, 58);
			this->buttonB->TabIndex = 3;
			this->buttonB->Text = L"Backward";
			this->buttonB->UseVisualStyleBackColor = false;
			this->buttonB->Click += gcnew System::EventHandler(this, &FormButtonControl::buttonB_Click);
			// 
			// buttonR
			// 
			this->buttonR->BackColor = System::Drawing::Color::RosyBrown;
			this->buttonR->Location = System::Drawing::Point(620, 219);
			this->buttonR->Name = L"buttonR";
			this->buttonR->Size = System::Drawing::Size(129, 58);
			this->buttonR->TabIndex = 4;
			this->buttonR->Text = L"Right";
			this->buttonR->UseVisualStyleBackColor = false;
			this->buttonR->Click += gcnew System::EventHandler(this, &FormButtonControl::buttonR_Click);
			// 
			// buttonS
			// 
			this->buttonS->BackColor = System::Drawing::Color::Red;
			this->buttonS->Location = System::Drawing::Point(134, 373);
			this->buttonS->Name = L"buttonS";
			this->buttonS->Size = System::Drawing::Size(114, 56);
			this->buttonS->TabIndex = 5;
			this->buttonS->Text = L"STOP";
			this->buttonS->UseVisualStyleBackColor = false;
			this->buttonS->Click += gcnew System::EventHandler(this, &FormButtonControl::buttonS_Click);
			// 
			// labelStatus
			// 
			this->labelStatus->AutoSize = true;
			this->labelStatus->Location = System::Drawing::Point(394, 238);
			this->labelStatus->Name = L"labelStatus";
			this->labelStatus->Size = System::Drawing::Size(74, 16);
			this->labelStatus->TabIndex = 6;
			this->labelStatus->Text = L"STATUS....";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(701, 118);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 24);
			this->comboBox1->TabIndex = 7;
			// 
			// buttonConnect
			// 
			this->buttonConnect->BackColor = System::Drawing::Color::Red;
			this->buttonConnect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->buttonConnect->Location = System::Drawing::Point(701, 73);
			this->buttonConnect->Name = L"buttonConnect";
			this->buttonConnect->Size = System::Drawing::Size(121, 39);
			this->buttonConnect->TabIndex = 8;
			this->buttonConnect->Text = L"Connect";
			this->buttonConnect->UseVisualStyleBackColor = false;
			this->buttonConnect->Click += gcnew System::EventHandler(this, &FormButtonControl::buttonConnect_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->label1->Location = System::Drawing::Point(140, 48);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(70, 20);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Angle: 0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(163)));
			this->label2->Location = System::Drawing::Point(337, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(212, 25);
			this->label2->TabIndex = 10;
			this->label2->Text = L"BUTTON CONTROL";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(778, 457);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(133, 140);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 11;
			this->pictureBox1->TabStop = false;
			// 
			// FormButtonControl
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(906, 597);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonConnect);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->labelStatus);
			this->Controls->Add(this->buttonS);
			this->Controls->Add(this->buttonR);
			this->Controls->Add(this->buttonB);
			this->Controls->Add(this->buttonL);
			this->Controls->Add(this->buttonF);
			this->Name = L"FormButtonControl";
			this->Text = L"FormButtonControl";
			this->Load += gcnew System::EventHandler(this, &FormButtonControl::FormButtonControl_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		void LoadCOMPorts()
		{
			array<String^>^ ports = SerialPort::GetPortNames();
			comboBox1->Items->Clear();
			for each (String ^ port in ports)
			{
				comboBox1->Items->Add(port);
				Console::WriteLine("Found port: " + port);
			}
			if (comboBox1->Items->Count > 0)
				comboBox1->SelectedIndex = 0;
		}
	// Xu ly goc
	//private: System::Void SerialPort_DataReceived(System::Object^ sender, SerialDataReceivedEventArgs^ e) {
	//	try {
	//		String^ data = serialPort->ReadLine(); // Đọc dòng dữ liệu từ Arduino
	//		if (data->StartsWith("ANGLE:")) {
	//			String^ angleStr = data->Substring(6); // Lấy phần sau "ANGLE:"
	//			double angle;
	//			if (Double::TryParse(angleStr, angle)) {
	//				// Cập nhật label1 trên luồng giao diện
	//				this->BeginInvoke(gcnew Action<double>(this, &FormButtonControl::UpdateAngleLabel), angle);
	//			}
	//		}
	//	}
	//	catch (Exception^ ex) {
	//		// Log the exception message to the console or update the status label
	//		Console::WriteLine("Exception occurred: " + ex->Message);
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
						this->BeginInvoke(gcnew Action<double>(this, &FormButtonControl::UpdateAngleLabel), angle);
					}
				}
			}
		}
		catch (Exception^ ex) {
			Console::WriteLine("Exception occurred: " + ex->Message);
		}
	}
	private: System::Void UpdateAngleLabel(double angle) {
			label1->Text = "Angle: " + angle.ToString("F2"); // Hiển thị với 1 chữ số thập phân

	}

// Xu ly nut an
	private: System::Void buttonF_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort != nullptr && serialPort->IsOpen) {
			serialPort->WriteLine("F"); // Gửi lệnh tiến
			labelStatus->Text = "Moving Forward";
		}
		else {
			labelStatus->Text = "Serial port not open";
		}

	}
		   // Xu ly lenh dieu khien
	private: System::Void buttonL_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort != nullptr && serialPort->IsOpen) {
			serialPort->WriteLine("L"); // Gửi lệnh trái
			labelStatus->Text = "Turning Left";
		}
		else {
			labelStatus->Text = "Serial port not open";
		}
	}

	private: System::Void buttonB_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort != nullptr && serialPort->IsOpen) {
			serialPort->WriteLine("B"); // Gửi lệnh lùi
			labelStatus->Text = "Moving Backward";
		}
		else {
			labelStatus->Text = "Serial port not open";
		}
	}

	private: System::Void buttonR_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort != nullptr && serialPort->IsOpen) {
			serialPort->WriteLine("R"); // Gửi lệnh phải
			labelStatus->Text = "Turning Right";
		}
		else {
			labelStatus->Text = "Serial port not open";
		}
	}

	private: System::Void buttonS_Click(System::Object^ sender, System::EventArgs^ e) {
		if (serialPort != nullptr && serialPort->IsOpen) {
			serialPort->WriteLine("S"); // Gửi lệnh dừng
			labelStatus->Text = "Stopped";
		}
		else {
			labelStatus->Text = "Serial port not open";
		}
	}
		   // ket noi voi combox
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
			serialPort = gcnew SerialPort(selectedPort, 115200);
			serialPort->DataReceived += gcnew SerialDataReceivedEventHandler(this, &FormButtonControl::SerialPort_DataReceived);
			serialPort->ReadTimeout = 500; // Thời gian timeout đọc
			serialPort->Open();
			MessageBox::Show("Connected to " + selectedPort, "Connection Status", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Connection error: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}
	private: System::Void FormButtonControl_Load(System::Object^ sender, System::EventArgs^ e) {
		LoadCOMPorts();
	}
};
}

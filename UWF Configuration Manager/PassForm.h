#pragma once


unsigned int hash(const char* s, unsigned int seed = 0);
int getKey();


namespace UWFConfigurationManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for PassForm
	/// </summary>
	public ref class PassForm : public System::Windows::Forms::Form
	{
	public:
		PassForm(void)
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
		~PassForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  okBtn;

	protected:

	protected:
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TextBox^  passInput;

	private:
		int attempts = 0;
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PassForm::typeid));
			this->okBtn = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->passInput = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// okBtn
			// 
			this->okBtn->Location = System::Drawing::Point(116, 76);
			this->okBtn->Name = L"okBtn";
			this->okBtn->Size = System::Drawing::Size(75, 23);
			this->okBtn->TabIndex = 1;
			this->okBtn->Text = L"OK";
			this->okBtn->UseVisualStyleBackColor = true;
			this->okBtn->Click += gcnew System::EventHandler(this, &PassForm::okBtn_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(197, 76);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &PassForm::button2_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->passInput);
			this->groupBox1->Location = System::Drawing::Point(13, 13);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(259, 57);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Password:";
			// 
			// passInput
			// 
			this->passInput->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->passInput->Location = System::Drawing::Point(7, 20);
			this->passInput->MaxLength = 14;
			this->passInput->Name = L"passInput";
			this->passInput->Size = System::Drawing::Size(246, 20);
			this->passInput->TabIndex = 0;
			this->passInput->UseSystemPasswordChar = true;
			// 
			// PassForm
			// 
			this->AcceptButton = this->okBtn;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->ClientSize = System::Drawing::Size(284, 111);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->okBtn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"PassForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"UWF Manager";
			this->Load += gcnew System::EventHandler(this, &PassForm::Form_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}

#pragma endregion

private: System::Void okBtn_Click(System::Object^  sender, System::EventArgs^  e) {
			 
			attempts++;

			const char* str = (const char*)(void*) Marshal::StringToHGlobalAnsi(this->passInput->Text);

			if (getKey() == hash(str))
 			{
 				this->DialogResult = System::Windows::Forms::DialogResult::OK;
			}
			else if (attempts < 3)
			{
				this->passInput->Text = L"";
			}
			else
			{
				MessageBox::Show("You have exceeded the maximum number of attempts!", "UWF Manager", MessageBoxButtons::OK, MessageBoxIcon::Error);
				Close();
			}
}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
			 Close();
}
private: System::Void Form_Load(System::Object^  sender, System::EventArgs^  e) {
			 this->passInput->Select();
}
};
}

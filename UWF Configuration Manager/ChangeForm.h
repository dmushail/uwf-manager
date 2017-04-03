#pragma once


int changeKey(int nPass);


namespace UWFConfigurationManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ChangeForm
	/// </summary>
	public ref class ChangeForm : public System::Windows::Forms::Form
	{
	public:
		ChangeForm(void)
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
		~ChangeForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  okBtn;
	private: System::Windows::Forms::Button^  cancelBtn;

	protected:

	private: System::Windows::Forms::GroupBox^  currentPassBox;
	private: System::Windows::Forms::TextBox^  currentPass;
	private: System::Windows::Forms::GroupBox^  newPassBox;
	private: System::Windows::Forms::TextBox^  newPass2;
	private: System::Windows::Forms::Label^  confirmLabel;
	private: System::Windows::Forms::TextBox^  newPass1;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ChangeForm::typeid));
			this->okBtn = (gcnew System::Windows::Forms::Button());
			this->cancelBtn = (gcnew System::Windows::Forms::Button());
			this->currentPassBox = (gcnew System::Windows::Forms::GroupBox());
			this->currentPass = (gcnew System::Windows::Forms::TextBox());
			this->newPassBox = (gcnew System::Windows::Forms::GroupBox());
			this->newPass2 = (gcnew System::Windows::Forms::TextBox());
			this->confirmLabel = (gcnew System::Windows::Forms::Label());
			this->newPass1 = (gcnew System::Windows::Forms::TextBox());
			this->currentPassBox->SuspendLayout();
			this->newPassBox->SuspendLayout();
			this->SuspendLayout();
			// 
			// okBtn
			// 
			this->okBtn->Location = System::Drawing::Point(66, 182);
			this->okBtn->Name = L"okBtn";
			this->okBtn->Size = System::Drawing::Size(75, 23);
			this->okBtn->TabIndex = 0;
			this->okBtn->Text = L"OK";
			this->okBtn->UseVisualStyleBackColor = true;
			this->okBtn->Click += gcnew System::EventHandler(this, &ChangeForm::okBtn_Click);
			// 
			// cancelBtn
			// 
			this->cancelBtn->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelBtn->Location = System::Drawing::Point(147, 182);
			this->cancelBtn->Name = L"cancelBtn";
			this->cancelBtn->Size = System::Drawing::Size(75, 23);
			this->cancelBtn->TabIndex = 1;
			this->cancelBtn->Text = L"Cancel";
			this->cancelBtn->UseVisualStyleBackColor = true;
			this->cancelBtn->Click += gcnew System::EventHandler(this, &ChangeForm::cancelBtn_Click);
			// 
			// currentPassBox
			// 
			this->currentPassBox->Controls->Add(this->currentPass);
			this->currentPassBox->Location = System::Drawing::Point(13, 13);
			this->currentPassBox->Name = L"currentPassBox";
			this->currentPassBox->Size = System::Drawing::Size(209, 56);
			this->currentPassBox->TabIndex = 2;
			this->currentPassBox->TabStop = false;
			this->currentPassBox->Text = L"Current Password:";
			// 
			// currentPass
			// 
			this->currentPass->Location = System::Drawing::Point(7, 20);
			this->currentPass->Name = L"currentPass";
			this->currentPass->Size = System::Drawing::Size(196, 20);
			this->currentPass->TabIndex = 0;
			this->currentPass->UseSystemPasswordChar = true;
			// 
			// newPassBox
			// 
			this->newPassBox->Controls->Add(this->newPass2);
			this->newPassBox->Controls->Add(this->confirmLabel);
			this->newPassBox->Controls->Add(this->newPass1);
			this->newPassBox->Location = System::Drawing::Point(13, 76);
			this->newPassBox->Name = L"newPassBox";
			this->newPassBox->Size = System::Drawing::Size(209, 100);
			this->newPassBox->TabIndex = 3;
			this->newPassBox->TabStop = false;
			this->newPassBox->Text = L"New Password:";
			// 
			// newPass2
			// 
			this->newPass2->Location = System::Drawing::Point(7, 64);
			this->newPass2->Name = L"newPass2";
			this->newPass2->Size = System::Drawing::Size(196, 20);
			this->newPass2->TabIndex = 2;
			this->newPass2->UseSystemPasswordChar = true;
			// 
			// confirmLabel
			// 
			this->confirmLabel->AutoSize = true;
			this->confirmLabel->Location = System::Drawing::Point(7, 47);
			this->confirmLabel->Name = L"confirmLabel";
			this->confirmLabel->Size = System::Drawing::Size(45, 13);
			this->confirmLabel->TabIndex = 1;
			this->confirmLabel->Text = L"Confirm:";
			// 
			// newPass1
			// 
			this->newPass1->Location = System::Drawing::Point(7, 20);
			this->newPass1->Name = L"newPass1";
			this->newPass1->Size = System::Drawing::Size(196, 20);
			this->newPass1->TabIndex = 0;
			this->newPass1->UseSystemPasswordChar = true;
			// 
			// ChangeForm
			// 
			this->AcceptButton = this->okBtn;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLight;
			this->CancelButton = this->cancelBtn;
			this->ClientSize = System::Drawing::Size(234, 214);
			this->Controls->Add(this->newPassBox);
			this->Controls->Add(this->currentPassBox);
			this->Controls->Add(this->cancelBtn);
			this->Controls->Add(this->okBtn);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"ChangeForm";
			this->ShowInTaskbar = false;
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"UWF Manager - Change Password";
			this->Load += gcnew System::EventHandler(this, &ChangeForm::changeForm_Load);
			this->currentPassBox->ResumeLayout(false);
			this->currentPassBox->PerformLayout();
			this->newPassBox->ResumeLayout(false);
			this->newPassBox->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void cancelBtn_Click(System::Object^  sender, System::EventArgs^  e) {
				 Close();
	}

private: System::Void okBtn_Click(System::Object^  sender, System::EventArgs^  e) {

			 const char* currentPass = (const char*)(void*)Marshal::StringToHGlobalAnsi(this->currentPass->Text);
			 const char* newPass = (const char*)(void*)Marshal::StringToHGlobalAnsi(this->newPass1->Text);

			 if (getKey() == hash(currentPass))
			 {
				 if (this->newPass1->Text == this->newPass2->Text)
				 {
					 if (changeKey(hash(newPass)) == 0)
					 {
						 this->DialogResult = System::Windows::Forms::DialogResult::OK;
					 }
				 }
				 else
				 {
					 MessageBox::Show("New passwords do not match!", "UWF Manager", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				 }
			 }
			 else
			 {
				 MessageBox::Show("Current password is invalid!", "UWF Manager", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			 }
}
private: System::Void changeForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 this->currentPass->Select();
}
};
}

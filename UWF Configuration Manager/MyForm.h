#pragma once


#include "PassForm.h"
#include "ChangeForm.h"


void getUWF(int& c, int& n);
int setUWF(int set);


namespace UWFConfigurationManager {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// Summary for MyForm
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::RadioButton^  enableUWF;
	private: System::Windows::Forms::RadioButton^  disableUWF;
	private: System::Windows::Forms::Button^  applyButton;
	private: System::Windows::Forms::Button^  cancelButton;
	private: System::Windows::Forms::TextBox^  currentBox;
	private: System::Windows::Forms::TextBox^  nextBox;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::MenuStrip^  menuStrip;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  changePasswordToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;


	protected:

	private: System::ComponentModel::IContainer^  components;
	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->enableUWF = (gcnew System::Windows::Forms::RadioButton());
			this->disableUWF = (gcnew System::Windows::Forms::RadioButton());
			this->applyButton = (gcnew System::Windows::Forms::Button());
			this->cancelButton = (gcnew System::Windows::Forms::Button());
			this->currentBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->nextBox = (gcnew System::Windows::Forms::TextBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->menuStrip = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changePasswordToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->menuStrip->SuspendLayout();
			this->SuspendLayout();
			// 
			// enableUWF
			// 
			this->enableUWF->AutoSize = true;
			this->enableUWF->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->enableUWF->Location = System::Drawing::Point(6, 19);
			this->enableUWF->Name = L"enableUWF";
			this->enableUWF->Size = System::Drawing::Size(194, 20);
			this->enableUWF->TabIndex = 0;
			this->enableUWF->TabStop = true;
			this->enableUWF->Text = L"Enable Unified Write Filter";
			this->enableUWF->UseVisualStyleBackColor = true;
			this->enableUWF->CheckedChanged += gcnew System::EventHandler(this, &MyForm::radioButton1_CheckedChanged);
			// 
			// disableUWF
			// 
			this->disableUWF->AutoSize = true;
			this->disableUWF->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->disableUWF->Location = System::Drawing::Point(6, 45);
			this->disableUWF->Name = L"disableUWF";
			this->disableUWF->Size = System::Drawing::Size(197, 20);
			this->disableUWF->TabIndex = 1;
			this->disableUWF->TabStop = true;
			this->disableUWF->Text = L"Disable Unified Write Filter";
			this->disableUWF->UseVisualStyleBackColor = true;
			// 
			// applyButton
			// 
			this->applyButton->AutoSize = true;
			this->applyButton->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->applyButton->Location = System::Drawing::Point(121, 251);
			this->applyButton->Name = L"applyButton";
			this->applyButton->Size = System::Drawing::Size(80, 28);
			this->applyButton->TabIndex = 8;
			this->applyButton->Text = L"Apply";
			this->applyButton->UseVisualStyleBackColor = true;
			this->applyButton->Click += gcnew System::EventHandler(this, &MyForm::applyButton_Click);
			// 
			// cancelButton
			// 
			this->cancelButton->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->cancelButton->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancelButton->Location = System::Drawing::Point(207, 251);
			this->cancelButton->Name = L"cancelButton";
			this->cancelButton->Size = System::Drawing::Size(80, 28);
			this->cancelButton->TabIndex = 10;
			this->cancelButton->Text = L"Cancel";
			this->cancelButton->UseVisualStyleBackColor = true;
			this->cancelButton->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// currentBox
			// 
			this->currentBox->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->currentBox->Location = System::Drawing::Point(6, 19);
			this->currentBox->Multiline = true;
			this->currentBox->Name = L"currentBox";
			this->currentBox->ReadOnly = true;
			this->currentBox->Size = System::Drawing::Size(257, 24);
			this->currentBox->TabIndex = 14;
			this->currentBox->TextChanged += gcnew System::EventHandler(this, &MyForm::currentBox_TextChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->nextBox);
			this->groupBox1->Controls->Add(this->currentBox);
			this->groupBox1->Location = System::Drawing::Point(12, 27);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(275, 90);
			this->groupBox1->TabIndex = 16;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Write Filter Status";
			this->groupBox1->Enter += gcnew System::EventHandler(this, &MyForm::groupBox1_Enter);
			// 
			// nextBox
			// 
			this->nextBox->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nextBox->Location = System::Drawing::Point(6, 49);
			this->nextBox->Multiline = true;
			this->nextBox->Name = L"nextBox";
			this->nextBox->ReadOnly = true;
			this->nextBox->Size = System::Drawing::Size(257, 24);
			this->nextBox->TabIndex = 15;
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->textBox1);
			this->groupBox2->Controls->Add(this->enableUWF);
			this->groupBox2->Controls->Add(this->disableUWF);
			this->groupBox2->Location = System::Drawing::Point(12, 123);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(275, 122);
			this->groupBox2->TabIndex = 17;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Write Filter Setting";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Cursor = System::Windows::Forms::Cursors::Arrow;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(6, 70);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(263, 46);
			this->textBox1->TabIndex = 2;
			this->textBox1->Text = L"WARNING: Operating a flash storage device without the use of a write filter can l"
				L"ead to premature wear of the storage device due to excessive writes.";
			// 
			// menuStrip
			// 
			this->menuStrip->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->menuStrip->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->fileToolStripMenuItem });
			this->menuStrip->Location = System::Drawing::Point(0, 0);
			this->menuStrip->Name = L"menuStrip";
			this->menuStrip->Size = System::Drawing::Size(299, 24);
			this->menuStrip->TabIndex = 18;
			this->menuStrip->Text = L"menuStrip";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->changePasswordToolStripMenuItem,
					this->exitToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// changePasswordToolStripMenuItem
			// 
			this->changePasswordToolStripMenuItem->Name = L"changePasswordToolStripMenuItem";
			this->changePasswordToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->changePasswordToolStripMenuItem->Text = L"Change Password";
			this->changePasswordToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::changePasswordToolStripMenuItem_Click);
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->Size = System::Drawing::Size(168, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AcceptButton = this->applyButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->CancelButton = this->cancelButton;
			this->ClientSize = System::Drawing::Size(299, 291);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->cancelButton);
			this->Controls->Add(this->applyButton);
			this->Controls->Add(this->menuStrip);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm";
			this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"UWF Manager";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->menuStrip->ResumeLayout(false);
			this->menuStrip->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

				 PassForm ^ pForm = gcnew PassForm;

				 if (pForm->ShowDialog() != System::Windows::Forms::DialogResult::OK)
				 {
					 Close();
				 }

				 int c, n;
				 getUWF(c, n);

				 if (c == 0)
				 {
					 this->currentBox->Text = "Current Session: Disabled";
					 this->disableUWF->Checked = true;
				 }
				 else if (c == 1)
				 {
					 this->currentBox->Text = "Current Session: Enabled";
					 this->enableUWF->Checked = true;
				 }
				 if (n == 0)
				 {
					 this->nextBox->Text = "Next Session: Disabled";
				 }
				 else if (n == 1)
				 {
					 this->nextBox->Text = "Next Session: Enabled";
				 }
	}

	private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void toolTip1_Popup(System::Object^  sender, System::Windows::Forms::PopupEventArgs^  e) {
	}

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
				 Close();
	}

	private: System::Void currentBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void applyButton_Click(System::Object^  sender, System::EventArgs^  e) {

				 int c, n;
				 getUWF(c, n);

				 if (this->enableUWF->Checked == true && n == 0)
				 {
					 if (setUWF(1) == 0)
					 {
						 this->nextBox->Text = "Next Session: Enabled";
					 }
				 }
				 else if (this->disableUWF->Checked == true && n == 1)
				 {
					 if (setUWF(0) == 0)
					 {
						 this->nextBox->Text = "Next Session: Disabled";
					 }
				 }

	}

private: System::Void groupBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void changePasswordToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {

			 ChangeForm ^ changeForm = gcnew ChangeForm;

			 if (changeForm->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			 {
				 getKey();
			 }

}

};
}

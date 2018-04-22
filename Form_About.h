#pragma once

namespace DLL_Injector {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form_About
	/// </summary>
	public ref class Form_About : public System::Windows::Forms::Form
	{
	public:
		Form_About(void)
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
		~Form_About()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  aboutLBL;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  buttonExit;
	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form_About::typeid));
			this->aboutLBL = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// aboutLBL
			// 
			this->aboutLBL->AutoSize = true;
			this->aboutLBL->BackColor = System::Drawing::Color::Transparent;
			this->aboutLBL->Font = (gcnew System::Drawing::Font(L"David", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->aboutLBL->ForeColor = System::Drawing::Color::Blue;
			this->aboutLBL->Location = System::Drawing::Point(29, 36);
			this->aboutLBL->Name = L"aboutLBL";
			this->aboutLBL->Size = System::Drawing::Size(510, 27);
			this->aboutLBL->TabIndex = 0;
			this->aboutLBL->Text = L"This DLL Injector Created By Gil Mansharov";
			this->aboutLBL->Click += gcnew System::EventHandler(this, &Form_About::aboutLBL_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"David", 17.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->label1->ForeColor = System::Drawing::Color::Blue;
			this->label1->Location = System::Drawing::Point(30, 136);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(529, 24);
			this->label1->TabIndex = 1;
			this->label1->Text = L"For More Cool Applications, Visit My Github Profile:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"David", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->label2->ForeColor = System::Drawing::Color::Blue;
			this->label2->Location = System::Drawing::Point(101, 209);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(332, 24);
			this->label2->TabIndex = 2;
			this->label2->Text = L"https://github.com/gilmansharov";
			// 
			// buttonExit
			// 
			this->buttonExit->BackColor = System::Drawing::Color::Transparent;
			this->buttonExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->buttonExit->ForeColor = System::Drawing::Color::Black;
			this->buttonExit->Location = System::Drawing::Point(182, 285);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(174, 36);
			this->buttonExit->TabIndex = 3;
			this->buttonExit->Text = L"Cool Story Man";
			this->buttonExit->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->buttonExit->UseVisualStyleBackColor = false;
			this->buttonExit->Click += gcnew System::EventHandler(this, &Form_About::buttonExit_Click);
			// 
			// Form_About
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Azure;
			this->ClientSize = System::Drawing::Size(571, 365);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->aboutLBL);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form_About";
			this->Text = L"About";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void aboutLBL_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void buttonExit_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
	}
};
}

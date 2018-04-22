#pragma once

namespace DLL_Injector {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form_Instructions
	/// </summary>
	public ref class Form_Instructions : public System::Windows::Forms::Form
	{
	public:
		Form_Instructions(void)
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
		~Form_Instructions()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  WelcomeLBL;
	private: System::Windows::Forms::Label^  instructionOne;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form_Instructions::typeid));
			this->WelcomeLBL = (gcnew System::Windows::Forms::Label());
			this->instructionOne = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->buttonExit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// WelcomeLBL
			// 
			this->WelcomeLBL->AutoSize = true;
			this->WelcomeLBL->Font = (gcnew System::Drawing::Font(L"Book Antiqua", 17, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->WelcomeLBL->Location = System::Drawing::Point(212, 18);
			this->WelcomeLBL->Name = L"WelcomeLBL";
			this->WelcomeLBL->Size = System::Drawing::Size(139, 28);
			this->WelcomeLBL->TabIndex = 0;
			this->WelcomeLBL->Text = L"Instructions";
			// 
			// instructionOne
			// 
			this->instructionOne->AutoSize = true;
			this->instructionOne->Font = (gcnew System::Drawing::Font(L"Book Antiqua", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->instructionOne->Location = System::Drawing::Point(12, 115);
			this->instructionOne->Name = L"instructionOne";
			this->instructionOne->Size = System::Drawing::Size(553, 23);
			this->instructionOne->TabIndex = 1;
			this->instructionOne->Text = L"2. Refresh The Process List By Clilcking The \"Refresh\" Button";
			this->instructionOne->Click += gcnew System::EventHandler(this, &Form_Instructions::label1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Book Antiqua", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 73);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(535, 23);
			this->label1->TabIndex = 2;
			this->label1->Text = L"1. Choose Your DLL By Clicking The \"Choose DLL\" Button";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Book Antiqua", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 158);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(515, 23);
			this->label2->TabIndex = 3;
			this->label2->Text = L"3. Choose The Process You Want To Inject Your DLL Into";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Book Antiqua", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(12, 203);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(196, 23);
			this->label3->TabIndex = 4;
			this->label3->Text = L"4. Success\? Have Fun";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Book Antiqua", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(12, 246);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(559, 23);
			this->label4->TabIndex = 5;
			this->label4->Text = L"5. Failed\? Maybe You Don\'t Have Permissions To This Process";
			// 
			// buttonExit
			// 
			this->buttonExit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(177)));
			this->buttonExit->Location = System::Drawing::Point(233, 308);
			this->buttonExit->Name = L"buttonExit";
			this->buttonExit->Size = System::Drawing::Size(91, 32);
			this->buttonExit->TabIndex = 6;
			this->buttonExit->Text = L"Got It";
			this->buttonExit->UseVisualStyleBackColor = true;
			this->buttonExit->Click += gcnew System::EventHandler(this, &Form_Instructions::buttonExit_Click);
			// 
			// Form_Instructions
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(578, 366);
			this->Controls->Add(this->buttonExit);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->instructionOne);
			this->Controls->Add(this->WelcomeLBL);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form_Instructions";
			this->Text = L"Instructions";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void buttonExit_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Close();
	}
};
}

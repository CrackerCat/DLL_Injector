#pragma once
#include "CustomProcess.h"
#include "Form_Instructions.h"
#include "Form_About.h"


namespace DLL_Injector {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
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

	protected:

	private: System::Windows::Forms::Button^  buttonInject;
	private: System::Windows::Forms::ListView^  listView1;
	private: System::Windows::Forms::Button^  buttonOpenDLL;
	private: System::Windows::Forms::OpenFileDialog^  openDLL;
	private: System::String^ DLL_PATH;
	private: System::Windows::Forms::TextBox^  dll_path_box;
	private: System::Windows::Forms::Button^  buttonRefresh;
	private: System::Windows::Forms::ListView^  listProgress;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  helpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  instructionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aboutToolStripMenuItem;
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			
			this->buttonInject = (gcnew System::Windows::Forms::Button());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->buttonOpenDLL = (gcnew System::Windows::Forms::Button());
			this->openDLL = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dll_path_box = (gcnew System::Windows::Forms::TextBox());
			this->buttonRefresh = (gcnew System::Windows::Forms::Button());
			this->listProgress = (gcnew System::Windows::Forms::ListView());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->helpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->instructionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonInject
			// 
			this->buttonInject->AutoSize = true;
			this->buttonInject->BackColor = System::Drawing::Color::Transparent;
			this->buttonInject->Enabled = false;
			this->buttonInject->Location = System::Drawing::Point(272, 36);
			this->buttonInject->Name = L"buttonInject";
			this->buttonInject->Size = System::Drawing::Size(75, 23);
			this->buttonInject->TabIndex = 1;
			this->buttonInject->Text = L"Inject";
			this->buttonInject->UseVisualStyleBackColor = false;
			this->buttonInject->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// listView1
			// 
			this->listView1->Location = System::Drawing::Point(38, 103);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(239, 381);
			this->listView1->TabIndex = 2;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::listView1_SelectedIndexChanged);
			// 
			// buttonOpenDLL
			// 
			this->buttonOpenDLL->BackColor = System::Drawing::Color::Transparent;
			this->buttonOpenDLL->Location = System::Drawing::Point(410, 36);
			this->buttonOpenDLL->Name = L"buttonOpenDLL";
			this->buttonOpenDLL->Size = System::Drawing::Size(111, 23);
			this->buttonOpenDLL->TabIndex = 3;
			this->buttonOpenDLL->Text = L"Choose DLL";
			this->buttonOpenDLL->UseVisualStyleBackColor = false;
			this->buttonOpenDLL->Click += gcnew System::EventHandler(this, &MyForm::buttonOpenDLL_Click);
			// 
			// openDLL
			// 
			this->openDLL->FileName = L"";
			this->openDLL->Filter = L"DLL File|*.dll";
			this->openDLL->Title = L"Choose Your DLL";
			// 
			// dll_path_box
			// 
			this->dll_path_box->Location = System::Drawing::Point(38, 77);
			this->dll_path_box->Name = L"dll_path_box";
			this->dll_path_box->ReadOnly = true;
			this->dll_path_box->Size = System::Drawing::Size(542, 22);
			this->dll_path_box->TabIndex = 4;
			// 
			// buttonRefresh
			// 
			this->buttonRefresh->BackColor = System::Drawing::Color::Transparent;
			this->buttonRefresh->Location = System::Drawing::Point(113, 36);
			this->buttonRefresh->Name = L"buttonRefresh";
			this->buttonRefresh->Size = System::Drawing::Size(75, 23);
			this->buttonRefresh->TabIndex = 5;
			this->buttonRefresh->Text = L"Refresh";
			this->buttonRefresh->UseVisualStyleBackColor = false;
			this->buttonRefresh->Click += gcnew System::EventHandler(this, &MyForm::buttonRefresh_Click);
			// 
			// listProgress
			// 
			this->listProgress->Location = System::Drawing::Point(339, 103);
			this->listProgress->Name = L"listProgress";
			this->listProgress->Size = System::Drawing::Size(241, 381);
			this->listProgress->TabIndex = 6;
			this->listProgress->UseCompatibleStateImageBehavior = false;
			this->listProgress->Columns->Add("Logs");
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->helpToolStripMenuItem });
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(616, 24);
			this->menuStrip1->TabIndex = 7;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// helpToolStripMenuItem
			// 
			this->helpToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->instructionsToolStripMenuItem,
					this->aboutToolStripMenuItem
			});
			this->helpToolStripMenuItem->Name = L"helpToolStripMenuItem";
			this->helpToolStripMenuItem->Size = System::Drawing::Size(43, 20);
			this->helpToolStripMenuItem->Text = L"Help";
			// 
			// instructionsToolStripMenuItem
			// 
			this->instructionsToolStripMenuItem->Name = L"instructionsToolStripMenuItem";
			this->instructionsToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->instructionsToolStripMenuItem->Text = L"Instructions";
			this->instructionsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::instructionsToolStripMenuItem_Click);
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aboutToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(616, 511);
			this->MaximumSize = System::Drawing::Size(616, 540);
			this->Controls->Add(this->listProgress);
			this->Controls->Add(this->buttonRefresh);
			this->Controls->Add(this->dll_path_box);
			this->Controls->Add(this->buttonOpenDLL);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->buttonInject);
			this->Controls->Add(this->menuStrip1);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"DLL Injector";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	System::String^ current;
	array<CustomProcess^>^ process_list;

	
	//Inject
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->listProgress->View = View::Details;
		this->listProgress->Columns[0]->Width = this->listView1->Width - 4;
		int count = 0;
		buttonRefresh_Click(nullptr, nullptr);
		for (int i = 0; ((i < process_list->Length) && (process_list[i] != nullptr)); i++)
		{
			try
			{
				System::String^ str1 = process_list[i]->ToString();
				System::String^ str2 = current;

				if (str1->Equals(str2))
				{

					if (!process_list[i]->injectDLL(DLL_PATH))
					{
						this->listProgress->Items->Add("Couldn't Inject DLL To: " + process_list[i]->ToString());
						this->listProgress->Items->Add("Maybe you don't have permissions?");
						Sleep(500);
					}
					else
					{
						MessageBox::Show("DLL Injected Successfully!");
						this->listProgress->Items->Add("DLL Injected To: " + process_list[i]->ToString());
						this->buttonInject->Enabled = false;
					}
				}
			}
			catch (Exception^ e)
			{
				MessageBox::Show(e->Message);
			}
		}
	}


	private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (listView1->SelectedItems->Count > 0)
			current = listView1->SelectedItems[0]->Text;
		isOkayToInject();
	}

	private: void isOkayToInject()
	{
		if (listView1->SelectedItems->Count < 1)
			 return;
		else if (DLL_PATH == nullptr)
			return;
		else
			this->buttonInject->Enabled = true;
	}


	private: System::Void buttonOpenDLL_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		if (openDLL->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			DLL_PATH = openDLL->FileName;
			this->dll_path_box->Text = DLL_PATH;
			isOkayToInject();
		}
	}


	private: System::Void buttonRefresh_Click(System::Object^  sender, System::EventArgs^  e) 
	{
		this->listView1->Clear();
		this->listView1->View = View::Details;
		this->listView1->Columns->Add("Process Name <-> PID");
		this->listView1->Columns[0]->Width = this->listView1->Width - 4;
		process_list = CustomProcess::getProcessList();
		for (int i = 0; i < process_list->Length; i++)
		{
			if (process_list[i] == nullptr)
				break;
			this->listView1->Items->Add(process_list[i]->ToString());
		}
	}


	private: System::Void instructionsToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		DLL_Injector::Form_Instructions^ instructions = gcnew DLL_Injector::Form_Instructions();
		instructions->ShowDialog();
	}

	private: System::Void aboutToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		DLL_Injector::Form_About^ about = gcnew DLL_Injector::Form_About();
		about->ShowDialog();
	}
};
}

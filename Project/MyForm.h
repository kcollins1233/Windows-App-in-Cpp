#pragma once
#include <iostream>
#include <boost/asio.hpp>
#include "MyForm.h"
#include "client.cpp"



namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

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
	private: System::Windows::Forms::Label^ locLabel;
	private: System::Windows::Forms::Button^ chooseImg;
	protected:


	protected:

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
			this->locLabel = (gcnew System::Windows::Forms::Label());
			this->chooseImg = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// locLabel
			// 
			this->locLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			this->locLabel->Location = System::Drawing::Point(70, 33);
			this->locLabel->Name = L"locLabel";
			this->locLabel->Size = System::Drawing::Size(1051, 27);
			this->locLabel->TabIndex = 0;
			this->locLabel->Tag = L"locLabel";
			this->locLabel->Text = L"label1";
			// 
			// chooseImg
			// 
			this->chooseImg->Location = System::Drawing::Point(76, 105);
			this->chooseImg->Name = L"chooseImg";
			this->chooseImg->Size = System::Drawing::Size(136, 43);
			this->chooseImg->TabIndex = 1;
			this->chooseImg->Text = L"Select Image";
			this->chooseImg->UseVisualStyleBackColor = true;
			this->chooseImg->Click += gcnew System::EventHandler(this, &MyForm::chooseImg_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1241, 522);
			this->Controls->Add(this->chooseImg);
			this->Controls->Add(this->locLabel);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void chooseImg_Click(System::Object^ sender, System::EventArgs^ e) {

		OpenFileDialog^ ofd = gcnew OpenFileDialog;

		ofd->InitialDirectory = "C:\\";
		ofd->RestoreDirectory = true;

		if (ofd->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			locLabel->Text = ofd->FileName->ToString();

			socket socket = new socket();
			

			
			

			
		}

	}

	

	};
}

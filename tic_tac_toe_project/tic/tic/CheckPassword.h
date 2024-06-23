#pragma once
#include "Users.h"

namespace tic {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::Data::SQLite;

	/// <summary>
	/// Summary for CheckPassword
	/// </summary>
	public ref class CheckPassword : public System::Windows::Forms::Form
	{

	private: User^ loginUser;

	public:
		CheckPassword(User^ user)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			loginUser = user;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~CheckPassword()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ prev_pass;
	private: System::Windows::Forms::TextBox^ current_pass;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ new_pass;
	private: System::Windows::Forms::Button^ confirm;
	private: System::Windows::Forms::Button^ cancel;

	protected:

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
			this->prev_pass = (gcnew System::Windows::Forms::Label());
			this->current_pass = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->new_pass = (gcnew System::Windows::Forms::TextBox());
			this->confirm = (gcnew System::Windows::Forms::Button());
			this->cancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// prev_pass
			// 
			this->prev_pass->AutoSize = true;
			this->prev_pass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->prev_pass->Location = System::Drawing::Point(12, 51);
			this->prev_pass->Name = L"prev_pass";
			this->prev_pass->Size = System::Drawing::Size(240, 25);
			this->prev_pass->TabIndex = 0;
			this->prev_pass->Text = L"Enter Current Password";
			this->prev_pass->Click += gcnew System::EventHandler(this, &CheckPassword::label1_Click);
			// 
			// current_pass
			// 
			this->current_pass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->current_pass->Location = System::Drawing::Point(273, 56);
			this->current_pass->Name = L"current_pass";
			this->current_pass->PasswordChar = '*';
			this->current_pass->Size = System::Drawing::Size(354, 26);
			this->current_pass->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 137);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(154, 25);
			this->label1->TabIndex = 2;
			this->label1->Text = L"New Password";
			// 
			// new_pass
			// 
			this->new_pass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->new_pass->Location = System::Drawing::Point(273, 136);
			this->new_pass->Name = L"new_pass";
			this->new_pass->PasswordChar = '*';
			this->new_pass->Size = System::Drawing::Size(354, 26);
			this->new_pass->TabIndex = 3;
			// 
			// confirm
			// 
			this->confirm->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->confirm->Location = System::Drawing::Point(273, 207);
			this->confirm->Name = L"confirm";
			this->confirm->Size = System::Drawing::Size(115, 41);
			this->confirm->TabIndex = 4;
			this->confirm->Text = L"Confirm";
			this->confirm->UseVisualStyleBackColor = true;
			this->confirm->Click += gcnew System::EventHandler(this, &CheckPassword::confirm_Click);
			// 
			// cancel
			// 
			this->cancel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cancel->Location = System::Drawing::Point(512, 207);
			this->cancel->Name = L"cancel";
			this->cancel->Size = System::Drawing::Size(115, 41);
			this->cancel->TabIndex = 5;
			this->cancel->Text = L"Cancel";
			this->cancel->UseVisualStyleBackColor = true;
			this->cancel->Click += gcnew System::EventHandler(this, &CheckPassword::cancel_Click);
			// 
			// CheckPassword
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnableAllowFocusChange;
			this->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->ClientSize = System::Drawing::Size(639, 272);
			this->Controls->Add(this->cancel);
			this->Controls->Add(this->confirm);
			this->Controls->Add(this->new_pass);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->current_pass);
			this->Controls->Add(this->prev_pass);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Name = L"CheckPassword";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CheckPassword";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void cancel_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
private: System::Void confirm_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ current_pass = this->current_pass->Text;
	String^ newPassword = this->new_pass->Text;

	if (current_pass->Length == 0 || newPassword->Length == 0) {
		//Empty inputs
		MessageBox::Show("Empty Data", "Empty Data");
	}
	else if(current_pass != loginUser->Password){
		MessageBox::Show("Enter the correct password", "Wrong Pass", MessageBoxButtons::OK);
	}
	else {
		try {
			// Database update query to change the password
			String^ connString = "Data Source=TicTacToeData.db;Version=3;";
			String^ sqlQuery = "UPDATE Users SET Password=@newPass WHERE User_Name=@username AND Password=@currentPass;";

			// Create a SQLite connection and command
			SQLiteConnection^ sqlConn = gcnew SQLiteConnection(connString);
			SQLiteCommand^ command = gcnew SQLiteCommand(sqlQuery, sqlConn);

			// Add parameters to the command
			command->Parameters->AddWithValue("@newPass", newPassword);
			command->Parameters->AddWithValue("@username", loginUser->Username);
			command->Parameters->AddWithValue("@currentPass", current_pass);

			// Open the connection and execute the command
			sqlConn->Open();
			int rowsAffected = command->ExecuteNonQuery();
			sqlConn->Close();

			// Check if the password was successfully updated
			if (rowsAffected > 0) {
				// Update the password in the loginUser object
				loginUser->Password = newPassword;

				MessageBox::Show("Password updated successfully.", "Password Changed", MessageBoxButtons::OK);
			}
			else {
				MessageBox::Show("Failed to update password.", "Update Failed", MessageBoxButtons::OK);
			}

		}
		catch (SQLiteException^ ex) {
			// Display an error message if connection or execution fails
			MessageBox::Show("Failed to connect to the database: " + ex->Message, "Database Error", MessageBoxButtons::OK);
		}
	}
	this->Close();
}
};
}

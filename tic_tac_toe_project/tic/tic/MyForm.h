#pragma once
#include "Users.h"
#include "CheckPassword.h"

namespace tic {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/* Hazem Edit */
	using namespace System::Data::SQLite;
	/**************/
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
			//------------------------------------------------------------------------------------
			// Create a 2D array of buttons
			buttonArray = gcnew array<Button^, 2>(3, 3); // Creating a 3x3 array of buttons

			

			//--------------------------------------------------------------------------------------
			for (int i = 0; i < 3; i++) {    //initialization the properties of the buttons
				for (int j = 0; j < 3; j++) {
					buttonArray[i, j] = gcnew Button();
					buttonArray[i, j]->Text = ""; // Assigning a unique text to each button
					buttonArray[i, j]->Location = System::Drawing::Point(10 + j * 210, 10 + i * 210); // Adjusting button positions
					buttonArray[i, j]->Size = System::Drawing::Size(200, 200);
					buttonArray[i,j]->BackColor = System::Drawing::Color::FromArgb(255, 192, 192);
					buttonArray[i, j]->Click += gcnew EventHandler(this, &MyForm::Button_Click);
					buttonArray[i,j]->Font = gcnew System::Drawing::Font("Times New Roman", 35, FontStyle::Bold);
					buttonArray[i,j]->ForeColor = System::Drawing::Color::Black;

					this->Controls->Add(buttonArray[i, j]); // Adding button to the form
					grid->Controls->Add(buttonArray[i, j]); // Adding button to the panel
				}
			}
		}

	private: System::Windows::Forms::Label^ label_loss;
	public:

	private: System::Windows::Forms::Label^ label_tie;
	private: System::Windows::Forms::Label^ label_win;
	private: System::Windows::Forms::Label^ label_name;
	private: System::Windows::Forms::Button^ delete_account;
	private: System::Windows::Forms::Button^ change_pass;
	private: System::Windows::Forms::Button^ back_to_home;
	private: System::Windows::Forms::GroupBox^ group_buttons;
	private: System::Windows::Forms::Button^ i8;

	private: System::Windows::Forms::Button^ i7;

	private: System::Windows::Forms::Button^ i6;

	private: System::Windows::Forms::Button^ i5;

	private: System::Windows::Forms::Button^ i4;

	private: System::Windows::Forms::Button^ i3;

	private: System::Windows::Forms::Button^ i2;

	private: System::Windows::Forms::Button^ i1;

	private: System::Windows::Forms::Button^ i0;
	private: System::Windows::Forms::Button^ next_game;
	private: System::Windows::Forms::Panel^ choose_level_page;
	private: System::Windows::Forms::Button^ button13;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button14;
	private: System::Windows::Forms::Button^ button15;
	private: System::Windows::Forms::Panel^ choose_level_title;
	private: System::Windows::Forms::Label^ label12;





	public: User^ loginUser = nullptr;
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



	protected:
		//--------------------variables needed------------------------------------------------


		bool Ai_mode = 0; // this variable=0 at the mode of two players and =1 at Ai mode




		//------------------------------------------------------------------------------------
	

	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
		    array<Button^, 2>^ buttonArray;

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ control_icons;
	private: System::Windows::Forms::Button^ minimize;
	private: System::Windows::Forms::Button^ max_min;
	private: System::Windows::Forms::Button^ close;
	private: System::Windows::Forms::Panel^ logo_panel;
	private: System::Windows::Forms::Label^ tic_tac_toe;
	private: System::Windows::Forms::PictureBox^ logo;
	private: System::Windows::Forms::Panel^ title_bar;
	private: System::Windows::Forms::Panel^ sign_in_title_bar;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ login_title_bar;

	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ login_main_page;
	private: System::Windows::Forms::Button^ sign_up_button;
	private: System::Windows::Forms::Label^ user_name_label;
	private: System::Windows::Forms::TextBox^ password_login;

	private: System::Windows::Forms::TextBox^ user_name_login;

	private: System::Windows::Forms::Button^ login_button;
	private: System::Windows::Forms::Label^ password_label;
	private: System::Windows::Forms::Label^ sign_up_label;
	private: System::Windows::Forms::Button^ see_password_login;

	private: System::Windows::Forms::Panel^ sign_in_main_page;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ user_name_sign_in;

	private: System::Windows::Forms::TextBox^ password_sign_in;




	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ see_password_sign_in;


	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ check_password;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ see_password_check;
	private: System::Windows::Forms::Panel^ Home_page;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Panel^ game_page;
	private: System::Windows::Forms::Button^ two_players;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Button^ logout;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ history;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ during_game;
private: System::Windows::Forms::Panel^ profile_page;

private: System::Windows::Forms::Panel^ profile_title_bar;
private: System::Windows::Forms::Label^ label11;

	private: System::Windows::Forms::Label^ label10;



		   //--------------------------------functins------------------------------------------
		   char check_winner(array<Button^, 2>^ buttons)
		   {
			  
			  for (int i = 0; i < 3; i++)
		      {
			   if (buttons[i, 0]->Text == buttons[i, 1]->Text && buttons[i, 1]->Text == buttons[i, 2]->Text && buttons[i, 0]->Text !="") //checck Rows
		     	   return buttons[i, 0]->Text == "X" ? 'X' : 'O';
		      }
			   
			  for (int i = 0; i < 3; i++)
			  {
				  if (buttons[0, i]->Text == buttons[1, i]->Text && buttons[1, i]->Text == buttons[2, i]->Text && buttons[0, i]->Text != "") //checck Rows
					  return buttons[0, i]->Text == "X" ? 'X' : 'O';
			  }
			  
			  
			  if((buttons[2, 0]->Text == buttons[1, 1]->Text && buttons[1, 1]->Text == buttons[0, 2]->Text) && buttons[2, 0]->Text != "") //check the 2nd diagonal
				  return (buttons[2, 0]->Text == "X" ? 'X' : 'O');

			  if ((buttons[0, 0]->Text == buttons[1, 1]->Text && buttons[1, 1]->Text == buttons[2, 2]->Text) && buttons[0, 0]->Text != "") //check the main diagonal
				  return (buttons[0, 0]->Text == "X" ? 'X' : 'O');

			  for (int i = 0; i < 3; i++)
			  {
				  for (int j = 0; j < 3; j++)
				  {
					  if (buttons[i, j]->Text == "")
						  return 'n';
				  }
			  }

			  return 'd';
		   }


		   /* Hazem Edit SQLite Functions */

		   String^ AppendToButtonState(String^ previousState, String^ currentState) {
			   // Concatenate the current state to the beginning of the previous state
			   String^ newState = currentState + previousState;

			   // Truncate the concatenated state if it exceeds the maximum length
			   int excessLength = newState->Length - 27;//max 3 games = 27 char
			   if (excessLength > 0) {
				   newState = newState->Substring(0, newState->Length - excessLength);
			   }

			   return newState;
		   }

		   void StoreButtonArrayState(String^ currentState) {
			   String^ connString = "Data Source=TicTacToeData.db;Version=3;";
			   try {
				   SQLiteConnection^ sqlConn = gcnew SQLiteConnection(connString);
				   sqlConn->Open();

				   // Retrieve the previous button state from the database
				   String^ sqlQuery = "SELECT ButtonState FROM Users WHERE User_Name = @username;";
				   SQLiteCommand^ command = gcnew SQLiteCommand(sqlQuery, sqlConn);
				   command->Parameters->AddWithValue("@username", loginUser->Username);
				   Object^ result = command->ExecuteScalar();

				   // Check if result is not DBNull
				   String^ previousState = "";
				   if (result != DBNull::Value && result != nullptr) {
					   previousState = safe_cast<String^>(result);
				   }

				   // Append the current state to the beginning of the previous state
				   String^ newState = AppendToButtonState(previousState, currentState);

				   // Define the SQL query for updating the button state
				   sqlQuery = "UPDATE Users SET ButtonState = @data WHERE User_Name = @username;";
				   command = gcnew SQLiteCommand(sqlQuery, sqlConn);
				   command->Parameters->AddWithValue("@username", loginUser->Username);
				   command->Parameters->AddWithValue("@data", newState);
				   command->ExecuteNonQuery();

				   sqlConn->Close();
			   }
			   catch (SQLiteException^ ex) {
				   // Handle exception
				   MessageBox::Show("Couldn't save Button state: " + ex->Message, "Store Button Error", MessageBoxButtons::OK);
			   }
		   }


		   String^ SerializeButtonArray(array<Button^, 2>^ buttonArray)
		   {
			   String^ serializedData = "";
			   for (int i = 0; i < 3; i++) {
				   for (int j = 0; j < 3; j++) {
					   if (buttonArray[i, j]->Text != "") {
						   serializedData += buttonArray[i, j]->Text;
					   }
					   else {
						   serializedData += " "; // Represent empty button with a space
					   }
				   }
			   }
			   return serializedData;
		   }
		   /*
		   void StoreButtonArrayState(String^ serializedData)
		   {
			   String^ connString = "Data Source=TicTacToeData.db;Version=3;";
			   try {
				   SQLiteConnection^ sqlConn = gcnew SQLiteConnection(connString);
				   sqlConn->Open();

				   // Define the SQL query for updating the ButtonState field for a specific user
				   String^ sqlQuery = "UPDATE Users SET ButtonState = @data WHERE User_Name = @username;";

				   // Create a SQLite command with the SQL query and connection
				   SQLiteCommand^ command = gcnew SQLiteCommand(sqlQuery, sqlConn);

				   // Add parameters to the command
				   command->Parameters->AddWithValue("@data", serializedData);
				   command->Parameters->AddWithValue("@username", loginUser->Username);

				   // Execute the SQL command
				   command->ExecuteNonQuery();

				   // Close the connection
				   sqlConn->Close();
			   }
			   catch (SQLiteException^ ex) {
				   // Handle exception
				   MessageBox::Show("Couldn't update Button state: " + ex->Message, "Store Button Error", MessageBoxButtons::OK);
			   }
		   }
		   */
		   /*********************************************/


		   //------------------------------------------------------------------------------------------







private: System::Windows::Forms::Button^ one_player;
private: System::Windows::Forms::Panel^ x_o_grid_page;

private: System::Windows::Forms::Panel^ data_grid;
private: System::Windows::Forms::Panel^ grid;
private: System::Windows::Forms::Panel^ user_data;
private: System::Windows::Forms::Panel^ user_2_data;




private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::PictureBox^ pictureBox6;
private: System::Windows::Forms::Panel^ user_1_data;

private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::PictureBox^ pictureBox7;
private: System::Windows::Forms::Panel^ exit_reset;
private: System::Windows::Forms::Button^ exit;


private: System::Windows::Forms::Button^ reset;






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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->one_player = (gcnew System::Windows::Forms::Button());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->choose_level_page = (gcnew System::Windows::Forms::Panel());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->game_page = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->history = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->logout = (gcnew System::Windows::Forms::Button());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->two_players = (gcnew System::Windows::Forms::Button());
			this->profile_page = (gcnew System::Windows::Forms::Panel());
			this->next_game = (gcnew System::Windows::Forms::Button());
			this->group_buttons = (gcnew System::Windows::Forms::GroupBox());
			this->i8 = (gcnew System::Windows::Forms::Button());
			this->i7 = (gcnew System::Windows::Forms::Button());
			this->i6 = (gcnew System::Windows::Forms::Button());
			this->i5 = (gcnew System::Windows::Forms::Button());
			this->i4 = (gcnew System::Windows::Forms::Button());
			this->i3 = (gcnew System::Windows::Forms::Button());
			this->i2 = (gcnew System::Windows::Forms::Button());
			this->i1 = (gcnew System::Windows::Forms::Button());
			this->i0 = (gcnew System::Windows::Forms::Button());
			this->back_to_home = (gcnew System::Windows::Forms::Button());
			this->delete_account = (gcnew System::Windows::Forms::Button());
			this->change_pass = (gcnew System::Windows::Forms::Button());
			this->label_loss = (gcnew System::Windows::Forms::Label());
			this->label_tie = (gcnew System::Windows::Forms::Label());
			this->label_win = (gcnew System::Windows::Forms::Label());
			this->label_name = (gcnew System::Windows::Forms::Label());
			this->x_o_grid_page = (gcnew System::Windows::Forms::Panel());
			this->data_grid = (gcnew System::Windows::Forms::Panel());
			this->grid = (gcnew System::Windows::Forms::Panel());
			this->user_data = (gcnew System::Windows::Forms::Panel());
			this->user_2_data = (gcnew System::Windows::Forms::Panel());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->user_1_data = (gcnew System::Windows::Forms::Panel());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->exit_reset = (gcnew System::Windows::Forms::Panel());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->reset = (gcnew System::Windows::Forms::Button());
			this->login_main_page = (gcnew System::Windows::Forms::Panel());
			this->sign_up_button = (gcnew System::Windows::Forms::Button());
			this->user_name_label = (gcnew System::Windows::Forms::Label());
			this->password_login = (gcnew System::Windows::Forms::TextBox());
			this->user_name_login = (gcnew System::Windows::Forms::TextBox());
			this->login_button = (gcnew System::Windows::Forms::Button());
			this->password_label = (gcnew System::Windows::Forms::Label());
			this->sign_up_label = (gcnew System::Windows::Forms::Label());
			this->see_password_login = (gcnew System::Windows::Forms::Button());
			this->sign_in_main_page = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->user_name_sign_in = (gcnew System::Windows::Forms::TextBox());
			this->check_password = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->password_sign_in = (gcnew System::Windows::Forms::TextBox());
			this->see_password_check = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->see_password_sign_in = (gcnew System::Windows::Forms::Button());
			this->control_icons = (gcnew System::Windows::Forms::Panel());
			this->minimize = (gcnew System::Windows::Forms::Button());
			this->max_min = (gcnew System::Windows::Forms::Button());
			this->close = (gcnew System::Windows::Forms::Button());
			this->logo_panel = (gcnew System::Windows::Forms::Panel());
			this->tic_tac_toe = (gcnew System::Windows::Forms::Label());
			this->logo = (gcnew System::Windows::Forms::PictureBox());
			this->title_bar = (gcnew System::Windows::Forms::Panel());
			this->Home_page = (gcnew System::Windows::Forms::Panel());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->choose_level_title = (gcnew System::Windows::Forms::Panel());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->login_title_bar = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->profile_title_bar = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->during_game = (gcnew System::Windows::Forms::Panel());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->sign_in_title_bar = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->choose_level_page->SuspendLayout();
			this->game_page->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->profile_page->SuspendLayout();
			this->group_buttons->SuspendLayout();
			this->x_o_grid_page->SuspendLayout();
			this->data_grid->SuspendLayout();
			this->user_data->SuspendLayout();
			this->user_2_data->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			this->user_1_data->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			this->exit_reset->SuspendLayout();
			this->login_main_page->SuspendLayout();
			this->sign_in_main_page->SuspendLayout();
			this->control_icons->SuspendLayout();
			this->logo_panel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo))->BeginInit();
			this->title_bar->SuspendLayout();
			this->Home_page->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->choose_level_title->SuspendLayout();
			this->login_title_bar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->profile_title_bar->SuspendLayout();
			this->during_game->SuspendLayout();
			this->sign_in_title_bar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// one_player
			// 
			this->one_player->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->one_player->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"one_player.BackgroundImage")));
			this->one_player->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->one_player->Location = System::Drawing::Point(83, 98);
			this->one_player->Margin = System::Windows::Forms::Padding(11, 10, 11, 10);
			this->one_player->Name = L"one_player";
			this->one_player->Size = System::Drawing::Size(132, 127);
			this->one_player->TabIndex = 0;
			this->one_player->UseVisualStyleBackColor = true;
			this->one_player->Click += gcnew System::EventHandler(this, &MyForm::one_player_Click);
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->panel1->Controls->Add(this->game_page);
			this->panel1->Controls->Add(this->login_main_page);
			this->panel1->Controls->Add(this->choose_level_page);
			this->panel1->Controls->Add(this->profile_page);
			this->panel1->Controls->Add(this->x_o_grid_page);
			this->panel1->Controls->Add(this->sign_in_main_page);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 91);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1135, 552);
			this->panel1->TabIndex = 1;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			// 
			// choose_level_page
			// 
			this->choose_level_page->Controls->Add(this->button13);
			this->choose_level_page->Controls->Add(this->button3);
			this->choose_level_page->Controls->Add(this->button14);
			this->choose_level_page->Controls->Add(this->button15);
			this->choose_level_page->Dock = System::Windows::Forms::DockStyle::Fill;
			this->choose_level_page->Location = System::Drawing::Point(0, 0);
			this->choose_level_page->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->choose_level_page->Name = L"choose_level_page";
			this->choose_level_page->Size = System::Drawing::Size(1135, 552);
			this->choose_level_page->TabIndex = 20;
			// 
			// button13
			// 
			this->button13->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->button13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button13->Location = System::Drawing::Point(501, 443);
			this->button13->Margin = System::Windows::Forms::Padding(4);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(139, 48);
			this->button13->TabIndex = 6;
			this->button13->Text = L"Home";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// button3
			// 
			this->button3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(835, 95);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(236, 215);
			this->button3->TabIndex = 5;
			this->button3->Text = L"hard";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click_1);
			// 
			// button14
			// 
			this->button14->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button14->Location = System::Drawing::Point(458, 95);
			this->button14->Margin = System::Windows::Forms::Padding(4);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(245, 215);
			this->button14->TabIndex = 5;
			this->button14->Text = L"Medium\r\n";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// button15
			// 
			this->button15->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button15->Location = System::Drawing::Point(88, 95);
			this->button15->Margin = System::Windows::Forms::Padding(4);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(256, 215);
			this->button15->TabIndex = 4;
			this->button15->Text = L"Easy";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// game_page
			// 
			this->game_page->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->game_page->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->game_page->Controls->Add(this->panel4);
			this->game_page->Controls->Add(this->panel2);
			this->game_page->Controls->Add(this->panel3);
			this->game_page->Dock = System::Windows::Forms::DockStyle::Fill;
			this->game_page->Location = System::Drawing::Point(0, 0);
			this->game_page->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->game_page->Name = L"game_page";
			this->game_page->Size = System::Drawing::Size(1135, 552);
			this->game_page->TabIndex = 8;
			// 
			// panel4
			// 
			this->panel4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel4.BackgroundImage")));
			this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel4->Location = System::Drawing::Point(348, 0);
			this->panel4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(443, 552);
			this->panel4->TabIndex = 5;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->button1);
			this->panel2->Controls->Add(this->history);
			this->panel2->Controls->Add(this->one_player);
			this->panel2->Controls->Add(this->label8);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel2->Location = System::Drawing::Point(791, 0);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(344, 552);
			this->panel2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(45, 465);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(259, 59);
			this->button1->TabIndex = 2;
			this->button1->Text = L"players sign in the game ";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// history
			// 
			this->history->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->history->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->history->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->history->Location = System::Drawing::Point(45, 334);
			this->history->Margin = System::Windows::Forms::Padding(11, 10, 11, 10);
			this->history->Name = L"history";
			this->history->Size = System::Drawing::Size(259, 59);
			this->history->TabIndex = 2;
			this->history->Text = L"Your Profile";
			this->history->UseVisualStyleBackColor = false;
			this->history->Click += gcnew System::EventHandler(this, &MyForm::history_Click);
			// 
			// label8
			// 
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::Red;
			this->label8->Location = System::Drawing::Point(67, 33);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(163, 53);
			this->label8->TabIndex = 1;
			this->label8->Text = L"One player";
			this->label8->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->logout);
			this->panel3->Controls->Add(this->label9);
			this->panel3->Controls->Add(this->two_players);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(348, 552);
			this->panel3->TabIndex = 4;
			// 
			// logout
			// 
			this->logout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->logout->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logout.BackgroundImage")));
			this->logout->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->logout->Location = System::Drawing::Point(5, 467);
			this->logout->Margin = System::Windows::Forms::Padding(5);
			this->logout->Name = L"logout";
			this->logout->Size = System::Drawing::Size(99, 81);
			this->logout->TabIndex = 2;
			this->logout->UseVisualStyleBackColor = true;
			this->logout->Click += gcnew System::EventHandler(this, &MyForm::logout_Click);
			// 
			// label9
			// 
			this->label9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::Red;
			this->label9->Location = System::Drawing::Point(96, 26);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(192, 53);
			this->label9->TabIndex = 1;
			this->label9->Text = L"Two players";
			this->label9->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// two_players
			// 
			this->two_players->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->two_players->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"two_players.BackgroundImage")));
			this->two_players->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->two_players->Location = System::Drawing::Point(124, 81);
			this->two_players->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->two_players->Name = L"two_players";
			this->two_players->Size = System::Drawing::Size(132, 127);
			this->two_players->TabIndex = 0;
			this->two_players->UseVisualStyleBackColor = true;
			this->two_players->Click += gcnew System::EventHandler(this, &MyForm::two_players_Click);
			// 
			// profile_page
			// 
			this->profile_page->Controls->Add(this->next_game);
			this->profile_page->Controls->Add(this->group_buttons);
			this->profile_page->Controls->Add(this->back_to_home);
			this->profile_page->Controls->Add(this->delete_account);
			this->profile_page->Controls->Add(this->change_pass);
			this->profile_page->Controls->Add(this->label_loss);
			this->profile_page->Controls->Add(this->label_tie);
			this->profile_page->Controls->Add(this->label_win);
			this->profile_page->Controls->Add(this->label_name);
			this->profile_page->Dock = System::Windows::Forms::DockStyle::Fill;
			this->profile_page->Location = System::Drawing::Point(0, 0);
			this->profile_page->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->profile_page->Name = L"profile_page";
			this->profile_page->Size = System::Drawing::Size(1135, 552);
			this->profile_page->TabIndex = 19;
			// 
			// next_game
			// 
			this->next_game->Location = System::Drawing::Point(807, 337);
			this->next_game->Margin = System::Windows::Forms::Padding(4);
			this->next_game->Name = L"next_game";
			this->next_game->Size = System::Drawing::Size(120, 46);
			this->next_game->TabIndex = 8;
			this->next_game->Text = L"Show Game";
			this->next_game->UseVisualStyleBackColor = true;
			this->next_game->Click += gcnew System::EventHandler(this, &MyForm::next_game_Click);
			// 
			// group_buttons
			// 
			this->group_buttons->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->group_buttons->Controls->Add(this->i8);
			this->group_buttons->Controls->Add(this->i7);
			this->group_buttons->Controls->Add(this->i6);
			this->group_buttons->Controls->Add(this->i5);
			this->group_buttons->Controls->Add(this->i4);
			this->group_buttons->Controls->Add(this->i3);
			this->group_buttons->Controls->Add(this->i2);
			this->group_buttons->Controls->Add(this->i1);
			this->group_buttons->Controls->Add(this->i0);
			this->group_buttons->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->group_buttons->ForeColor = System::Drawing::SystemColors::AppWorkspace;
			this->group_buttons->Location = System::Drawing::Point(804, 48);
			this->group_buttons->Margin = System::Windows::Forms::Padding(4);
			this->group_buttons->Name = L"group_buttons";
			this->group_buttons->Padding = System::Windows::Forms::Padding(4);
			this->group_buttons->Size = System::Drawing::Size(291, 254);
			this->group_buttons->TabIndex = 7;
			this->group_buttons->TabStop = false;
			this->group_buttons->Text = L"Game History";
			// 
			// i8
			// 
			this->i8->Location = System::Drawing::Point(203, 175);
			this->i8->Margin = System::Windows::Forms::Padding(4);
			this->i8->Name = L"i8";
			this->i8->Size = System::Drawing::Size(73, 58);
			this->i8->TabIndex = 8;
			this->i8->Text = L"button11";
			this->i8->UseVisualStyleBackColor = true;
			// 
			// i7
			// 
			this->i7->Location = System::Drawing::Point(111, 175);
			this->i7->Margin = System::Windows::Forms::Padding(4);
			this->i7->Name = L"i7";
			this->i7->Size = System::Drawing::Size(73, 58);
			this->i7->TabIndex = 7;
			this->i7->Text = L"button10";
			this->i7->UseVisualStyleBackColor = true;
			// 
			// i6
			// 
			this->i6->Location = System::Drawing::Point(16, 175);
			this->i6->Margin = System::Windows::Forms::Padding(4);
			this->i6->Name = L"i6";
			this->i6->Size = System::Drawing::Size(73, 58);
			this->i6->TabIndex = 6;
			this->i6->Text = L"button9";
			this->i6->UseVisualStyleBackColor = true;
			// 
			// i5
			// 
			this->i5->Location = System::Drawing::Point(203, 103);
			this->i5->Margin = System::Windows::Forms::Padding(4);
			this->i5->Name = L"i5";
			this->i5->Size = System::Drawing::Size(73, 58);
			this->i5->TabIndex = 5;
			this->i5->Text = L"button8";
			this->i5->UseVisualStyleBackColor = true;
			this->i5->Click += gcnew System::EventHandler(this, &MyForm::i5_Click);
			// 
			// i4
			// 
			this->i4->Location = System::Drawing::Point(111, 102);
			this->i4->Margin = System::Windows::Forms::Padding(4);
			this->i4->Name = L"i4";
			this->i4->Size = System::Drawing::Size(73, 58);
			this->i4->TabIndex = 4;
			this->i4->Text = L"button7";
			this->i4->UseVisualStyleBackColor = true;
			// 
			// i3
			// 
			this->i3->Location = System::Drawing::Point(16, 102);
			this->i3->Margin = System::Windows::Forms::Padding(4);
			this->i3->Name = L"i3";
			this->i3->Size = System::Drawing::Size(73, 58);
			this->i3->TabIndex = 3;
			this->i3->Text = L"button6";
			this->i3->UseVisualStyleBackColor = true;
			// 
			// i2
			// 
			this->i2->Location = System::Drawing::Point(203, 27);
			this->i2->Margin = System::Windows::Forms::Padding(4);
			this->i2->Name = L"i2";
			this->i2->Size = System::Drawing::Size(73, 58);
			this->i2->TabIndex = 2;
			this->i2->Text = L"button5";
			this->i2->UseVisualStyleBackColor = true;
			// 
			// i1
			// 
			this->i1->Location = System::Drawing::Point(111, 27);
			this->i1->Margin = System::Windows::Forms::Padding(4);
			this->i1->Name = L"i1";
			this->i1->Size = System::Drawing::Size(73, 58);
			this->i1->TabIndex = 1;
			this->i1->Text = L"button4";
			this->i1->UseVisualStyleBackColor = true;
			// 
			// i0
			// 
			this->i0->Location = System::Drawing::Point(16, 27);
			this->i0->Margin = System::Windows::Forms::Padding(4);
			this->i0->Name = L"i0";
			this->i0->Size = System::Drawing::Size(73, 58);
			this->i0->TabIndex = 0;
			this->i0->Text = L"button3";
			this->i0->UseVisualStyleBackColor = true;
			// 
			// back_to_home
			// 
			this->back_to_home->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->back_to_home->Location = System::Drawing::Point(461, 421);
			this->back_to_home->Margin = System::Windows::Forms::Padding(4);
			this->back_to_home->Name = L"back_to_home";
			this->back_to_home->Size = System::Drawing::Size(139, 48);
			this->back_to_home->TabIndex = 6;
			this->back_to_home->Text = L"Home";
			this->back_to_home->UseVisualStyleBackColor = true;
			this->back_to_home->Click += gcnew System::EventHandler(this, &MyForm::back_to_home_Click);
			// 
			// delete_account
			// 
			this->delete_account->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->delete_account->Location = System::Drawing::Point(88, 421);
			this->delete_account->Margin = System::Windows::Forms::Padding(4);
			this->delete_account->Name = L"delete_account";
			this->delete_account->Size = System::Drawing::Size(236, 48);
			this->delete_account->TabIndex = 5;
			this->delete_account->Text = L"Delete Account";
			this->delete_account->UseVisualStyleBackColor = true;
			this->delete_account->Click += gcnew System::EventHandler(this, &MyForm::delete_account_Click);
			// 
			// change_pass
			// 
			this->change_pass->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->change_pass->Location = System::Drawing::Point(87, 335);
			this->change_pass->Margin = System::Windows::Forms::Padding(4);
			this->change_pass->Name = L"change_pass";
			this->change_pass->Size = System::Drawing::Size(236, 48);
			this->change_pass->TabIndex = 4;
			this->change_pass->Text = L"Change Password";
			this->change_pass->UseVisualStyleBackColor = true;
			this->change_pass->Click += gcnew System::EventHandler(this, &MyForm::change_pass_Click);
			// 
			// label_loss
			// 
			this->label_loss->AutoSize = true;
			this->label_loss->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_loss->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label_loss->Location = System::Drawing::Point(81, 230);
			this->label_loss->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_loss->Name = L"label_loss";
			this->label_loss->Size = System::Drawing::Size(159, 36);
			this->label_loss->TabIndex = 3;
			this->label_loss->Text = L"lable_loss";
			// 
			// label_tie
			// 
			this->label_tie->AutoSize = true;
			this->label_tie->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_tie->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label_tie->Location = System::Drawing::Point(81, 172);
			this->label_tie->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_tie->Name = L"label_tie";
			this->label_tie->Size = System::Drawing::Size(135, 36);
			this->label_tie->TabIndex = 2;
			this->label_tie->Text = L"lable_tie";
			// 
			// label_win
			// 
			this->label_win->AutoSize = true;
			this->label_win->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_win->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label_win->Location = System::Drawing::Point(81, 108);
			this->label_win->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_win->Name = L"label_win";
			this->label_win->Size = System::Drawing::Size(150, 36);
			this->label_win->TabIndex = 1;
			this->label_win->Text = L"lable_win";
			// 
			// label_name
			// 
			this->label_name->AutoSize = true;
			this->label_name->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_name->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->label_name->Location = System::Drawing::Point(81, 48);
			this->label_name->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label_name->Name = L"label_name";
			this->label_name->Size = System::Drawing::Size(177, 36);
			this->label_name->TabIndex = 0;
			this->label_name->Text = L"lable_name";
			// 
			// x_o_grid_page
			// 
			this->x_o_grid_page->Controls->Add(this->data_grid);
			this->x_o_grid_page->Controls->Add(this->exit_reset);
			this->x_o_grid_page->Dock = System::Windows::Forms::DockStyle::Fill;
			this->x_o_grid_page->Location = System::Drawing::Point(0, 0);
			this->x_o_grid_page->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->x_o_grid_page->Name = L"x_o_grid_page";
			this->x_o_grid_page->Size = System::Drawing::Size(1135, 552);
			this->x_o_grid_page->TabIndex = 18;
			// 
			// data_grid
			// 
			this->data_grid->Controls->Add(this->grid);
			this->data_grid->Controls->Add(this->user_data);
			this->data_grid->Dock = System::Windows::Forms::DockStyle::Fill;
			this->data_grid->Location = System::Drawing::Point(0, 0);
			this->data_grid->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->data_grid->Name = L"data_grid";
			this->data_grid->Size = System::Drawing::Size(1135, 449);
			this->data_grid->TabIndex = 1;
			// 
			// grid
			// 
			this->grid->AutoScroll = true;
			this->grid->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->grid->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->grid->Dock = System::Windows::Forms::DockStyle::Fill;
			this->grid->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->grid->Location = System::Drawing::Point(0, 0);
			this->grid->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->grid->Name = L"grid";
			this->grid->Size = System::Drawing::Size(634, 449);
			this->grid->TabIndex = 4;
			this->grid->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::grid_Paint);
			// 
			// user_data
			// 
			this->user_data->Controls->Add(this->user_2_data);
			this->user_data->Controls->Add(this->user_1_data);
			this->user_data->Dock = System::Windows::Forms::DockStyle::Right;
			this->user_data->Location = System::Drawing::Point(634, 0);
			this->user_data->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->user_data->Name = L"user_data";
			this->user_data->Size = System::Drawing::Size(501, 449);
			this->user_data->TabIndex = 3;
			// 
			// user_2_data
			// 
			this->user_2_data->Controls->Add(this->label13);
			this->user_2_data->Controls->Add(this->pictureBox6);
			this->user_2_data->Dock = System::Windows::Forms::DockStyle::Fill;
			this->user_2_data->Location = System::Drawing::Point(0, 0);
			this->user_2_data->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->user_2_data->Name = L"user_2_data";
			this->user_2_data->Size = System::Drawing::Size(260, 449);
			this->user_2_data->TabIndex = 1;
			// 
			// label13
			// 
			this->label13->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label13->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label13->Location = System::Drawing::Point(39, 263);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(203, 78);
			this->label13->TabIndex = 1;
			this->label13->Text = L"User_1";
			this->label13->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.BackgroundImage")));
			this->pictureBox6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox6->Location = System::Drawing::Point(47, 36);
			this->pictureBox6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(180, 201);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox6->TabIndex = 0;
			this->pictureBox6->TabStop = false;
			// 
			// user_1_data
			// 
			this->user_1_data->Controls->Add(this->label14);
			this->user_1_data->Controls->Add(this->pictureBox7);
			this->user_1_data->Dock = System::Windows::Forms::DockStyle::Right;
			this->user_1_data->Location = System::Drawing::Point(260, 0);
			this->user_1_data->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->user_1_data->Name = L"user_1_data";
			this->user_1_data->Size = System::Drawing::Size(241, 449);
			this->user_1_data->TabIndex = 2;
			// 
			// label14
			// 
			this->label14->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label14->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label14->Location = System::Drawing::Point(27, 266);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(203, 78);
			this->label14->TabIndex = 1;
			this->label14->Text = L"User_2";
			this->label14->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pictureBox7
			// 
			this->pictureBox7->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.BackgroundImage")));
			this->pictureBox7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox7->Location = System::Drawing::Point(27, 36);
			this->pictureBox7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(187, 201);
			this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox7->TabIndex = 0;
			this->pictureBox7->TabStop = false;
			// 
			// exit_reset
			// 
			this->exit_reset->Controls->Add(this->exit);
			this->exit_reset->Controls->Add(this->reset);
			this->exit_reset->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->exit_reset->Location = System::Drawing::Point(0, 449);
			this->exit_reset->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->exit_reset->Name = L"exit_reset";
			this->exit_reset->Size = System::Drawing::Size(1135, 103);
			this->exit_reset->TabIndex = 0;
			// 
			// exit
			// 
			this->exit->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->exit->Dock = System::Windows::Forms::DockStyle::Left;
			this->exit->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 34.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exit->Location = System::Drawing::Point(0, 0);
			this->exit->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(624, 103);
			this->exit->TabIndex = 1;
			this->exit->Text = L"Exit";
			this->exit->UseVisualStyleBackColor = false;
			this->exit->Click += gcnew System::EventHandler(this, &MyForm::exit_Click_1);
			// 
			// reset
			// 
			this->reset->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->reset->Dock = System::Windows::Forms::DockStyle::Right;
			this->reset->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 34.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->reset->Location = System::Drawing::Point(618, 0);
			this->reset->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->reset->Name = L"reset";
			this->reset->Size = System::Drawing::Size(517, 103);
			this->reset->TabIndex = 0;
			this->reset->Text = L"Reset";
			this->reset->UseVisualStyleBackColor = false;
			this->reset->Click += gcnew System::EventHandler(this, &MyForm::reset_Click_1);
			// 
			// login_main_page
			// 
			this->login_main_page->Controls->Add(this->sign_up_button);
			this->login_main_page->Controls->Add(this->user_name_label);
			this->login_main_page->Controls->Add(this->password_login);
			this->login_main_page->Controls->Add(this->user_name_login);
			this->login_main_page->Controls->Add(this->login_button);
			this->login_main_page->Controls->Add(this->password_label);
			this->login_main_page->Controls->Add(this->sign_up_label);
			this->login_main_page->Controls->Add(this->see_password_login);
			this->login_main_page->Dock = System::Windows::Forms::DockStyle::Fill;
			this->login_main_page->Location = System::Drawing::Point(0, 0);
			this->login_main_page->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->login_main_page->Name = L"login_main_page";
			this->login_main_page->Size = System::Drawing::Size(1135, 552);
			this->login_main_page->TabIndex = 6;
			// 
			// sign_up_button
			// 
			this->sign_up_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->sign_up_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sign_up_button->Location = System::Drawing::Point(482, 346);
			this->sign_up_button->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->sign_up_button->Name = L"sign_up_button";
			this->sign_up_button->Size = System::Drawing::Size(164, 41);
			this->sign_up_button->TabIndex = 15;
			this->sign_up_button->Text = L"Sign up";
			this->sign_up_button->UseVisualStyleBackColor = true;
			this->sign_up_button->Click += gcnew System::EventHandler(this, &MyForm::sign_up_button_Click);
			// 
			// user_name_label
			// 
			this->user_name_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->user_name_label->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->user_name_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->user_name_label->ForeColor = System::Drawing::Color::White;
			this->user_name_label->Location = System::Drawing::Point(241, 108);
			this->user_name_label->Name = L"user_name_label";
			this->user_name_label->Size = System::Drawing::Size(139, 47);
			this->user_name_label->TabIndex = 14;
			this->user_name_label->Text = L"User name :";
			this->user_name_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// password_login
			// 
			this->password_login->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->password_login->Location = System::Drawing::Point(376, 198);
			this->password_login->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->password_login->Name = L"password_login";
			this->password_login->PasswordChar = '*';
			this->password_login->Size = System::Drawing::Size(399, 22);
			this->password_login->TabIndex = 12;
			// 
			// user_name_login
			// 
			this->user_name_login->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->user_name_login->Location = System::Drawing::Point(376, 123);
			this->user_name_login->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->user_name_login->Name = L"user_name_login";
			this->user_name_login->Size = System::Drawing::Size(399, 22);
			this->user_name_login->TabIndex = 11;
			// 
			// login_button
			// 
			this->login_button->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->login_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->login_button->Location = System::Drawing::Point(482, 261);
			this->login_button->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->login_button->Name = L"login_button";
			this->login_button->Size = System::Drawing::Size(164, 41);
			this->login_button->TabIndex = 10;
			this->login_button->Text = L"login";
			this->login_button->UseVisualStyleBackColor = true;
			this->login_button->Click += gcnew System::EventHandler(this, &MyForm::login_button_Click);
			// 
			// password_label
			// 
			this->password_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->password_label->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->password_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->password_label->ForeColor = System::Drawing::Color::White;
			this->password_label->Location = System::Drawing::Point(241, 183);
			this->password_label->Name = L"password_label";
			this->password_label->Size = System::Drawing::Size(139, 47);
			this->password_label->TabIndex = 9;
			this->password_label->Text = L"password :";
			this->password_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// sign_up_label
			// 
			this->sign_up_label->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->sign_up_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sign_up_label->ForeColor = System::Drawing::Color::White;
			this->sign_up_label->Location = System::Drawing::Point(344, 314);
			this->sign_up_label->Name = L"sign_up_label";
			this->sign_up_label->Size = System::Drawing::Size(461, 30);
			this->sign_up_label->TabIndex = 8;
			this->sign_up_label->Text = L"If you are a new user create new acount ";
			this->sign_up_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// see_password_login
			// 
			this->see_password_login->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->see_password_login->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"see_password_login.BackgroundImage")));
			this->see_password_login->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->see_password_login->Location = System::Drawing::Point(790, 193);
			this->see_password_login->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->see_password_login->Name = L"see_password_login";
			this->see_password_login->Size = System::Drawing::Size(57, 33);
			this->see_password_login->TabIndex = 5;
			this->see_password_login->UseVisualStyleBackColor = true;
			this->see_password_login->Click += gcnew System::EventHandler(this, &MyForm::see_password_login_Click);
			// 
			// sign_in_main_page
			// 
			this->sign_in_main_page->Controls->Add(this->button2);
			this->sign_in_main_page->Controls->Add(this->label5);
			this->sign_in_main_page->Controls->Add(this->label3);
			this->sign_in_main_page->Controls->Add(this->user_name_sign_in);
			this->sign_in_main_page->Controls->Add(this->check_password);
			this->sign_in_main_page->Controls->Add(this->label6);
			this->sign_in_main_page->Controls->Add(this->password_sign_in);
			this->sign_in_main_page->Controls->Add(this->see_password_check);
			this->sign_in_main_page->Controls->Add(this->label4);
			this->sign_in_main_page->Controls->Add(this->see_password_sign_in);
			this->sign_in_main_page->Dock = System::Windows::Forms::DockStyle::Fill;
			this->sign_in_main_page->Location = System::Drawing::Point(0, 0);
			this->sign_in_main_page->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->sign_in_main_page->Name = L"sign_in_main_page";
			this->sign_in_main_page->Size = System::Drawing::Size(1135, 552);
			this->sign_in_main_page->TabIndex = 7;
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(434, 383);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(164, 41);
			this->button2->TabIndex = 15;
			this->button2->Text = L"Sign up";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(389, 34);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(227, 59);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Enter your data : ";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(197, 135);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(139, 47);
			this->label3->TabIndex = 14;
			this->label3->Text = L"User name :";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// user_name_sign_in
			// 
			this->user_name_sign_in->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->user_name_sign_in->Location = System::Drawing::Point(341, 151);
			this->user_name_sign_in->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->user_name_sign_in->Name = L"user_name_sign_in";
			this->user_name_sign_in->Size = System::Drawing::Size(399, 22);
			this->user_name_sign_in->TabIndex = 12;
			// 
			// check_password
			// 
			this->check_password->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->check_password->Location = System::Drawing::Point(341, 308);
			this->check_password->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->check_password->Name = L"check_password";
			this->check_password->PasswordChar = '*';
			this->check_password->Size = System::Drawing::Size(399, 22);
			this->check_password->TabIndex = 11;
			this->check_password->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(137, 293);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(197, 47);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Ensure password  :";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// password_sign_in
			// 
			this->password_sign_in->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->password_sign_in->Location = System::Drawing::Point(341, 226);
			this->password_sign_in->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->password_sign_in->Name = L"password_sign_in";
			this->password_sign_in->PasswordChar = '*';
			this->password_sign_in->Size = System::Drawing::Size(399, 22);
			this->password_sign_in->TabIndex = 11;
			this->password_sign_in->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox4_TextChanged);
			// 
			// see_password_check
			// 
			this->see_password_check->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->see_password_check->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"see_password_check.BackgroundImage")));
			this->see_password_check->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->see_password_check->Location = System::Drawing::Point(765, 297);
			this->see_password_check->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->see_password_check->Name = L"see_password_check";
			this->see_password_check->Size = System::Drawing::Size(57, 33);
			this->see_password_check->TabIndex = 5;
			this->see_password_check->UseVisualStyleBackColor = true;
			this->see_password_check->Click += gcnew System::EventHandler(this, &MyForm::see_password_check_Click);
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(197, 210);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(139, 47);
			this->label4->TabIndex = 9;
			this->label4->Text = L"password :";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// see_password_sign_in
			// 
			this->see_password_sign_in->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->see_password_sign_in->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"see_password_sign_in.BackgroundImage")));
			this->see_password_sign_in->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->see_password_sign_in->Location = System::Drawing::Point(765, 215);
			this->see_password_sign_in->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->see_password_sign_in->Name = L"see_password_sign_in";
			this->see_password_sign_in->Size = System::Drawing::Size(57, 33);
			this->see_password_sign_in->TabIndex = 5;
			this->see_password_sign_in->UseVisualStyleBackColor = true;
			this->see_password_sign_in->Click += gcnew System::EventHandler(this, &MyForm::see_password_sign_in_Click);
			// 
			// control_icons
			// 
			this->control_icons->Controls->Add(this->minimize);
			this->control_icons->Controls->Add(this->max_min);
			this->control_icons->Controls->Add(this->close);
			this->control_icons->Dock = System::Windows::Forms::DockStyle::Right;
			this->control_icons->Location = System::Drawing::Point(874, 0);
			this->control_icons->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->control_icons->Name = L"control_icons";
			this->control_icons->Size = System::Drawing::Size(261, 91);
			this->control_icons->TabIndex = 0;
			// 
			// minimize
			// 
			this->minimize->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"minimize.BackgroundImage")));
			this->minimize->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->minimize->Dock = System::Windows::Forms::DockStyle::Fill;
			this->minimize->Location = System::Drawing::Point(0, 0);
			this->minimize->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->minimize->Name = L"minimize";
			this->minimize->Size = System::Drawing::Size(87, 91);
			this->minimize->TabIndex = 1;
			this->minimize->UseVisualStyleBackColor = true;
			this->minimize->Click += gcnew System::EventHandler(this, &MyForm::minimize_Click);
			// 
			// max_min
			// 
			this->max_min->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"max_min.BackgroundImage")));
			this->max_min->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->max_min->Dock = System::Windows::Forms::DockStyle::Right;
			this->max_min->Location = System::Drawing::Point(87, 0);
			this->max_min->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->max_min->Name = L"max_min";
			this->max_min->Size = System::Drawing::Size(81, 91);
			this->max_min->TabIndex = 1;
			this->max_min->UseVisualStyleBackColor = true;
			this->max_min->Click += gcnew System::EventHandler(this, &MyForm::max_min_Click);
			// 
			// close
			// 
			this->close->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"close.BackgroundImage")));
			this->close->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->close->Dock = System::Windows::Forms::DockStyle::Right;
			this->close->Location = System::Drawing::Point(168, 0);
			this->close->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->close->Name = L"close";
			this->close->Size = System::Drawing::Size(93, 91);
			this->close->TabIndex = 0;
			this->close->UseVisualStyleBackColor = true;
			this->close->Click += gcnew System::EventHandler(this, &MyForm::close_Click);
			// 
			// logo_panel
			// 
			this->logo_panel->Controls->Add(this->tic_tac_toe);
			this->logo_panel->Controls->Add(this->logo);
			this->logo_panel->Dock = System::Windows::Forms::DockStyle::Left;
			this->logo_panel->Location = System::Drawing::Point(0, 0);
			this->logo_panel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->logo_panel->Name = L"logo_panel";
			this->logo_panel->Size = System::Drawing::Size(131, 91);
			this->logo_panel->TabIndex = 1;
			// 
			// tic_tac_toe
			// 
			this->tic_tac_toe->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tic_tac_toe->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tic_tac_toe->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->tic_tac_toe->Location = System::Drawing::Point(0, 69);
			this->tic_tac_toe->Name = L"tic_tac_toe";
			this->tic_tac_toe->Size = System::Drawing::Size(131, 22);
			this->tic_tac_toe->TabIndex = 2;
			this->tic_tac_toe->Text = L"tic_tac_toe";
			this->tic_tac_toe->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// logo
			// 
			this->logo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logo.BackgroundImage")));
			this->logo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->logo->Dock = System::Windows::Forms::DockStyle::Top;
			this->logo->Location = System::Drawing::Point(0, 0);
			this->logo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->logo->Name = L"logo";
			this->logo->Size = System::Drawing::Size(131, 69);
			this->logo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->logo->TabIndex = 0;
			this->logo->TabStop = false;
			// 
			// title_bar
			// 
			this->title_bar->BackColor = System::Drawing::Color::Gray;
			this->title_bar->Controls->Add(this->login_title_bar);
			this->title_bar->Controls->Add(this->Home_page);
			this->title_bar->Controls->Add(this->choose_level_title);
			this->title_bar->Controls->Add(this->profile_title_bar);
			this->title_bar->Controls->Add(this->during_game);
			this->title_bar->Controls->Add(this->logo_panel);
			this->title_bar->Controls->Add(this->control_icons);
			this->title_bar->Controls->Add(this->sign_in_title_bar);
			this->title_bar->Dock = System::Windows::Forms::DockStyle::Top;
			this->title_bar->Location = System::Drawing::Point(0, 0);
			this->title_bar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->title_bar->Name = L"title_bar";
			this->title_bar->Size = System::Drawing::Size(1135, 91);
			this->title_bar->TabIndex = 0;
			// 
			// Home_page
			// 
			this->Home_page->Controls->Add(this->pictureBox3);
			this->Home_page->Controls->Add(this->label7);
			this->Home_page->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Home_page->Location = System::Drawing::Point(131, 0);
			this->Home_page->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Home_page->Name = L"Home_page";
			this->Home_page->Size = System::Drawing::Size(743, 91);
			this->Home_page->TabIndex = 7;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.BackgroundImage")));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox3->Location = System::Drawing::Point(180, 9);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(120, 76);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 6;
			this->pictureBox3->TabStop = false;
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(284, 26);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(201, 59);
			this->label7->TabIndex = 5;
			this->label7->Text = L"Home page";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label7->Click += gcnew System::EventHandler(this, &MyForm::label7_Click);
			// 
			// choose_level_title
			// 
			this->choose_level_title->Controls->Add(this->label12);
			this->choose_level_title->Dock = System::Windows::Forms::DockStyle::Fill;
			this->choose_level_title->Location = System::Drawing::Point(131, 0);
			this->choose_level_title->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->choose_level_title->Name = L"choose_level_title";
			this->choose_level_title->Size = System::Drawing::Size(743, 91);
			this->choose_level_title->TabIndex = 10;
			// 
			// label12
			// 
			this->label12->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::White;
			this->label12->Location = System::Drawing::Point(297, 15);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(252, 59);
			this->label12->TabIndex = 5;
			this->label12->Text = L"choose the level ";
			this->label12->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// login_title_bar
			// 
			this->login_title_bar->Controls->Add(this->pictureBox2);
			this->login_title_bar->Controls->Add(this->label1);
			this->login_title_bar->Dock = System::Windows::Forms::DockStyle::Fill;
			this->login_title_bar->Location = System::Drawing::Point(131, 0);
			this->login_title_bar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->login_title_bar->Name = L"login_title_bar";
			this->login_title_bar->Size = System::Drawing::Size(743, 91);
			this->login_title_bar->TabIndex = 5;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox2->Location = System::Drawing::Point(196, 11);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(120, 76);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 6;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &MyForm::pictureBox2_Click);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(308, 16);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(201, 59);
			this->label1->TabIndex = 5;
			this->label1->Text = L"Login page";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// profile_title_bar
			// 
			this->profile_title_bar->Controls->Add(this->label11);
			this->profile_title_bar->Dock = System::Windows::Forms::DockStyle::Fill;
			this->profile_title_bar->Location = System::Drawing::Point(131, 0);
			this->profile_title_bar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->profile_title_bar->Name = L"profile_title_bar";
			this->profile_title_bar->Size = System::Drawing::Size(743, 91);
			this->profile_title_bar->TabIndex = 9;
			// 
			// label11
			// 
			this->label11->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::Snow;
			this->label11->Location = System::Drawing::Point(89, 14);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(543, 57);
			this->label11->TabIndex = 0;
			this->label11->Text = L"player profile";
			this->label11->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// during_game
			// 
			this->during_game->Controls->Add(this->label10);
			this->during_game->Dock = System::Windows::Forms::DockStyle::Fill;
			this->during_game->Location = System::Drawing::Point(131, 0);
			this->during_game->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->during_game->Name = L"during_game";
			this->during_game->Size = System::Drawing::Size(743, 91);
			this->during_game->TabIndex = 8;
			// 
			// label10
			// 
			this->label10->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::Snow;
			this->label10->Location = System::Drawing::Point(89, 14);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(543, 57);
			this->label10->TabIndex = 0;
			this->label10->Text = L"tic_tac_toe game";
			this->label10->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// sign_in_title_bar
			// 
			this->sign_in_title_bar->Controls->Add(this->pictureBox1);
			this->sign_in_title_bar->Controls->Add(this->label2);
			this->sign_in_title_bar->Dock = System::Windows::Forms::DockStyle::Fill;
			this->sign_in_title_bar->Location = System::Drawing::Point(0, 0);
			this->sign_in_title_bar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->sign_in_title_bar->Name = L"sign_in_title_bar";
			this->sign_in_title_bar->Size = System::Drawing::Size(1135, 91);
			this->sign_in_title_bar->TabIndex = 6;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox1->Location = System::Drawing::Point(393, 7);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(123, 76);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(512, 16);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(201, 59);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Sign in page";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1135, 643);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->title_bar);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->panel1->ResumeLayout(false);
			this->choose_level_page->ResumeLayout(false);
			this->game_page->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->profile_page->ResumeLayout(false);
			this->profile_page->PerformLayout();
			this->group_buttons->ResumeLayout(false);
			this->x_o_grid_page->ResumeLayout(false);
			this->data_grid->ResumeLayout(false);
			this->user_data->ResumeLayout(false);
			this->user_2_data->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			this->user_1_data->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			this->exit_reset->ResumeLayout(false);
			this->login_main_page->ResumeLayout(false);
			this->login_main_page->PerformLayout();
			this->sign_in_main_page->ResumeLayout(false);
			this->sign_in_main_page->PerformLayout();
			this->control_icons->ResumeLayout(false);
			this->logo_panel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo))->EndInit();
			this->title_bar->ResumeLayout(false);
			this->Home_page->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->choose_level_title->ResumeLayout(false);
			this->login_title_bar->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->profile_title_bar->ResumeLayout(false);
			this->during_game->ResumeLayout(false);
			this->sign_in_title_bar->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}


#pragma endregion
		// -------------------------here is the algorithm of the game-----------------------------
		void Button_Click(Object^ sender, EventArgs^ e)
		{
			Button^ clickedButton = dynamic_cast<Button^>(sender); // Get the button that was clicked
			if (clickedButton != nullptr) 
			{
				//here write the algorithm for x_o game
				
				static bool x_o = 1; //  ( 1->X 0->o)variable to know we will writ x or o (it is static variable)
				if (clickedButton->Text == "")
					clickedButton->Text = x_o ? "X" : "O";
				x_o = !x_o;
				char check_win = check_winner(buttonArray);
				if (check_win == 'X')
				{
					MessageBox::Show("      Congratiolations! \n  Player (X) win !", "tic_tac_toe");
					/* Hazem Edit store game details in Server */
					String^ datastore = SerializeButtonArray(buttonArray);
					StoreButtonArrayState(datastore);
					/*******************************************/
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							buttonArray[i, j]->Text = "";
						}
					}
					return;
				}
				else if (check_win == 'O')
				{
					MessageBox::Show("      Congratiolations! \n  Player (O) win !", "tic_tac_toe");
					/* Hazem Edit store game details in Server */
					String^ datastore = SerializeButtonArray(buttonArray);
					StoreButtonArrayState(datastore);

					/*******************************************/


					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							buttonArray[i, j]->Text = "";
						}
					}
					return;
				}
				else if (check_win == 'd')
				{
					MessageBox::Show("        DraW! \n   Two players are drawn !", "tic_tac_toe");

					/* Hazem Edit store game details in Server */
					String^ datastore = SerializeButtonArray(buttonArray);
					StoreButtonArrayState(datastore);

					/*******************************************/


					/* Hazem Edit this code must be run when tie happen */
					String^ username = loginUser->Username; // Replace with the current username

					try {
						String^ connString = "Data Source=TicTacToeData.db;Version=3;";
						SQLiteConnection^ sqlConn = gcnew SQLiteConnection(connString);

						sqlConn->Open();

						// Define the SQL query to select the current number of wins for the user
						String^ sqlQuery = "SELECT Tie FROM Users WHERE User_Name=@username;";
						SQLiteCommand^ command = gcnew SQLiteCommand(sqlQuery, sqlConn);
						command->Parameters->AddWithValue("@username", username);

						// Execute the query and get the result (the current number of wins)
						Object^ result = command->ExecuteScalar();

						// Check if the result is not null and increment it by one
						if (result != nullptr) {
							int currentTies = Convert::ToInt32(result);
							currentTies++;


							// Define the SQL query to update the number of wins for the user
							sqlQuery = "UPDATE Users SET Tie=@tie WHERE User_Name=@username;";
							command = gcnew SQLiteCommand(sqlQuery, sqlConn);
							command->Parameters->AddWithValue("@tie", currentTies);
							command->Parameters->AddWithValue("@username", username);
							// Execute the update command
							command->ExecuteNonQuery();
						}
						loginUser->IncrementTie();
						// Update the displayed Wins count
						label_tie->Text = "Tie = " + loginUser->Tie;
						// Close the connection
						sqlConn->Close();
					}
					catch (SQLiteException^ ex) {
						// Handle any exceptions that may occur
						MessageBox::Show("Failed to update number of Tie: " + ex->Message, "Database Error");
					}


					/****************************************************/
					for (int i = 0; i < 3; i++)
					{
						for (int j = 0; j < 3; j++)
						{
							buttonArray[i, j]->Text = "";
						}
					}
					return;
				}
				if (Ai_mode == 1)
				{

					//write here the Ai algorithm
					//buttonArray[x,y]->Text = "X" ,"O"

				}
			}
		}
		


	private: System::Void minimize_Click(System::Object^ sender, System::EventArgs^ e) {
		this->WindowState = System::Windows::Forms::FormWindowState::Minimized;

	}
	private: System::Void close_Click(System::Object^ sender, System::EventArgs^ e) {
		Environment::Exit(0);
	}
	private: System::Void max_min_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->WindowState == FormWindowState::Normal)
		{
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
		}
		else
		{
			this->WindowState = System::Windows::Forms::FormWindowState::Normal;
		}

	}

	private: System::Void home_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void title_sign_up_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void sign_in_main_page_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void see_password_login_Click(System::Object^ sender, System::EventArgs^ e) {
		if (password_login->PasswordChar == '*')
		{
			password_login->PasswordChar = 0;
		}
		else
		{
			password_login->PasswordChar = '*';
		}
	}
	private: System::Void sign_up_button_Click(System::Object^ sender, System::EventArgs^ e) {

		user_name_sign_in->Clear();
		check_password->Clear();
		password_sign_in->Clear();
		user_name_login->Clear();
		password_login->Clear();
		sign_in_main_page->BringToFront();
		sign_in_title_bar->BringToFront();
	}
		   /* Register account */
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ name = user_name_sign_in->Text;
		String^ Pass = password_sign_in->Text;
		String^ confPass = check_password->Text;

		if (name->Length == 0 || Pass->Length == 0 || confPass->Length == 0) {
			MessageBox::Show("Missing data", "UnValid Create", MessageBoxButtons::OK);
		}
		else if (String::Compare(Pass, confPass) != 0) {
			MessageBox::Show("Unmatched Password", "Password Error", MessageBoxButtons::OK);
		} 
		else{
			String^ connString = "Data Source=TicTacToeData.db;Version=3;";

			try {
				// Create a new SQLite connection
				SQLiteConnection^ sqlConn = gcnew SQLiteConnection(connString);

				// Open the connection
				sqlConn->Open();

				// Define the SQL query for inserting data into the Users table
				String^ sqlQuery = "INSERT INTO Users (User_Name, Password, Win, Loss, Tie) VALUES (@username, @pass , 0, 0, 0);";

				// Create a SQLite command with the SQL query and connection
				SQLiteCommand^ command = gcnew SQLiteCommand(sqlQuery, sqlConn);

				// Add parameters to the command
				command->Parameters->AddWithValue("@username", name);
				command->Parameters->AddWithValue("@pass", Pass);

				// Execute the SQL command
				command->ExecuteNonQuery();

				// Close the connection
				sqlConn->Close();

				// Optionally, perform additional actions here after successful insertion
				MessageBox::Show(" Welcome in our tic_tac_toe game\n your acount has been added Successfully.", "Registration Success");
				login_main_page->BringToFront();
				login_title_bar->BringToFront();
			}
			catch (SQLiteException^ ex) {
				// Display an error message if connection or execution fails
				MessageBox::Show("Error: " + ex->Message, "Database Error", MessageBoxButtons::OK);
			}
		}
		user_name_sign_in->Clear();
		check_password->Clear();
		password_sign_in->Clear();
	}
	private: System::Void see_password_sign_in_Click(System::Object^ sender, System::EventArgs^ e) {
		if (password_sign_in->PasswordChar == '*')
		{
			password_sign_in->PasswordChar = 0;
		}
		else
		{
			password_sign_in->PasswordChar = '*';
		}
	}
	private: System::Void see_password_check_Click(System::Object^ sender, System::EventArgs^ e) {
		if (check_password->PasswordChar == '*')
		{
			check_password->PasswordChar = 0;
		}
		else
		{
			check_password->PasswordChar = '*';
		}
	}
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void one_player_Click(System::Object^ sender, System::EventArgs^ e)
	{
		/*Morad edit for adding page to choose the level*/
		//x_o_grid_page->BringToFront();
		//during_game->BringToFront();
		//Ai_mode = 1;
		choose_level_page->BringToFront();
		choose_level_title->BringToFront();
	}
	private: System::Void two_players_Click(System::Object^ sender, System::EventArgs^ e) {
		Ai_mode = 0; // two player mode
		x_o_grid_page->BringToFront();
		during_game->BringToFront();

	}
	private: System::Void logout_Click(System::Object^ sender, System::EventArgs^ e) {
		
		/* Hazem edit */
		loginUser = nullptr;
		/**************/

		login_main_page->BringToFront();
		login_title_bar->BringToFront();
	}
		   /* Login Code */
	private: System::Void login_button_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ User_Name = user_name_login->Text;
		String^ Password = password_login->Text;

		if (User_Name->Length == 0 || Password->Length == 0) {
			//Empty inputs
			MessageBox::Show("Empty Username or Password", "Error");
		}
		else {
			String^ connString = "Data Source=TicTacToeData.db;Version=3;";

			try {
				SQLiteConnection^ sqlConn = gcnew SQLiteConnection(connString);
				sqlConn->Open();

				// Define the SQL query to select user by username and password
				String^ sqlQuery = "SELECT * FROM Users WHERE User_Name=@username AND Password=@pwd;";

				// Create a SQLite command with the SQL query and connection
				SQLiteCommand^ command = gcnew SQLiteCommand(sqlQuery, sqlConn);

				// Add parameters to the command
				command->Parameters->AddWithValue("@username", User_Name);
				command->Parameters->AddWithValue("@pwd", Password);

				// Execute the SQL command and get the data reader
				SQLiteDataReader^ reader = command->ExecuteReader();

				if (reader->Read()) {
					// Username and password are correct
					loginUser = gcnew User;
					loginUser->Username = reader->GetString(0);
					loginUser->Password = reader->GetString(1);
					loginUser->Wins = reader->GetInt32(2);
					loginUser->Loss = reader->GetInt32(3);
					loginUser->Tie = reader->GetInt32(4);

					//go to game page
					game_page->BringToFront();
					Home_page->BringToFront();
				}
				else {
					MessageBox::Show("Username or password is incorrect", "Invalid account", MessageBoxButtons::OK);
				}
				// Close the reader and connection
				reader->Close();
				sqlConn->Close();
			}
			catch (SQLiteException^ ex) {
				// Display an error message if connection or execution fails
				MessageBox::Show("Failed to connect database: " + ex->Message, "Login Error");
			}
		}
		user_name_login->Clear();
		password_login->Clear();
	}
	private: System::Void panel5_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void panel7_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void exit_Click(System::Object^ sender, System::EventArgs^ e) {
		game_page->BringToFront();
		Home_page->BringToFront();
	}
	private: System::Void reset_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {
	}
private: System::Void label12_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label11_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void grid_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}



private: System::Void exit_Click_1(System::Object^ sender, System::EventArgs^ e) {
	game_page->BringToFront();
	Home_page->BringToFront();
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			buttonArray[i, j]->Text = "";
		}
	}
}

private: System::Void reset_Click_1(System::Object^ sender, System::EventArgs^ e) {

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{

			buttonArray[i, j]->Text = "";
		}
	}
}
private: System::Void history_Click(System::Object^ sender, System::EventArgs^ e) {
	label_name->Text = "Name : " + loginUser->Username;
	label_win->Text = "Wins = " + loginUser->Wins;
	label_loss->Text = "Loss = " + loginUser->Loss;
	label_tie->Text = "Tie = " + loginUser->Tie;
	profile_page->BringToFront();
	profile_title_bar->BringToFront();
}
private: System::Void back_to_home_Click(System::Object^ sender, System::EventArgs^ e) {
	game_page->BringToFront();
	Home_page->BringToFront();
}
private: System::Void delete_account_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		// Establish the connection string
		String^ connString = "Data Source=TicTacToeData.db;Version=3;";
		SQLiteConnection^ sqlConn = gcnew SQLiteConnection(connString);

		// Open the database connection
		sqlConn->Open();

		// Construct the SQL DELETE statement to delete the account
		String^ sqlQuery = "DELETE FROM Users WHERE User_Name = @username;";

		// Create a SQLite command with the SQL query and connection
		SQLiteCommand^ command = gcnew SQLiteCommand(sqlQuery, sqlConn);

		// Add parameters to the command
		command->Parameters->AddWithValue("@username", loginUser->Username);

		// Execute the SQL command
		command->ExecuteNonQuery();

		// Close the database connection
		sqlConn->Close();

		// Optionally, clear the loginUser object or perform any other cleanup tasks
		loginUser = nullptr;

		/*Return to login page*/
		login_main_page->BringToFront();
		login_title_bar->BringToFront();
		/**********************/

		// Display a message indicating successful account deletion
		MessageBox::Show("Account deleted successfully", "Success", MessageBoxButtons::OK);
		
	}
	catch (SQLiteException^ ex) {
		// Display an error message if the database operation fails
		MessageBox::Show("Failed to delete account: " + ex->Message, "Error", MessageBoxButtons::OK);
	}
}
private: System::Void change_pass_Click(System::Object^ sender, System::EventArgs^ e) {
	tic::CheckPassword checkform(loginUser);
	checkform.ShowDialog();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: int currentIndex = 0; // Initialize the index to 0

private: System::Void next_game_Click(System::Object^ sender, System::EventArgs^ e) {
	try {
		String^ connString = "Data Source=TicTacToeData.db;Version=3;";
		SQLiteConnection^ sqlConn = gcnew SQLiteConnection(connString);
		sqlConn->Open();

		// Define the SQL query to retrieve the ButtonState
		String^ sqlQuery = "SELECT ButtonState FROM Users WHERE User_Name = @username;";
		SQLiteCommand^ command = gcnew SQLiteCommand(sqlQuery, sqlConn);
		command->Parameters->AddWithValue("@username", loginUser->Username);

		// Execute the query and get the result (the serialized button state)
		Object^ result = command->ExecuteScalar();

		if (result != DBNull::Value) {
			String^ buttonState = safe_cast<String^>(result);

			// Check if buttonState is not null or empty
			if (!String::IsNullOrEmpty(buttonState)) {
				// Extract the substring representing a single game
				String^ game = buttonState->Substring(currentIndex, 9);

				// Display the game on the appropriate buttons
				i0->Text = game[0].ToString();
				i1->Text = game[1].ToString();
				i2->Text = game[2].ToString();
				i3->Text = game[3].ToString();
				i4->Text = game[4].ToString();
				i5->Text = game[5].ToString();
				i6->Text = game[6].ToString();
				i7->Text = game[7].ToString();
				i8->Text = game[8].ToString();

				// Increment the index for the next game
				currentIndex += 9;

				// Wrap around if currentIndex exceeds the length of buttonState
				if (currentIndex >= buttonState->Length) {
					currentIndex = 0; // Return to the first game
				}
			}
			else {
				// Handle the case where buttonState is null or empty
			}
		}
		else {
			// Handle the case where result is DBNull
		}


		sqlConn->Close();
	}
	catch (SQLiteException^ ex) {
		// Handle exception
		MessageBox::Show("Couldn't retrieve Button state: " + ex->Message, "Retrieve Button Error", MessageBoxButtons::OK);
	}
}
private: System::Void i5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button13_Click(System::Object^ sender, System::EventArgs^ e) {
	game_page->BringToFront();
	Home_page->BringToFront();

}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button15_Click(System::Object^ sender, System::EventArgs^ e) {
	x_o_grid_page->BringToFront();
    during_game->BringToFront();
}
private: System::Void button14_Click(System::Object^ sender, System::EventArgs^ e) {
     x_o_grid_page->BringToFront();
     during_game->BringToFront();
}
private: System::Void button3_Click_1(System::Object^ sender, System::EventArgs^ e) {
	 x_o_grid_page->BringToFront();
     during_game->BringToFront();
}
};
}

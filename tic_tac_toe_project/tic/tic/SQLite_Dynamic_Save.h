#pragma once

using namespace System;
using namespace System::Data::SQLite;
//using namespace System::Text;

String^ SerializeButtonArray(array<Button^, 2>^ buttonArray)
{
    String^ serializedData = "";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            serializedData += buttonArray[i, j]->Text;
        }
    }
    return serializedData;
}

/*
String^ SerializeButtonArray(array<Button^, 2>^ buttonArray)
{
    StringBuilder^ sb = gcnew StringBuilder();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sb->Append(buttonArray[i, j]->Text);
            sb->Append(","); // Separate button values by comma
        }
    }
    return sb->ToString();
}
*/
void StoreButtonArrayState(String^ serializedData)
{
    String^ connString = "Data Source=TicTacToeData.db;Version=3;";
    try {
        SQLiteConnection^ sqlConn = gcnew SQLiteConnection(connString);
        sqlConn->Open();
        String^ sqlQuery = "INSERT INTO Users (ButtonState) VALUES (@data);";
        SQLiteCommand^ command = gcnew SQLiteCommand(sqlQuery, sqlConn);
        command->Parameters->AddWithValue("@data", serializedData);
        command->ExecuteNonQuery();
        sqlConn->Close();
    }
    catch (SQLiteException^ ex) {
        // Handle exception
        MessageBox::Show("Couldn't save Button state","Store Button Error",MessageBoxButtons::OK);
    }
}

/*
void RestoreButtonArrayState(array<Button^, 2>^ buttonArray)
{
    String^ connString = "Data Source=TicTacToeData.db;Version=3;";
    try {
        SQLiteConnection^ sqlConn = gcnew SQLiteConnection(connString);
        sqlConn->Open();
        String^ sqlQuery = "SELECT ButtonState FROM Users;";
        SQLiteCommand^ command = gcnew SQLiteCommand(sqlQuery, sqlConn);
        SQLiteDataReader^ reader = command->ExecuteReader();
        if (reader->Read()) {
            String^ serializedData = safe_cast<String^>(reader["ButtonState"]);
            array<String^>^ buttonValues = serializedData->Split(',');
            int index = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    buttonArray[i, j]->Text = buttonValues[index++];
                }
            }
        }
        reader->Close();
        sqlConn->Close();
    }
    catch (SQLiteException^ ex) {
        // Handle exception
        MessageBox::Show("Couldn't restore Button state", "Restore Button Error", MessageBoxButtons::OK);
    }
}

void PrintButtonArrayState(array<Button^, 2>^ buttonArray)
{
    StringBuilder^ sb = gcnew StringBuilder();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            sb->Append(buttonArray[i, j]->Text);
            sb->Append(" "); // Separate button values by space
        }
        sb->AppendLine(); // Newline after each row
    }
    MessageBox::Show(sb->ToString(), "Button State");
}

 
void Button_Click(Object^ sender, EventArgs^ e)
{
    // Button click event code...

    // Serialize button array state
    String^ serializedData = SerializeButtonArray(buttonArray);

    // Store serialized data in the database
    StoreButtonArrayState(serializedData);
}
*/

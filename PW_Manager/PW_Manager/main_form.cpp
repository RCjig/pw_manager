#include "stdafx.h"

System::Void PW_Manager::main_form::button1_Click(System::Object^  sender, System::EventArgs^  e) {
	sqlite3 * db;
	int error = sqlite3_open("pw.db", &db);
	if (!error) {
		this->Hide();

		PW_Manager::second_form object_name_second;
		object_name_second.ShowDialog();
		
		this->Show();
		sqlite3_close(db);
	}
}

System::Void PW_Manager::main_form::button2_Click(System::Object^  sender, System::EventArgs^  e) {
	sqlite3 * db;
	int error = sqlite3_open("pw.db", &db);
	if (!error) {
		this->Hide();

		PW_Manager::third_form retrieve_form;
		retrieve_form.ShowDialog();

		this->Show();
		sqlite3_close(db);
	}
}

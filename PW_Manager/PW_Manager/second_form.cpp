#include "stdafx.h"

using namespace std;

System::Void PW_Manager::second_form::button1_Click(System::Object^  sender, System::EventArgs^  e) {
	sqlite3 * db;
	int error = sqlite3_open("pw.db", &db);
	if (!error && label2->Text != "Yes") {
		
		msclr::interop::marshal_context contextSite;
		string site = contextSite.marshal_as<string>(textBox1->Text);

		msclr::interop::marshal_context contextUser;
		string user = contextUser.marshal_as<string>(textBox2->Text);

		msclr::interop::marshal_context contextPass;
		string pass = contextPass.marshal_as<string>(textBox3->Text);

		msclr::interop::marshal_context contextKey;
		char key = (contextKey.marshal_as<string>(textBox4->Text)).at(0);

		SiteData insert(site, user, pass, key);
		insert.insertPass(db);

		label2->Text = "Yes";

		sqlite3_close(db);
	}
}
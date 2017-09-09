#include "stdafx.h"

using namespace std;

System::Void PW_Manager::third_form::button1_Click(System::Object^  sender, System::EventArgs^  e) {
	sqlite3 * db;
	int error = sqlite3_open("pw.db", &db);
	if (!error && label2->Text != "Yes") {

		// convert from string ^ to string for use with SiteData class
		msclr::interop::marshal_context contextSite;
		string site = contextSite.marshal_as<string>(textBox1->Text);

		msclr::interop::marshal_context contextUser;
		string user = contextUser.marshal_as<string>(textBox2->Text);

		msclr::interop::marshal_context contextKey;
		char key = (contextKey.marshal_as<string>(textBox3->Text)).at(0);

		SiteData retrieve(site, user, db);
	
		// convert final string back to string ^ for display
		string convertStr = retrieve.getPassword(key);
		label2->Text = gcnew String(convertStr.c_str());

		sqlite3_close(db);
	}
}
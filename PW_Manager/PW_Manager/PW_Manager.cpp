// PW_Manager.cpp : main project file.

#include "stdafx.h"

using namespace System;
using namespace System::Windows::Forms;

int main(array<System::String ^> ^args)
{
	//sqlite3 * db;
	//int error = sqlite3_open("pw.db", &db);

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PW_Manager::main_form nameObjectForm;
	Application::Run(%nameObjectForm);

	//sqlite3_close(db);
	return 0;
}

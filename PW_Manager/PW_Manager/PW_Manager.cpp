// PW_Manager.cpp : main project file.

#include "stdafx.h"

using namespace System;
using namespace System::Windows::Forms;

int main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	PW_Manager::main_form nameObjectForm;
	Application::Run(%nameObjectForm);

	return 0;
}

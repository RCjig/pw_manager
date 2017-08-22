#include <python2.7/Python.h>
#include <sqlite3.h>
#include <fstream>
#include <iostream>
#include "SiteData.h"

using namespace std;

int main(int argc, char **argv) {

  SiteData tester("test", "ing");
  string orig = "abcxyz";
  cout << "Original = " << orig << endl;
  string test = tester.encodePassword(orig, 'x');
  cout << "Encrypted = " << test << endl;
  string test2 = tester.getPassword(test, 'x');
  cout << "Unencrypted = " << test2 << endl;
  

	Py_Initialize();

  // create database if not exists
  if (!ifstream("pw.db")) {
		FILE * pyFile = fopen("db_create.py", "r");
		PyRun_SimpleFile(pyFile, "db_create.py");
		fclose(pyFile);
    cout << "Created database" << endl;
  }

  // open up and connect to database
  sqlite3 * db;
  int error;
  error = sqlite3_open("pw.db", &db);

  if (error) {
    cerr << "Couldn't open database" << endl;
  }

  else {
    cout << "Opened database" << endl;
    sqlite3_close(db);
  }

	Py_Finalize();
	return 0;
}

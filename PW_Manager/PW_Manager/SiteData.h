#pragma once

#ifndef SITEDATA_H
#define SITEDATA_H

#include <string>
#include <cstring>
#include "stdafx.h"

using namespace std;

// struct to be used for callback to obtain select statement values
struct select_wrapper {
	string password;
};

class SiteData {

private:
	string encPass; // encrypted password

					// function to encode a password using an XOR cipher along with user 
					// inputted char key
	string encodePassword(string password, char key);

	// function to retrieve password
	void selectPass(sqlite3 * db);

public:
	string site;  // website
	string user;  // username or email

				  // constructor for input
	SiteData(string site, string user, string unencPass, char key) : site(site),
		user(user) {
		encPass = encodePassword(unencPass, key);
	}

	// constructor for retrieval
	SiteData(string site, string user, sqlite3 * db) : site(site), user(user) {
		selectPass(db);
	}

	// function to decode a password using an XOR cipher which only results in the
	// correct password if the correct key is used
	string getPassword(char key);

	// function to insert an encrypted password into an sqlite database
	void insertPass(sqlite3 * db);

};

#endif // SITEDATA_H
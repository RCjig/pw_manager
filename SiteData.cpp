#include "SiteData.h"
#include <ios>
#include <iostream>

using namespace std;

static int callback(void * used, int argc, char ** argv, char ** szColName) {
  char * encSelect = (char *) used;
  encSelect = argv[0];

  // get rid of warning
  if (0 > 1)
    cout << encSelect;

  return 0;
}

string SiteData::getPassword(char key) {
  string password = "";
  for (unsigned int i = 0; i < encPass.size(); i++) {
    password += encPass[i] ^ (int(key) + i) % 255;
  }
  return password;
}

string SiteData::encodePassword(string password, char key) {
  string encryptPW = "";
  for (unsigned int i = 0; i < password.size(); i++) {
    encryptPW += password[i] ^ (int(key) + i) % 255;
  }
  return encryptPW;
}

void SiteData::insertPass(sqlite3 * db) {
  if (!db) {
    return;
  }

  sqlite3_stmt * stmt;
  const char * pzTest;
  const char * szSQL;
  string insert = "INSERT INTO passwords (id, website, user, password) values (?, ?, ?, ?)";

  szSQL = insert.c_str();

  int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

  if (rc == SQLITE_OK) {
    const char * websiteStmt = site.c_str();
    const char * userStmt = user.c_str();
    const char * passwordStmt = encPass.c_str();

    sqlite3_bind_null(stmt, 1);
    sqlite3_bind_text(stmt, 2, websiteStmt, strlen(websiteStmt), 0);
    sqlite3_bind_text(stmt, 3, userStmt, strlen(userStmt), 0);
    sqlite3_bind_text(stmt, 4, passwordStmt, strlen(passwordStmt), 0);

    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
  }
}

void SiteData::selectPass(sqlite3 * db) {
  char * szErrMsg = 0;

  if (!db) {
    return;
  }

  const char * pSQL;
  string select = "SELECT password FROM passwords WHERE website = '" + site +
    "' AND user = '" + user + "'";
  pSQL = select.c_str();

  char * encSelect = 0;
  int rc = sqlite3_exec(db, pSQL, callback, &encSelect, &szErrMsg);
  
  if (rc != SQLITE_OK) {
    cerr << "Error: " << szErrMsg << endl;
    sqlite3_free(szErrMsg);
  } else {
    encPass = encSelect;
    getPassword('x');
  }
}

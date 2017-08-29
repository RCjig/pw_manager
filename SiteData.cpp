#include "SiteData.h"

using namespace std;

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

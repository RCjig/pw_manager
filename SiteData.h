#ifndef SITEDATA_H
#define SITEDATA_H

#include <string>
#include <cstring>
#include <sqlite3.h>

using namespace std;

struct select_wrapper {
  string password;
};

class SiteData {

  private:
    string encPass;

    string encodePassword(string password, char key);
    
    void selectPass(sqlite3 * db);

  public:
    string site;
    string user;

    SiteData(string site, string user, string unencPass, char key) : site(site), 
      user(user) {
      encPass = encodePassword(unencPass, key);
    }

    SiteData(string site, string user, sqlite3 * db) : site(site), user(user) {
      selectPass(db);
    }

    string getPassword(char key);

    void insertPass(sqlite3 * db);

};

#endif // SITEDATA_H

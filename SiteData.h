#ifndef SITEDATA_H
#define SITEDATA_H

#include <string>

using namespace std;

class SiteData {

  private:
    string encPass;

    string encodePassword(string password, char key);

  public:
    string site;
    string user;

    SiteData(string site, string user, string unencPass, char key) : site(site), 
      user(user) {
      encPass = encodePassword(unencPass, key);
    }

    string getPassword(char key);

};

#endif // SITEDATA_H

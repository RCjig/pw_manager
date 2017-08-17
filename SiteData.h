#ifndef SITEDATA_H
#define SITEDATA_H

#include <string>

using namespace std;

class SiteData {

  private:
    int password;

    string getPassword();

  public:
    string site;
    string user;

    SiteData(string site, string user, int password = -1) : site(site), 
      user(user) {};

    string encodePassword(string txtPassword);

    string encodeChar(int currChar);

};

#endif // SITEDATA_H

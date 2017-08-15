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

    void encodePassword(string txtPassword);

};

#endif // SITEDATA_H

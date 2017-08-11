#ifndef SITEDATA_H
#define SITEDATA_H

#include <string>

using namespace std;

class SiteData {

  public:
    string site;
    string user;

    SiteData(string site, string user, long password = -1) : site(site), 
      user(user) {};

    string getPassword();

  private:
    long password;

};

#endif // SITEDATA_H

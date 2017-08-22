#ifndef SITEDATA_H
#define SITEDATA_H

#include <string>

using namespace std;

class SiteData {

  private:
    int password1;


  public:
    string site;
    string user;

    SiteData(string site, string user, int password1 = -1) : site(site), 
      user(user) {};

    string getPassword(string encryptPW, char key);

    string encodePassword(string password, char key);

};

#endif // SITEDATA_H

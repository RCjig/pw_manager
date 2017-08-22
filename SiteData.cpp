#include "SiteData.h"

using namespace std;

string SiteData::getPassword(string encryptPW, char key) {
  string password = "";
  for (unsigned int i = 0; i < encryptPW.size(); i++) {
    password += encryptPW[i] ^ (int(key) + i) % 255;
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

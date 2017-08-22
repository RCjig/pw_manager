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

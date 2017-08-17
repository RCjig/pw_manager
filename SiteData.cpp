#include "SiteData.h"

using namespace std;

string SiteData::getPassword() {
  string txtPassword;
  
  return txtPassword;
}

string SiteData::encodePassword(string txtPassword) {
  string returnVal = "";
  for (unsigned int i = 0; i < txtPassword.length(); i++) {
    returnVal += encodeChar((int)txtPassword.at(i));
  }
  return returnVal;
}

string SiteData::encodeChar(int currChar) {
  string retVal = to_string(currChar);

  if (currChar < 10) {
    retVal = "00" + retVal;
  } else if (currChar < 100) {
    retVal = "0" + retVal;
  }

  return retVal;
}

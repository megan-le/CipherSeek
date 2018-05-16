#include <iostream>
#include <string>
#include <map>

#include "dvorak.h"

using namespace std;

string dvorak(string text, bool encrypt){
  string answer = "";
  map<char, char> table;
  string qwerty = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?";
  string dvorak = "`1234567890[]',.pyfgcrl/=\\aoeuidhtns-;qjkxbmwvz~!@#$%^&*(){}\"<>PYFGCRL?+|AOEUIDHTNS_:QJKXBMWVZ";
  if(encrypt){
      for(int i = 0; i < qwerty.length(); i++){
         table.insert({qwerty.at(i), dvorak.at(i)});
      }
  }else{
      for(int j = 0; j < qwerty.length(); j++){
         table.insert({dvorak.at(j), qwerty.at(j)});
      }
  }
  for(int k = 0; k < text.length(); k++){
      if(text.at(k) == ' '){
         answer += ' ';
      }else{
         answer += table.at(text.at(k));
      }
  }
  return answer;
}
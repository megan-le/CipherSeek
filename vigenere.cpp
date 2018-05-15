#include <iostream>
#include <string>
#include <vector>

#include "vigenere.h"

using namespace std;

string vigenere(string text, string keyword, bool encrypt){
  string punctuation = ".\"\',;:?() ";
  vector <int> lowercase;
  string answer = "";
  string fullKey;
  for(int i = 0, j = 0; i < text.length(); i++, j++){
    if(j == keyword.length()){
      j = 0;
    }
    fullKey += toupper(keyword.at(j));
  }
  
  for(int k = 0, j = 0; k < text.length(); k++, j++){
    if(islower(text.at(k))){
      lowercase.push_back(k);
      text.at(k) = toupper(text.at(k));
    }
    if(punctuation.find(text.at(k)) != std::string::npos){
      answer += text.at(k);
      j--;
    }else{
      if(encrypt){
        answer += ((text.at(k) + fullKey.at(j)) % 26) + 'A';
      }else if (!encrypt){
        answer += ((text.at(k) - fullKey.at(j) + 26) % 26) + 'A';
      }
      }
    for(int l = 0; l < lowercase.size(); l++){
      answer.at(lowercase.at(l)) = tolower(answer.at(lowercase.at(l)));
    }
  }
  return answer;
}


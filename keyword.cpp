#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "keyword.h"

using namespace std;

string keyword(string text, string keyword, bool encrypt){
  string punctuation = ".\"\',;:?() ";
  vector <int> uppercase;
  string answer = "";
  //generate bottom of substitution table
  string bottom = "";
  string top = "abcdefghijklmnopqrstuvwxyz";
  map<char, char> table;
  for(int i = 0; i < keyword.length(); i++){
    if(!(bottom.find(keyword.at(i)) != std::string::npos)){
      bottom += keyword.at(i);
    }
  }
  int holder = bottom.length();
  for(int j = 0; j < top.length(); j++){
    if(!(bottom.find(top.at(j)) != std::string::npos)){
      bottom += top.at(j);
    }
  }
  for(int k = 0; k < 25; k++){
   if(encrypt){
      table.insert({top.at(k), bottom.at(k)});
   }else{
      table.insert({bottom.at(k), top.at(k)});
   }
  }
  for(int l = 0; l < text.length(); l++){
   if(isupper(text.at(l))){
        uppercase.push_back(l);
        text.at(l) = tolower(text.at(l));
   }
   if(punctuation.find(text.at(l)) != std::string::npos){
      answer += text.at(l);
   }else{
       answer += table.at(text.at(l));
   }   
  }
  for(int m = 0; m < uppercase.size(); m++){
      answer.at(uppercase.at(m)) = toupper(answer.at(uppercase.at(m)));
    }
  return answer;
}



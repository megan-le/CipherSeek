#include <iostream>
#include <string>
#include <map>
#include <vector>

#include "atbash.h"

using namespace std;

string atbash(string text){
  vector <int> uppercase;
  string punctuation = ".\"\',;:?() ";
  string answer = "";
  map <char, char> table = {
    {'a', 'z'}, {'b', 'y'}, {'c', 'x'}, {'d', 'w'}, {'e', 'v'}, {'f', 'u'}, {'g', 't'}, {'h', 's'}, {'i', 'r'}, {'j', 'q'}, {'k', 'p'},  {'l', 'o'}, {'m', 'n'}, {'n', 'm'}, {'o', 'l'}, {'p', 'k'}, {'q', 'j'}, {'r', 'i'}, {'s', 'h'}, {'t', 'g'}, {'u', 'f'}, {'v', 'e'}, {'w', 'd'}, {'x', 'c'}, {'y', 'b'}, {'z', 'a'}};
    for(int i = 0; i < text.length(); i++){
      if(isupper(text.at(i))){
        uppercase.push_back(i);
        text.at(i) = tolower(text.at(i));
      }
      if(punctuation.find(text.at(i)) != std::string::npos){
        answer += text.at(i);
      }else{
        answer += table.at(text.at(i));
      }
    }
    for(int j = 0; j < uppercase.size(); j++){
      answer.at(uppercase.at(j)) = toupper(answer.at(uppercase.at(j)));
    }
  return answer;
}
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "hill.h"

using namespace std;

string hill(string text, string keyword, bool encrypt){
   string result = "";
   for(int i = 0; i < text.length(); i++){
      text.at(i) = toupper(text.at(i));
   }
   int key[2][2] = {
      {23, 23},
      {23, 23}
   };
   if(keyword.length() >= 1){
      key[0][0] = toupper(keyword.at(0)) - 65;
   }
   if(keyword.length() >= 2){
      key[0][1] = toupper(keyword.at(1)) - 65;
   }
   if(keyword.length() >= 3){
      key[1][0] = toupper(keyword.at(2)) - 65;
   }
   if(keyword.length() >= 4){
      key[1][1] = toupper(keyword.at(3)) - 65;
   }
   if(text.length() % 2 == 1){
      text += 'X';
   }  
   if(encrypt){ 
      int msg[2] = {}; 
      int top;
      int bottom;
      for(int j = 0; j < text.length() - 1; j+=2){
         msg[0] = text.at(j) - 65;
         msg[1] = text.at(j+1) - 65;
         result += (char)(((msg[0] * key[0][0]) + (msg[1] * key[0][1]))%26) + 65;
         result += (char)(((msg[0] * key[1][0]) + (msg[1] * key[1][1]))%26) + 65;      
      }
   }else if(!encrypt){
      int determinant = (key[0][0]*key[1][1]) - (key[0][1] * key[1][0]);   
      determinant = determinant % 26;
      cout << determinant;
   }
   return result;
}
int main(){
   string key = "door";
   string text = "cipherseek";
   cout << hill(text, key, true);

}
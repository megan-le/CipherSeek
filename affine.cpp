#include "affine.h"

string affine(string m, int a, int b, bool encrypt){
  string answer = "";
  for(int i = 0; i<m.length(); i++){
    int val = 0;
    if(m[i] == ' '){
      answer += " ";
    }else if(!isalpha(m[i])){
      answer+= m[i];
    }else if(isupper(m[i])){
      val = 65;
    }else{
      val = 97;
    }
    if(val != 0){
      if(encrypt){
        answer+=char(((((int(m[i])-val)*a+b)%26)+26)%26+val);
      }else{
        int temp = (((int(m[i])-val-b)%26)+26)%26;
        bool notFound = true;
        int x = -1;
        while(notFound){
          x++;
          if((x*a)%26==temp){
            notFound=false;
          }
        }
        answer+=char(x+val);
      }
    }
  }
  return answer;
}
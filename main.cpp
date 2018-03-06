#include <iostream>
#include<string>

using namespace std;

string caesar(string a, int shift, bool encrypt){
  string answer = "";
  for(int i = 0; i<a.length(); i++){
    int val = 0;
    if(a[i] == ' '){
      answer += " ";
    }else if(!isalpha(a[i])){
      answer+= a[i];
    }else if(isupper(a[i])){
      val = 65;
    }else{
      val = 97;
    }
    if(val != 0){
      if(encrypt){
        answer+=char((((int(a[i])-val+shift)%26)+26)%26+val);
      }else{
        answer+=char((((int(a[i])-val-shift)%26)+26)%26+val);
      }
    }
  }
  return answer;
}

int main() {
  std::cout << caesar("This is a test",10,true) << "\n";
  std::cout << caesar("Drsc sc k docd",10,false);
}

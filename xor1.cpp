#include "xor1.h"

string xor1(string m, string k){
  string answer = "";
  for(int i = 0; i<m.length(); i++){
    answer += char(int(m[i])^int(k[i%k.length()]));
  }
  return answer;
}

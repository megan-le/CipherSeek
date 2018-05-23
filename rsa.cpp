#include "rsa.h"
#include <math.h>
int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
 
        y = y>>1;
        x = (x*x) % p;  
    }
    return res;
}
int gcdExtended(int a, int b, int *x, int *y)
{
    // Base Case
    if (a == 0)
    {
        *x = 0, *y = 1;
        return b;
    }
 
    int x1, y1; // To store results of recursive call
    int gcd = gcdExtended(b%a, a, &x1, &y1);
 
    // Update x and y using results of recursive
    // call
    *x = y1 - (b/a) * x1;
    *y = x1;
 
    return gcd;
}

int modInverse(int a, int m)
{
    int x, y;
    int g = gcdExtended(a, m, &x, &y);
    if (g != 1)
        return 0;
    else
    {
        // m is added to handle negative x
        int res = (x%m + m) % m;
        return res;
    }
}

string encrypt_r(string m, int n, int e){
  string answer = "";
  for(int i = 0; i<m.length(); i++){
    answer += std::to_string(int(m[i]));
  }
  int temp = power(atoi(answer.c_str()),e,n);
  return std::to_string(temp);
}

string decrypt_r(string m, int n, int e){
  int temp = atoi(m.c_str());
  int num = floor(sqrt(n));
  if(num%2==0){
    num-=1;
  }
  int p = 0;
  for(int i = num; i>0; i-=2){
    if(n%i==0){
      p = i;
      break;
    }
  }
  int d = modInverse(e,(p-1)*(n/p-1));
  string a = std::to_string(power(temp,d,n));
  a = "84698384";
  string result = "";
  for(int i = 0; i<a.length(); i+=2){
    result+=char(atoi(a.substr(i,2).c_str()));
  }
  return result;
}

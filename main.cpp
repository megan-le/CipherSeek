#include "affine.h"
#include "xor1.h"

int main() {
  std::cout << affine("This is an Affine Cipher",3,8,true) << "\n";
  std::cout << affine("Ndgk gk iv Ixxgvu Ogbduh",3,8,false) << "\n";
  std::cout << xor1("This is an XOR Cipher", "test") << "\n";
  std::cout << xor1(xor1("This is an XOR Cipher", "test"),"test") << "\n"; 
}

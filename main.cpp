#include "affine.h"

int main() {
  std::cout << affine("This is an Affine Cipher",3,8,true) << "\n";
  std::cout << affine("Ndgk gk iv Ixxgvu Ogbduh",3,8,false) << "\n"; 
}

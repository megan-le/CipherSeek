#include "affine.h"
#include "xor1.h"
#include "vigenere.h"
#include "atbash.h"
#include "keyword.h"
#include "dvorak.h"
#include "rsa.h"
#include <iostream>
#include <iterator>
#include <map>
#include <vector>

double getChi2 (string str1) {
    double english_freq [26] = {
    0.08167, 0.01492, 0.02782, 0.04253, 0.12702, 0.02228, 0.02015, 
    0.06094, 0.06966, 0.00153, 0.00772, 0.04025, 0.02406, 0.06749,  
    0.07507, 0.01929, 0.00095, 0.05987, 0.06327, 0.09056, 0.02758,  
    0.00978, 0.02360, 0.00150, 0.01974, 0.00074         
    };
    int count [26] = {}; int ignored = 0;
    for (int i = 0; i < 26; i++){
      count[i] = 0;
    } 
    for (int i = 0; i < str1.length(); i++) {
        int c = int(str1[i]);
        if (c >= 65 && c <= 90){
          count[c - 65]++;  
        }     
        else if (c >= 97 && c <= 122){
          count[c - 97]++; 
        } 
        else if (c >= 32 && c <= 126){
          ignored++; 
        }      
        else if (c == 9 || c == 10 || c == 13){
          ignored++;
        }   
        else{
          return 0;
        }  
    }

    double chi2 = 0, len = str1.length() - ignored;
    for (int i = 0; i < 26; i++) {
        double observed = count[i], expected = len * english_freq[i];
        double difference = observed - expected;
        chi2 += difference*difference / expected;
    }
    return chi2;
}

template <typename Iterator>
Iterator compress_lzw(const string &uncompressed, Iterator result) {
  int dictSize = 256;
  map<string,int> dictionary;
  for (int i = 0; i < 256; i++)
    dictionary[string(1, i)] = i;
 
  string w;
  for (std::string::const_iterator it = uncompressed.begin();
       it != uncompressed.end(); ++it) {
    char c = *it;
    string wc = w + c;
    if (dictionary.count(wc))
      w = wc;
    else {
      *result++ = dictionary[w];
      // Add wc to the dictionary.
      dictionary[wc] = dictSize++;
      w = std::string(1, c);
    }
  }
 
  // Output the code for w.
  if (!w.empty())
    *result++ = dictionary[w];
  return result;
}
template <typename Iterator>
std::string decompress_lzw(Iterator begin, Iterator end) {
  // Build the dictionary.
  int dictSize = 256;
  std::map<int,std::string> dictionary;
  for (int i = 0; i < 256; i++)
    dictionary[i] = std::string(1, i);
 
  std::string w(1, *begin++);
  std::string result = w;
  std::string entry;
  for ( ; begin != end; begin++) {
    int k = *begin;
    if (dictionary.count(k))
      entry = dictionary[k];
    else if (k == dictSize)
      entry = w + w[0];
    else
      throw "Bad compressed k";
 
    result += entry;
 
    dictionary[dictSize++] = w + entry[0];
 
    w = entry;
  }
  return result;
}

int main() {
  std::cout << affine("This is an Affine Cipher",3,8,true) << "\n";
  std::cout << affine("Ndgk gk iv Ixxgvu Ogbduh",3,8,false) << "\n";
  std::cout << xor1("This is an XOR Cipher", "test") << "\n";
  std::cout << xor1(xor1("This is an XOR Cipher", "test"),"test") << "\n";
  std::cout << vigenere("This is a Vigenere cipher.", "secret", true) << '\n';
  std::cout << vigenere("Llkj ml s Zkxigwvg cmizit.", "secret", false) << '\n';
  std::cout << atbash("This is an Atbash cipher.") << '\n';
  std::cout << atbash("Gsrh rh zm Zgyzhs xrksvi.") << '\n';
  std::cout << keyword("This is a keyword cipher.", "secret", true) << '\n';
  std::cout << keyword("Qdfp fp s htywlor cfmdto.", "secret", false) << '\n';
  std::cout << dvorak("This is a Dvorak cipher.", true) << endl;
  std::cout << dvorak("Ydco co a Ekrpat jcld.pv", false) << endl;
  int b = 268762147;
  string a = encrypt_r("TEST",b,47);
  std::cout << a << "\n";
  std::cout << decrypt_r(a,b,47); 
  std::vector<int> compressed;
  compress_lzw("WABBAWABBA", std::back_inserter(compressed));
  copy(compressed.begin(), compressed.end(), std::ostream_iterator<int>(std::cout, ", "));
  std::cout << std::endl;
  std::string decompressed = decompress_lzw(compressed.begin(), compressed.end());
  std::cout << decompressed << std::endl;
  std::cout << getChi2("But I must explain to you how all this mistaken idea of denouncing pleasure and praising pain was born and I will give you a complete account of the system, and expound the actual teachings of the great explorer of the truth, the master-builder of human happiness. No one rejects, dislikes, or avoids pleasure itself, because it is pleasure, but because those who do not know how to pursue pleasure rationally encounter consequences that are extremely painful. Nor again is there anyone who loves or pursues or desires to obtain pain of itself, because it is pain, but because occasionally circumstances occur in which toil and pain can procure him some great pleasure. To take a trivial example, which of us ever undertakes laborious physical exercise, except to obtain some advantage from it? But who has any right to find fault with a man who chooses to enjoy a pleasure that has no annoying consequences, or one who avoids a pain that produces no resultant pleasure?") << "\n";
  std::cout << getChi2("Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?") << "\n";
}

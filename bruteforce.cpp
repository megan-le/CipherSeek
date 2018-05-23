#include <iostream>
#include <string>
#include <vector>

#include "getchi2.h"
#include "vigenere.h"
#include "bruteforce.h"

using namespace std;
class Guess{
   public:
      Guess();
      Guess(string k, int c, string r);
      
      string key;
      float chi;
      string result;
      
};

Guess::Guess(){
   chi = 999999;
   key = "";
   result = "";
}
Guess::Guess(string k, int c, string r){
   key = k;
   chi = c;
   result = r;
}

void bruteForce(int keyLength, string text){
   string test2;
   int listLength = 3;
   float chiValue;
   string result;
   Guess* topGuesses[listLength];
   double lowestValue = 999999;
   int index = 20-1;
   for(int init = 0; init < 20; init++){
      Guess* filler = new Guess();
      topGuesses[init] = filler;
   }
   
   
   
   if(keyLength > 3 || keyLength == 1){
      cout << "Sorry, that keylength is currently not supported." << endl;
   }else if(keyLength == 2){
      char* test = new char[2];
      for(int i = 65; i < 91; i++){
        test[0] = (char)i;
        for(int j = 65; j < 91; j++){
            test2 = "";
            test[1] = (char)j;
            cout << "Tested key: " << test[0] << test[1] << "          ";
            for(int agh = 0;agh < 2; agh++){
               test2 += test[agh];
            } 
            result = vigenere(text, test2, false);
            chiValue = getChi2(result);
            cout << "Current cut-off value: " << lowestValue << "          ";
            cout << "Chi Value: " << chiValue << "         ";
            if(chiValue < lowestValue){
               lowestValue = chiValue;
               Guess* yay = new Guess(test2, chiValue, result);
               topGuesses[index] = yay;
               for(int z = 0; z < listLength; z++){
                  if(topGuesses[z]->chi > lowestValue){
                     lowestValue = topGuesses[z]->chi;
                     index = z;
                  }
               }
               cout << "New cut-off value: " << lowestValue;
            }
 
            cout << endl;
         } 
      }
      }else if(keyLength == 3){
         char* test = new char[3];
         for(int i = 65; i < 91; i++){
            test[0] = (char)i;
            for(int j = 65; j < 91; j++){
               test[1] = (char)j; 
                  for(int k = 65; k < 91; k++){
                     test2 = "";
                     test[2] = (char)k;
             //        cout << "Tested key: " << test[0] << test[1] << test[2] << "          ";
                     for(int agh = 0; agh < 3; agh++){
                         test2 += test[agh];
                     }
                     result = vigenere(text, test2, false);
                     chiValue = getChi2(result);
          //           cout << "Current cut-off value: " << lowestValue << "          ";
            //         cout << "Chi Value: " << chiValue << "         ";
                     if(chiValue < lowestValue){
                        lowestValue = chiValue;
                        Guess* yay = new Guess(test2, chiValue, result);
                        topGuesses[index] = yay;
                        for(int z = 0; z < listLength; z++){
                           if(topGuesses[z]->chi > lowestValue){
                              lowestValue = topGuesses[z]->chi;
                              index = z;
                           }
                        }
            //            cout << "New cut-off value: " << lowestValue;
                     }
        //             cout << endl;
                  }
            } 
                  }
            }
      
  for(int finalCounter = 0; finalCounter < listLength; finalCounter++){
      string output(topGuesses[finalCounter]->key);
      cout << "Key: " << output << "          Chi Value: " << topGuesses[finalCounter]->chi << endl;
      cout << topGuesses[finalCounter]->result <<endl << endl;
  }
}

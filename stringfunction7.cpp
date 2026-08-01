#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX = 4;
 
int main () {
const char *names[MAX] = { "Zara Ali", "Hina Ali", "aiza Ali", "Sara Ali" };

   for (int i = 0; i < MAX; i++) {
      cout << "Value of names[" << i << "] = ";
      //cout << *(names + i) << endl;
      cout << names[i] << endl;
   }
   
   return 0;
}

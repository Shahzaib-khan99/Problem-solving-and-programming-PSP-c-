#include <iostream>
#include <cmath>
#include <conio.h>
#include<iomanip>
using namespace std;
 
int main () {
   // declare simple variables
   int    i;
   double d;
 
   // declare reference variables
   int&    r = i;
   double& s = d;
   
   i = 10;
   cout << "Value of i : " << i << endl;
   cout << "Value of i reference : " << r  << endl;
 	
 i=30;
   cout << "Value of i : " << i << endl;
   cout << "Value of i reference : " << r  << endl;
   
   d = 20.5;
   cout << "Value of d : " << d << endl;
   cout << "Value of d reference : " << s  << endl;
   
   return 0;
}

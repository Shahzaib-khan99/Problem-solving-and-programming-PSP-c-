#include <iostream>
#include <cmath>
#include <conio.h>

#include<iomanip>

 using namespace std;
 
int main() {
       int    i;	   double d;			// declare simple variables
  
   int& r = i;					// declare reference variables
   double& s = d;
      i = 5;
   cout << "Value of i : " << i << endl;					// display 5
   cout << "Value of i reference : " << r  << endl;		//display 5
   
   
   cout<<"address of i="<<&i;
   cout<<"\n\n address of r="<<&r;
   /*
   r=10;
   cout << "Value of i : " << i << endl;					// display 10
   cout << "Value of i reference : " << r  << endl;		//display 10
d = 11.7;
   cout << "Value of d : " << d << endl;				//  display 11.7
   cout << "Value of d reference : " << s  << endl;		//display 11.7
  */
   return 0;
}



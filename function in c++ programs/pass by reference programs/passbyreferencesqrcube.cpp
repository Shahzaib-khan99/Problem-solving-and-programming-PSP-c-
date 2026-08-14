#include <iostream>
#include <cmath>
#include <conio.h>
//#include<iomanip>
using namespace std;
 void sqr_cube(float, float&, float& );  //function prototype
 
 void sqr_cube(float num, float& sqr, float& cube )
 {						
 	sqr=num*num;
 	cube=num*num*num;
 }
int main() 
{						
	float n, sqr1, cube1;
     
	 cout<<"enter a number=>";
	 cin>>n;				//2
	 
	 sqr_cube(n,sqr1,cube1);  // function calling
	 
	 cout<<"\n  Square of a number ="<<sqr1; //12.56
	  cout<<"\n  Cube of a number="<<cube1; //12.56
	  
   return 0;
}



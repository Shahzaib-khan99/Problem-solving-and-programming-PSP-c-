#include <iostream>
#include <cmath>
#include <conio.h>
#include<iomanip>
 using namespace std;
 
int main() {
   int count=1; int count2;
   
   while (count<=3)				//count=1+1=2+1=3+1=4
   {
   	cout<<"outer loop=\n\n";
	   count2=1;				//count2=1
   	   while(count2<=5)
   	   {
   	   	cout<<" inner loop\n";
   	   	
   	   	count2++;
	   }
   	
   	count++;
   }
   return 0;
}



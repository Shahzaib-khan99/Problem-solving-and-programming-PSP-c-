#include <iostream>
#include <cmath>
#include <conio.h>
#include<iomanip>
 using namespace std;
 
int main() 
{
   int count=1; int count2;
   
 do				
   {
   	cout<<"outer loop=\n\n";
	  count2=1;
   	   do
   	   {
   	   	cout<<" inner loop\n";
   	   	
   	   	count2++;
	   }while(count2<=3);
   	
   	count++;
   }while(count<=3);
   return 0;
}



#include <iostream>
#include <cmath>
#include <conio.h>
#include<iomanip>
 using namespace std;
 
int main() {
   int count=1; int count2;
   
  int i, j;
  
  for (i=1; i<=3; i++)
  {
  	cout<<"outer loop\n";
	
	for(j=1; j<=2;j++)
  	{
  		cout<<"inner loop\n";	
	}
  	cout<<"inner loop end\n\n";
 }
  
   return 0;
}



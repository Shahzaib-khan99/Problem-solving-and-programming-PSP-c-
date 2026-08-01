#include <iostream>
#include <cmath>
#include <conio.h>
#include<iomanip>
 using namespace std;
 
int main()
 { 
  int i, j;
  for (i=1; i<=3; i++)
  {
  	cout<<"outer loop\n";
	
	for(j=1; j<=5;j++)
  	{
  		cout<<"inner loop\n";	
	}
  	//cout<<"inner loop end\n\n";
 }
  
   return 0;
}


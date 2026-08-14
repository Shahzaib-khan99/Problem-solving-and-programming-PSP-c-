#include <iostream>
#include <cmath>
#include <conio.h>
//#include<iomanip>
using namespace std;
 
 void MaxMin(int,int, int&,int&);  //function prototype
 
 void MaxMin(int n1,int n2, int& max,int& min)
 {				 			
 	if(n1>n2)
	 	{
	 		max=n1;	
		}
	else
		{
			max=n2;
		}
	if(n1<n2)
	 	{
	 		min=n1;	
		}
	else
		{
			min=n2;
		}
 }
 
int main() 
{						
	int num1,num2, max1,min1;
     
	 cout<<"enter number1=>";
	 cin>>num1;				
	 cout<<"enter number2=>";
	 cin>>num2;
	 
	 MaxMin(num1,num2,max1,min1);  // function calling
	 
	 cout<<"\n  Maximum="<<max1; 
	  cout<<"\n  Minimum="<<min1; 
   return 0;
}



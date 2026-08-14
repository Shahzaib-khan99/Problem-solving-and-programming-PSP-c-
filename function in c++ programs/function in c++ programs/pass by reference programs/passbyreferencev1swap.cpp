#include <iostream>
#include <cmath>
#include <conio.h>
#include<iomanip>
using namespace std;
 
void swap(int&, int&);  //function prototype

void swap(int& n1, int& n2 )
{
	int temp;
	temp=n1;
	n1=n2;
	n2=temp;				
}
int main() {						
	int num1,num2;
	cout<<"enter first number =";				
	cin>>num1;//3
	cout<<"enter second number =";				
	cin>>num2;//6
	cout<<"\nValues before function calling";
	cout<<"\n first number="<<num1;
	cout<<"\n second number="<<num2;
	swap(num1,num2);
	
	cout<<"\nValues after function calling";
	cout<<"\n first number="<<num1;
	cout<<"\n second number="<<num2;
	num1=num1*2;
       cout<<"\n first number *2="<<num1;
   return 0;
}



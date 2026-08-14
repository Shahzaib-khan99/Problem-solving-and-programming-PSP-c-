#include <iostream>
#include <cmath>
#include <conio.h>
#include<iomanip>
using namespace std;
 //Function with argument/ parameter  and return value.
int max(int, int); // function prototype or function declaration

int max(int num1, int num2) // formal parameters
{						//num1=9   num2=11	
	if (num1>num2)
	{
		return num1;
	}
	else
	{
		return num2;
	}
}
int main() 
{						
	int result,n1,n2,n3;
	cout<<"enter number1=>";
	cin>>n1;//9
	cout<<"enter number2=>";
	cin>>n2;//11
	
	cout<<"function call starting \n";
	result=max(n1,n2);// function calling
	cout<<"\n\nfunction call ends \n";
	cout<<"maximum number between "<<n1<<" and "<<n2<<"="<<result;
	
	
 return 0;
}



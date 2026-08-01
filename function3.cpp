#include <iostream>
#include <cmath>
#include <conio.h>
#include<iomanip>
using namespace std;
 //Function with argument/ parameter  and return value.
int add(int, int, int); // function prototype or function declaration
int add(int num1, int num2, int num3) // formal parameters
{						//num1=9   num2=11	num3=5
	int sum;
	sum=num1+num2+num3;//sum=25
	return sum;
}
int main() 
{						
	int result,n1,n2,n3;
	cout<<"enter number1=>";
	cin>>n1;//9
	cout<<"enter number2=>";
	cin>>n2;//11
	cout<<"enter number3=>";
	cin>>n3;//5
	cout<<"function call starting \n";
	result=add(n1,n2,n3);// function calling
	cout<<"\n\nfunction call ends \n";
	cout<<"sum of number1 "<<n1<<"and number2 "<<n2<<" and number3 "<<n3<<"="<<result;
	
	
 return 0;
}



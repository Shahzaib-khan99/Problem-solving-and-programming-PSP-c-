#include <iostream>
#include <cmath>
#include <conio.h>
#include<iomanip>
using namespace std;
 //Function with no argument/ parameter  and return value.
int add(); // function prototype or function declaration

int add() // formal parameters
{						//num1=9   num2=11	
	int sum,num1,num2;
	cout<<"enter number1=>";
	cin>>num1;//9
	cout<<"enter number2=>";
	cin>>num2;//10
	sum=num1+num2;//sum=19
	return sum;
}
int main() 
{						
	int result,n1,n2;
	//cout<<"enter number1=>";
	///cin>>n1;//9
	//cout<<"enter number2=>";
	//cin>>n2;//11
	cout<<"function call starting \n";
	
	result=add();
	cout<<"\n\nfunction call ends \n";
	
	cout<<"sum of two numbers="<<result;
	
	
 return 0;
}



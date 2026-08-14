#include <iostream>
#include <cmath>
#include <conio.h>
#include<iomanip>
using namespace std;
 //Function with no argument/ parameter and no return type.
//returnType functionName (parameter list);

void display(void); // function prototype or function declaration

void add(void) // function definition
{
	//cout<<"my first user defiend function \n";
	//cout<<"let us see, how it executes \n\n";
	int num1, num2;
	num1=5;
	num2=10;
	int sum=num1+num2;
	cout<<"sum="<<sum;
	
}

int main() 
{	
					
	cout<<"function call starting \n";
	
	add();

	cout<<"\n\nfunction call ends \n";
	

	
 return 0;
}
 


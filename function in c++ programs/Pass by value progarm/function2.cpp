#include <iostream>
#include <cmath>
#include <conio.h>
#include<iomanip>
using namespace std;
 //Function with arguments/parameters but no return type.
 
void add(int ,int ); // function prototype or function declaration

void add(int num1, int num2) // formal parameters
{							//num1=10    num2=20
	int sum;
	sum=num1+num2;// sum=30
	cout<<"\n sum of number1 "<<num1 <<" and number2 "<<num2<<"=>"<<sum;
}
int main() 
{						
	int n1,n2;
	cout<<"enter number1=";
	cin>>n1;//10
	cout<<"enter number2=";
	cin>>n2;//20
	cout<<"function call starting \n";
	add(n1,n2); // funtion calling
			// actual parameters		
	cout<<"\n\nfunction call ends \n";
 return 0;
}



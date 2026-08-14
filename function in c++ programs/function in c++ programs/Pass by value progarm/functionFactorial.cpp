#include <iostream>
#include <cmath>
#include <conio.h>
#include<iomanip>
using namespace std;
 //Function with argument/ parameter  and return value.
int fact(int);				// function prototype or function declaration
//5!=5*4*3*2*1=120
int fact(int num)//num=5
{
	int result;      result=1;		//i=1+1=2+1=3+1=4
									//result=1*1=1*2=2*3=6
	for (int i=1;i<=num;i++ )
	{
		result=result*i;
	}
	return result;
}
int main() 
{						
	int R,n1;
	
	cout<<"eneter a number you want a factprial=";
	cin>>n1;//5
	
	R=fact(n1);
	
	cout<<"the factorial of "<<n1 <<"!="<<R;

 return 0;
}



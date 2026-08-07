#include <iostream>
#include<stdio.h>  
using namespace std;
void iabs(int);
void iabs(float);

void iabs(int n)
{
	if (n<0)
		n=(-n);
	cout<<"\n  absolute value of integer="<<n;
}

void iabs(float n1)
{
	if (n1<0)
		n1=(-n1);
	cout<<"absolute value of float="<<n1;
}

int main ()  
{
int x=-5;
float y=3.5;
	iabs(x);
	cout<<endl;
	iabs(y);
    
    return 0;
}  

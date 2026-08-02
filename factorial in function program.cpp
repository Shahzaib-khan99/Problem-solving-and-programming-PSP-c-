#include<iostream>
#include<iomanip>
#include<conio.h>
#include<cmath>
using namespace std;

int fact(int);
int fact(int num)
{

int result;
result=1;
int i;
 for(i=1;i<num;i++)
{
   result=result*i;	
}
return result;
}
int main()
{

int R,n;
cout<<"enter the number that you want to find the factorial =";
cin>>n;
 
 R=fact(n);
 cout<<"factorial of"<<n<<"!="<<R;
}

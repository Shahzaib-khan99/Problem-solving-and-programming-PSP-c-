#include <iostream>
#include<stdio.h>  

using namespace std;

int num1=5;
inline int cube(int ) ;
inline int cube(int s) 
{   
	int num1=30;
	cout<<"in  cube function num1="<<num1;
    return s*s*s; 
} 


int main() 
{ 	

int num, num1;
num1=10;
	cout<<"in main="<<num1;
	cout<<"\n enter a number you want a cube:";
	cin>>num;
    int result=cube(num);
	cout << "\nThe cube of 3 is: " << result << "\n"; 
    return 0; 
} 

#include <iostream>
#include <cmath>
#include <conio.h>
#include<iomanip>
 using namespace std;
 
int main() 
{
 int num;
 char ch;
 do
 {
 	cout<<"\neneter a number=";
 	cin>>num;							
 	cout<<"\n the input number is="<<num;
 	
 	cout<<"\n \n Do you want to continue [y/n] ?==>";
 	ch=getche();
 	
 }while(ch=='y' || ch=='Y');
   
return 0;
}


#include <iostream>
#include <cmath>
#include <conio.h>
#include<iomanip>
using namespace std;
 
void swap(int&, int&);  //function prototype

void swap(int& n1, int& n2 )  //functio definition
{							//n1= 3   n2=6   // int& n1=num1;  
	int temp;								//  int& n2=num2;
	temp=n1;		//temp=3
	n1=n2;			//n1=6
	n2=temp;		//n2=3		
}
int main() {						
	int num1,num2;
	cout<<"enter first number =";				
	cin>>num1;//3
	cout<<"enter second number =";				
	cin>>num2;//6
	cout<<"\n\n Values before function calling";
	cout<<"\n\n first number =>"<<num1;  //3
	cout<<"\n second number=>"<<num2; //6
	
	swap(num1,num2);   //function calling
	
	cout<<"\n\n Values after function calling";
	cout<<"\n\n first number =>"<<num1;  //6
	cout<<"\n second number=>"<<num2; //3
	
       
   return 0;
}



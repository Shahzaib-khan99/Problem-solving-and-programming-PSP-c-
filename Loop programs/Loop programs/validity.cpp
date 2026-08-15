#include <iostream>
#include <cmath>
#include <conio.h>
#include<iomanip>
 using namespace std;
 
int main() 
{
 int id;
 do
 {
 	cout<<"eneter an id number=";
 	cin>>id;							//id=5
 	if(id<1 ||id>10)
 	 {
 		cout<<"invalid number ... please eneter correct number \n";
	 }
 	else
 		{
 		cout<<"valid number..";
		 break;
		}
 	
 }while(1);
   
return 0;
}


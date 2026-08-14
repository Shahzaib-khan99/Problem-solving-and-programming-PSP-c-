#include <iostream>
#include <cmath>
#include <conio.h>

#include<iomanip>

 using namespace std;
 const int size=5;

int main() {
   
   int marks[size];// it reserve 5 memory locations
   int i, num,ind;
   bool found=false;
   for(int i=0; i<size; i++)
   {
   		cout<<"enter marks for student "<<i+1<<"==>";
   		cin>>marks[i];
   		
   }
    cout<<"Array values are";
	for(int i=0; i<size; i++)
   {
   		cout<<marks[i]<<",\t";
   		
   }
   cout<<"\nenter marks you want to search";
   cin>>num;
   i=1;
   while((i<=size)&& (found==false) )
   {
	   	if (marks[i]==num)
	   	{
	   		found=true;
	   		ind=i;
		}
		else
	   		i++;
   	
   }
   
	   if (found==true)
	   {
	   		cout<<"marks found at location "<<ind;
	   }
	   else
	   {
	   		cout<<"marks not found";
	   	
	   }
   
   return 0;
}



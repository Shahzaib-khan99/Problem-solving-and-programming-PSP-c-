#include <iostream>
#include <cmath>
#include <conio.h>
#include<iomanip>
 using namespace std;
 const int size=5;
int main() 
{// program that finds the smallest element in the array
 int list[size]={10,20,-1,40,50};
 	
	cout<<" Array values are\n";
	
	cout<<"list[0]\tlist[1]\tliat[2]\tlist[3]\tlist[4]\n";
	for(int i=0; i<size; i++)
	{
		cout<<list[i]<<"\t";		
	}
	
	int smallest=list[0];				//largest=50
	for(int i=1; i<size; i++)			//i=1+1=2+1=3+1=4+1=5
	{
		if (list[i]<smallest)
		{
			smallest=list[i];
		}
	}
	
	cout<<"\nsmallest value in the list="<<smallest;

 	//display array values
 	
	
return 0;
}


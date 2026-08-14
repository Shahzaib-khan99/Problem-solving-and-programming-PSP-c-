#include <iostream>
#include <cmath>
#include <conio.h>
#include<iomanip>
// Sort element in the array
 using namespace std;
 const int size=5;
int main() 
{  
   int list[size];
   
   int i,j; int temp;
   
   // input the whole array
   for(i=0;i<size;i++)
   {
   	cout<<" enter vlues for list array=";
   	cin>>list[i];			
   }
   
   cout<<"\n the values in the list array bofore sorting\n";
   for(i=0;i<size;i++)
   {
   	cout<<list[i]<<"\t";			//[ 10,20,11,30,40]
   									
   }
  // code for sorting
   for(i=0;i<size-1;i++)				//i=1				temp=20
   {									//j=1				lsiat[1]=10
		for(j=1;j<size;j++)				//					list[2]=30
		{
			if (list[j]<list[j-1])
			{
				temp=list[j];
				list[j]=list[j-1];
				list[j-1]=temp;	
			}
		}
   }
   
   cout<<"\n the values in the list array after sorting\n";
   for(i=0;i<size;i++)
   {
   	cout<<list[i]<<"\t";
   	
   }
   return 0;
}



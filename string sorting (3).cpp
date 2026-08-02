#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;


const int size=6;
int main () 
{

char fruit[size][25] = { "orange", "banana", "pineapple", "apple",  "pear","appl"};
 
 char temp[25];
 int i,j;
  cout<<"string before sorting\n";
  for(i=0;i<size;i++)
 	cout<<fruit[i] <<"\t";
 
 for(i=0;i<size-1;i++)
 {
      for(j=i+1;j<size;j++)
	  {
         if(strcmp(fruit[i],fruit[j])>0)
		 {
            strcpy(temp,fruit[i]);
            strcpy(fruit[i],fruit[j]);
            strcpy(fruit[j],temp);
         }
         //cout<<"ok";
      }
 }
cout<<endl;	 
cout<<"string after sorting sorting\n";
 for(i=0;i<6;i++)
 	cout<<fruit[i] <<"\t";
 
   
   return 0;
}

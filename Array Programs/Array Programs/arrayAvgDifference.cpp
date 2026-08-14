#include <iostream>
#include <cmath>
#include <conio.h>

#include<iomanip>

 using namespace std;
 const int size=5;

int main() {
   
   int marks[size];// it reserve 5 memory locations
   // input data
   float sum,average, diff;
   sum=0.0;
   for(int i=0; i<size; i++)
   {
   		cout<<"enter marks for student "<<i+1<<"==>";
   		cin>>marks[i];
   		sum=sum+marks[i];
   }
   cout<<" Array values are\n";
	
	cout<<"marks[0]\tmarks[1]\tmarks[2]\tmarks[3]\tmarks[4]\n";
	for(int i=0; i<size; i++)
	{
		cout<<marks[i]<<"\t\t";		
	}
  		
		cout<<"\n sum of marks of student="<<sum;
 		average=sum/size;
 		cout<<"\n Average of marks of student="<<average;
		 cout<<endl;cout<<endl;
 	// difference from average for each student
	
	 cout<<"Student\t Marks\t aveage\t difference from average \n";
	 cout<<"=============================================== \n";
	 for(int i=0; i<size; i++)
	   {
	   	diff=marks[i]-average;
		cout<<i+1<<"\t"<<marks[i]<<"\t"<<average<<"\t"<<diff<<"\n";
	   }	
   
   return 0;
}



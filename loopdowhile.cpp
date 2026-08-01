#include <iostream>
#include <cmath>
#include <conio.h>
#include<iomanip>

 using namespace std;
 
int main() {
    float sum, avg;					//count=6			sum=0+10=10+20=30+30=60+20=80+10=90
  int count=1;
  int num;						//num=10,20,30,20,10
  do  
  {
  	cout<< "enter number";
  	cin>>num;
  	sum=sum+num;
  	count++;
  }while (count<=5);
  avg=sum/5;
   cout<<"sum of 5 numbers="<<sum;cout<<endl;
   cout<<"average="<<avg;
   return 0;
}



#include <iostream>
#include <cmath>
#include <conio.h>
#include<iomanip>
using namespace std;
 
void SqCube(int, float&, float&);

void sqcube(int num, float& sq1, float& cube1)// num=4
{
	sq1=num*num;						//sq1=16   sq=16
	cube1=num*num*num;					//cube1=64  cube=64
}
int main() {						
	int n; float sq, cube;
	cout<<"enter a number =";				//n=4
	cin>>n;
	sqcube(n,sq,cube);  // Function CALLING
	
	cout<<"\n square of a number "<<n<<"="<<sq;
	cout<<"\n cube of a number "<<n<<"="<<cube;
       
   return 0;
}

           

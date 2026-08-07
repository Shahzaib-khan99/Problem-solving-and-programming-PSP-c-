#include <iostream>
#include <cmath>
#include <conio.h>
#include<iomanip>
using namespace std;
 
void area(float length=3.0,float breadth=5.0   );  //function prototype
void area(float length,float breadth  )
{
	float area;
	cout<<"\n area of rectangle="<<length*breadth;
}

int main() {						
	int num1,num2;
	area(3);
	area(5);
	area(3,4);
	
   return 0;
}



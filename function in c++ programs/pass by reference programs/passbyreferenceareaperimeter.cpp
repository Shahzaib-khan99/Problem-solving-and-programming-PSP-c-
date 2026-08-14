#include <iostream>
#include <cmath>
#include <conio.h>
//#include<iomanip>
using namespace std;
 void AP(float, float&, float&, float& );  //function prototype
 
 void AP(float radius, float& Area, float& Perimeter,float& diameter )
 {							//radius=2	float& Area=area1  	float& Perimeter=perimeter1
 	Area=3.14*radius*radius;// 12.56
 	Perimeter=2*3.14*radius;// 12.56
 	diameter=2*radius;
 }
int main() 
{						
	float r, area1, perimeter1,d;
     
	 cout<<"enter value of radius=>";
	 cin>>r;				//2
	 
	 AP(r,area1,perimeter1,d);  // function calling
	 
	 cout<<"\n  Area of circle="<<area1; //12.56
	  cout<<"\n  Perimeter of circle="<<perimeter1; //12.56
	  cout<<"\n  diameter of circle="<<d;
   return 0;
}



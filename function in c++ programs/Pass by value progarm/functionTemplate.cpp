#include <iostream>
#include<stdio.h>  

using namespace std;

template <class T> 

T myMax(T x, T y) // int mymax(int x, int y)
{ 
   	if (x>y)
   		return x;
	else
		return y;
  // return (x > y)? x: y; 
} 
  
int main() 
{ 

  int x3,y3;   x3=8;    y3=7;
  float x1,y1;   x1=9.5;	y1=7.8;
  char x2,y2;	x2='c';		y2='d';
  cout <<"the greater value between-"<<x3<<"-and-"<<y3<<"- is="<<myMax(x3, y3) << endl;  // Call myMax for int 
  cout <<"the greater value between-"<<x1<<"-and-"<<y1<<"- is="<< myMax(x1, y1) << endl; // call myMax for double 
  cout <<"the greater value between-"<<x2<<"-and-"<<y2<<"- is="<< myMax(x2, y2) << endl;   // call myMax for char 
  
  return 0; 
}


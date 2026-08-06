///program to access the static member function using the class' object in the C++

#include <iostream>  
using namespace std;  
class Note  
{  
	// declare a static data member  
	//int num;  
	  static int num;  
	public:  
	// create static member function  
	static int func ()  
	{  
	cout << " The value of the num is: " << num << endl;    
	}  
};  
// initialize the static data member using the class name and the scope resolution operator  
int Note :: num = 15;   
  
int main ()  
{  
    // create an object of the class Note  
    Note n;  
	// access static member function using the object  
	n.func();  
  
return 0;  
}   


//program to access the static member function using the class name in the C++ 

#include <iostream>  
using namespace std;  
class Note  
{  
	 
	static int num;  // declare a static data member 
	  
	public:  
	
	static int func ()  // create static member function  
	{  
	return num;  
	}  
};  
// initialize the static data member using the class name and the scope resolution operator  
int Note :: num = 5;   
  
int main ()  
{  
// access static member function using the class name and the scope resolution  
cout << " The value of the num is: " << Note:: func () << endl;  
return 0;  
}   

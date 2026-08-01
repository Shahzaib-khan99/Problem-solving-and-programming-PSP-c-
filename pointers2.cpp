#include <iostream>

using namespace std;
const int MAX = 3;

int main () 
{
   int  var[MAX] = {10, 100, 200};
   int  *ptr;

   ptr = var;// var[0] now store the address of starting location means var[0]
   //cout<<var[2];cout<<endl;// 200
   //cout<<*ptr; cout<<endl;//10
   //cout<<*(ptr+1);cout<<endl;//100
   //cout<<ptr[2];cout<<endl;//200
   
  
   for (int i = 0; i < MAX; i++) {
     // cout << "Address of var[" << i << "] = ";
     // cout << ptr << endl;
	//	ptr=ptr+1;
      cout << "Value of var[" << i << "] = ";
      cout << *ptr << endl;

       ptr++;
   }
   
   return 0;
}


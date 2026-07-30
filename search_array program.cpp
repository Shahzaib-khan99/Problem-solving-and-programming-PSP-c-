#include <iostream>
using namespace std;

int main() 
{
       int arr[10] = {1,2,3,4,5,6,7,8,9,10};
       
       int key, found = -1;
       
       cout << "enter the element to search: ";
       
       cin >> key;
       
       for ( int i = 0; i<10; i++)
       {
       	if (arr[i] == key )
       	{
       		found = i;
       		break;
	       }
       }
       
       
       if (found!= -1)
       {
       	cout << "element" << key <<" found at index" << found << endl;
       	
       }
       
       else
        { 
        cout << "element" << key << "not found in the array" <<endl;
       }
       
       return 0;
	
	
	
	
}
  

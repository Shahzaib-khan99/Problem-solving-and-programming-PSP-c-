
///enumerated data type
#include <iostream>
using namespace std;

enum week { Sunday=1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };
enum year { Jan, 
            Feb, 
            Mar, 
            Apr, 
            May, 
            Jun, 
            Jul, 
            Aug, 
            Sep, 
            Oct, 
            Nov, 
            Dec }; 

int main()
{
	
	for (int i = Jan; i <= Dec; i++) 
        cout << i << " "; 
    week today;
    today = Sunday;
    //cout << "Day " << today+1;
    switch(today)
    {
    	case Sunday: cout<<"sunday";break;
    	case Monday: cout<<"Monday";break;
    	default: cout<<"oh";
	}
    return 0;
}

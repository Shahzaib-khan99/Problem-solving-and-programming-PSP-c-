#include <iostream>
using namespace std;

int main()
{
    int i;
    // Array of pointers to strings
    char *sports[] = {
        "golf",
        "hockey",
        "football",
        "cricket",
        "shooting"
    };

    // Loop through the array and print the strings and their addresses
    for (i = 0; i < 5; i++)
    {
        cout << "\nString = " << sports[i];
        cout << "\t\tAddress of string literal sports[" << i << "] = " << static_cast<void*>(sports[i]);
    }
    return 0;
}



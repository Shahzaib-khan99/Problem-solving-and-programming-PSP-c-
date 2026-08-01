
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include<string.h>
#include<ctype.h>
using namespace std;

int main()


{
 //char sports[5][15] = {"golf", "hockey", "football", "cricket",  "shooting" };
 
 
	 int i ; 

    char *sports1[] = {"golf",  "hockey",  "football",  "cricket", "shooting"  };

    for( i = 0; i < 5; i++)
    {
        cout<<"String = "<<sports1[i] ;
        cout<<"\tAddress of string literal = "<<i+1<<"="<< &sports1[i];cout<<endl;
    }
	return 0;
}


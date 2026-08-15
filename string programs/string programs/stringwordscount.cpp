#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;



int main()
{

//char str1[20]="abcde";
//char str2[20]="abcdef";
        int i, count;
	   char str[] = "tommy tucket took a tiny ticket ";
         count = 0;
        for (i = 0; i < strlen(str);i++)
           { 
             if (str[i] == ' ') 
              {
              	count++;
			  }
			   
            }
       cout<<"The number of words are="<<count;


	return 0;
}


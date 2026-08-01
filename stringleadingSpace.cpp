
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include<string.h>
#include<ctype.h>
using namespace std;


const int MAX_SIZE=100;
/* Function declaration */

void trimLeading(char * );


int main()
{
    char str[MAX_SIZE];

    /* Input string from user */
    cout<<"Enter any string:" ;
    gets(str);

    cout<<"\nString before trimming leading whitespace:"<<str;

    trimLeading(str);

   cout<<"\n\nString after trimming leading whitespace: "<< str;

    return 0;
}


/**
 * Remove leading whitespace characters from string
 */
void trimLeading(char * str)
{
    int index, i, j;

    index = 0;

    /* Find last index of whitespace character */
    while(str[index] == ' ' || str[index] == '\t' || str[index] == '\n')
    {
        index++;
    }


    if(index != 0)
    {
        
        i = 0;
        while(str[i + index] != '\0')
        {
            str[i] = str[i + index];
            i++;
        }
        str[i] = '\0'; // Make sure that string is NULL terminated
    }
}

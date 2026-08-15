#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;



int main()
{
//char name1[20]={'a','b','c',' ','a','l','i','\0'};
//char name2[20]="abc ali";
char str1[20]="Ahsan Rafiq";
char str2[20];
//cout<<"engter name of the person=>";
//gets(name);// ali\0
	int i;
	for( i=0; str1[i]!='\0';i++)
	{
		str2[i]=str1[i];
	}    

	str2[i]='\0';
	cout<<"\n str1 ="<<str1;
	cout<<"\n str2 ="<<str2;
	return 0;
}


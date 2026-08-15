#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main()
{
	char str1[20]="Ahsandf";
	char str2[20]="Ahsanfgh";	
	
int x=strncmp(str1,str2,6);
cout<<"\n\n x="<<x;

if (x==0)
	cout<<"\nstrings are same";
else
	cout<<"\nstrings are not same";



//cout<<"engter name of the person=>";
//gets(name);// ali\0
/*	int i;
	for( i=0; str1[i]!='\0';i++)
	{
		str2[i]=str1[i];
	}

	str2[i]='\0';
	cout<<"\n str1 ="<<str1;
	cout<<"\n str2 ="<<str2;*/
	return 0;
}


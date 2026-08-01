#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;



int main()
{
	//char name[20]={'a','l','i',' ','h','a','m','z','a','\0'};
	//char name[20]="ali hamza";
	char name[20] ="ali hamza";
//	cout<<"enter name =";
//	gets(name);
/*	int i=0;  int length=0;
	while (name[i]!='\0')
	{
		length++;
		i++;
	}
	
	cout<< "\nname="<<name;
	cout<< "\n length of name ="<<length;*/
	
	
  char *p;
  	p = name;     // assign starting location
  	while( *p != '\0')
  	{
    	cout << *p;
    	p++;
  	}
	return 0;
}


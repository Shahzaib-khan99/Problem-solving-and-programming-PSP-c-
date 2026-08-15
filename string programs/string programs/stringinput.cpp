#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;



int main()
{
//char name1[20]={'a','b','c',' ','a','l','i','\0'};
//char name2[20]="abc ali";
char name[20];
cout<<"enter name of the person:";
//cin>>name;
//cin.getline(name,20);// we can use gets() and puts()
gets(name);
//cout<<"\n  name="<<name;
puts(name);
//cout<<"\n  name1="<<name1;
//cout<<"\n  name2="<<name2;
	return 0;
}


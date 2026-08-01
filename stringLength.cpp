#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;



int main()
{
char name[ ]= "Hello";
  	int len1, len2;
  	len1 = strlen(name);
  	len2 = strlen("Hello World");
  	cout << "Length of " << name << " = " << len1 << endl;
  	cout << "Length of " << "Hello World" << " = " << len2 << endl;
	return 0;
}


#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;



int main()
{
char s2[ ]= "World";
  	char s1[20]= "Hello";
  	strcat(s1, s2);
  	cout << "Source string " << s2 << endl;
  	cout << "Target string " << s1 << endl;
	return 0;
}


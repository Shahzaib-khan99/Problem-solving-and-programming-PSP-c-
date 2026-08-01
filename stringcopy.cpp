#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;



int main()
{
char s2[ ]= "Hello";
  	char s1[10];
  	strcpy(s1, s2);
  	cout << "Source string " << s2 << endl;
  	cout << "Target string " << s1 << endl;
	return 0;
}


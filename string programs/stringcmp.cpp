#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;



int main()
{
char s1[ ]= "Hello";
  	char s2[ ]= "World";
  	int i, j;
  	i = strcmp(s1, "Hello");// retrn 0 if strings are same otherwise non zero
  	j = strcmp(s1, s2);
  	cout << i << endl;
  	cout << j << endl;
	return 0;
}


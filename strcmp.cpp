#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int result;
	char str1[20],str2[20];
	
	cout<<"enter the first string:";
	cin>>str1;
	cout<<"enter the second string";
	cin>>str2;
	
          result=strcmp(str1,str2);
          
          if(result==0)
          {
          	cout<<"strings are same";
	}
	else
	{
	         cout<<"strings are not same";
	}
	
}

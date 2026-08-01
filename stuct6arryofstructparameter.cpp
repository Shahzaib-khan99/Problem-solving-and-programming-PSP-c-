#include <iostream>
using namespace std;

struct Example
{
  int num1;
  int num2;
}s[3];

void accept( Example [],int );
void print( Example [],int );
//-------------------------------------
void accept( Example sptr[],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
  cout<<"\nEnter num1 : ";
  cin>>sptr[i].num1;
  cout<<"\nEnter num2 : ";
  cin>>sptr[i].num2;
  }
}
//-------------------------------------
void print( Example sptr[],int n)
{
  int i;
  for(i=0;i<n;i++)
  {
  cout<<"\nNum1 :"<<sptr[i].num1;
  cout<<"\nNum2 : "<<sptr[i].num2;
  }
}
//-------------------------------------
int main()
{
int i;

accept(s,3);
print(s,3);
return 0;
}

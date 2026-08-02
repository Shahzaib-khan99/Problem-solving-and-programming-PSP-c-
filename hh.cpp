#include <iostream>
#include <cctype>
#include <cstring>
#include <stdio.h>
using namespace std;
int const size =3;
struct person
{ 
 int age;
 float salary;
 char name[50];
}; 
int main()
{ 

 struct person p[size];
 for(int i=0;i<size;i++)
 { 
  cout<<"enter a name "<<i+1;
  cin.ignore();
  cin.getline(p[i].name,50);
  cout<<endl;
  cout<<"enter salary "<<i+1;
  cin>>p[i].salary;
  cout<<endl;
  cout<<"enter age "<<i+1;
  cin>>p[i].age;
  cout<<endl;
 }
  for(int i=0;i<size;i++)
  { 
   cout<<p[i].name;
   cout<<endl;
   cout<<p[i].age;
   cout<<endl;
   cout<<p[i].salary;
  }
  return 0;
}



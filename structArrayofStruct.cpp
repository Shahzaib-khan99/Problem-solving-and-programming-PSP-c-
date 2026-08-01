#include <iostream>
using namespace std;
const int size=3;
struct Person
{
    //char name[50];
    int age;
    float salary;
};


int main()
{
   Person p[size];
// input data in array of record/ struct
   for(int i=0; i<size;i++)
	   {
	   	cout << "Enter age of person "<<i+1<<"=";
	    cin >> p[i].age;
	    cout << "Enter salary of person "<<i+1<<"=";
	    cin >> p[i].salary;
	   }
    // display data in array of record/ struct

    for(int i=0; i<size;i++)
	   {
	   	cout<<"\nAge of person "<<i+1<<"="<<p[i].age;
	    cout<<"\nSalary of person "<<i+1<<"="<<p[i].salary;
	    
	   }

    return 0;
}



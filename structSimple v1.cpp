#include <iostream>
#include <stdio.h>
#include <cctype>
#include <cstring>
#include <cstdlib>

using namespace std;

struct Person
{
    char name[50];
    int age;
    float salary;
};

int main()
{
   
  
  Person p1,p2;
  char ag[10];
  char sal[10];
  
 
    cout << "Enter Full name: ";
    gets(p1.name);
    cout << "Enter age: ";
    gets(ag);
    p1.age=atoi(ag);
    //cin >> p1.age;
    cout << "Enter salary: ";
    gets(sal);
    p1.age=atof(sal);
    //cin >> p1.salary;
    

    // Function call with structure variable as an argument
    cout << "\nDisplaying Information." << endl;
    cout << "Name: " << p1.name << endl;
    cout <<"Age: " << p1.age << endl;
    cout << "Salary: " << p1.salary;

    return 0;
}



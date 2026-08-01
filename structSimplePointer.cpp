#include <iostream>
#include <stdio.h>
#include <cctype>
#include <cstring>
using namespace std;

struct Person
{
    char name[50];
    int age;
    float salary;
};

int main()
{
  Person p2={"muhammad ali", 34, 55000};
  
  Person *ptr;
  ptr=&p2;
  //ptr->age=66;  
    (*ptr).age=66;
  //strcpy(ptr->name,"haider khan");
 // ptr->age=25;	//		(*ptr).age=25
 // ptr->salary=44000;
  
	//cout << "Enter Full name: ";
    //cin.get(p1.name, 50);
    /*gets(p1.name);
    
    cout << "Enter age: ";
    cin >> p1.age;
    cout << "Enter salary: ";
    cin >> p1.salary;*/

    // Function call with structure variable as an argument
    cout << "\nDisplaying Information." << endl;
    cout << "Name: " << ptr->name << endl;
    cout <<"Age: " << ptr->age << endl;
    cout << "Salary: " << ptr->salary;

    return 0;
}



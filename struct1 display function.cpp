#include <iostream>
using namespace std;

struct Person
{
    char name[50];
    int age;
    float salary;
};

void displayData(Person);   // Function prototype/declaration

int main()
{
   
   Person p={"ali ahmad", 23, 4567};
  /*  Person p;

    cout << "Enter Full name: ";
    cin.get(p.name, 50);
    cout << "Enter age: ";
    cin >> p.age;
    cout << "Enter salary: ";
    cin >> p.salary;*/

    // Function call with structure variable as an argument
    displayData(p);

    return 0;
}

void displayData(Person p1)
{
    cout << "\nDisplaying Information." << endl;
    cout << "Name: " << p1.name << endl;
    cout <<"Age: " << p1.age << endl;
    cout << "Salary: " << p1.salary;
}

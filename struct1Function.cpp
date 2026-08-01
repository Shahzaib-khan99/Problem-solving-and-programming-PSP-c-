#include <iostream>
using namespace std;

struct Person
{
    char name[50];
    int age;
    float salary;
};

void displayData( Person);   // Function declaration or function prototype
void displayData(Person p)  //function definition
{
    cout << "\nDisplaying Information." << endl;
    cout << "Name: " << p.name << endl;
    cout <<"Age: " << p.age << endl;
    cout << "Salary: " << p.salary;
}
int main()
{
   
   //Person p1={"ali ahmad", 23, 20000};
  Person p1;

    cout << "Enter Full name: ";
    //cin.get(p1.name, 50);
    gets(p1.name);
    cout << "Enter age: ";
    cin >> p1.age;
    cout << "Enter salary: ";
    cin >> p1.salary;

    // Function call with structure variable as an argument
    displayData(p1);// function call

    return 0;
}



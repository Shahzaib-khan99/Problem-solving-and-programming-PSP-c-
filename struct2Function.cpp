
/////Returning structure from function in C++
#include <iostream>
using namespace std;

struct Person {
    char name[50];
    int age;
    float salary;
};

Person getData(Person); //function prototype

void displayData(Person); //function prototype

Person getData(Person p) 
{
    cout << "Enter Full name: ";
    cin.get(p.name, 50);
    cout << "Enter age: ";
    cin >> p.age;
    cout << "Enter salary: ";
    cin >> p.salary;
return p;
}

void displayData(Person p1)
{
    cout << "\nDisplaying Information." << endl;
    cout << "Name: " << p1.name << endl;
    cout <<"Age: " << p1.age << endl;
    cout << "Salary: " << p1.salary;
}
int main()
{
	Person p2;

    p2 = getData(p2);   
    displayData(p2);

    return 0;
}



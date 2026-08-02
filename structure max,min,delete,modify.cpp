#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

struct Employee {
    char name[50];
    int id;
    double salary;
    char gender;
};

const int size = 5;
Employee emp[size]; 

void inputEmployees() {
    for (int i = 0; i < size; i++) {
        cout << "Enter Name of employee " << i + 1 << ": ";
        cin.ignore();
        cin.getline(emp[i].name, 50);
        cout << "Enter ID of employee " << i + 1 << ": ";
        cin >> emp[i].id;
        cout << "Enter Salary of employee " << i + 1 << ": ";
        cin >> emp[i].salary;
        cout << "Enter Gender of employee " << i + 1 << " (m/f): ";
        cin >> emp[i].gender;
    }
}

void displayEmployees() {
    cout << "Name\t\tID\t\tSalary\t\tGender\n";
    for (int i = 0; i < size; i++) {
        if (emp[i].id != -1) { 
            cout << emp[i].name << "\t\t" << emp[i].id << "\t\t" << emp[i].salary << "\t\t" << emp[i].gender << endl;
        }
    }
}

void findMaxMinSalary() {
    double max = INT_MIN, min = INT_MAX;
    int maxIndex = -1, minIndex = -1;

    for (int i = 0; i < size; i++) {
        if (emp[i].gender == 'm' && emp[i].salary > max) {
            max = emp[i].salary;
            maxIndex = i;
        }
        if (emp[i].gender == 'f' && emp[i].salary < min) {
            min = emp[i].salary;
            minIndex = i;
        }
    }

    if (maxIndex != -1) {
        cout << "\nMale Employee with Maximum Salary:\n";
        cout << emp[maxIndex].name << "\t\t" << emp[maxIndex].id << "\t\t" << emp[maxIndex].salary << "\t\t" << emp[maxIndex].gender << endl;
    }

    if (minIndex != -1) {
        cout << "\nFemale Employee with Minimum Salary:\n";
        cout << emp[minIndex].name << "\t\t" << emp[minIndex].id << "\t\t" << emp[minIndex].salary << "\t\t" << emp[minIndex].gender << endl;
    }
}

void modifyEmployee() {
    int searchId;
    cout << "Enter the ID of the employee to modify: ";
    cin >> searchId;

    for (int i = 0; i < size; i++) {
        if (emp[i].id == searchId) {
            cout << "Enter New Name: ";
            cin.ignore();
            cin.getline(emp[i].name, 50);
            cout << "Enter New Salary: ";
            cin >> emp[i].salary;
            cout << "Enter New Gender (m/f): ";
            cin >> emp[i].gender;
            cout << "Record updated successfully.\n";
            return;
        }
    }
    cout << "Employee with ID " << searchId << " not found.\n";
}

void deleteEmployee() {
    int searchId;
    cout << "Enter the ID of the employee to delete: ";
    cin >> searchId;

    for (int i = 0; i < size; i++) {
        if (emp[i].id == searchId) {
            emp[i].id = -1; 
            cout << "Employee record deleted successfully.\n";
            return;
        }
    }
    cout << "Employee with ID " << searchId << " not found.\n";
}
 
int main() {
    inputEmployees();

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Display All Employees\n";
        cout << "2. Find Maximum and Minimum Salary\n";
        cout << "3. Modify Employee Record\n";
        cout << "4. Delete Employee Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                displayEmployees();
                break;
            case 2:
                findMaxMinSalary();
                break;
            case 3:
                modifyEmployee();
                break;
            case 4:
                deleteEmployee();
                break;
            case 5:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}


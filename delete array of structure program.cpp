#include<iostream>
#include<climits>
using namespace std;

struct employee {
    char name[50];
    int id;
    double salary;
    char gender;
};

void employeedelete(employee emp[], int n) {
    int searchid;
    cout << "Enter the ID of employee to delete: ";
    cin >> searchid;

    bool found = false;  
    for (int i = 0; i < n; i++) {
        if (emp[i].id == searchid) {
            emp[i].id = -1;  
            found = true;
            cout << "Record with ID " << searchid << " is found and deleted." << endl;
            break;
        }
    }

    if (!found) {
        cout << "Your record ID is not found." << endl;
    }
}

int main() {
    const int size = 5;
    employee emp[size]; 

    
    for (int i = 0; i < size; i++) {
        cout << "Enter Name of employee " << i + 1 << " = ";
        cin.ignore();  
        cin.getline(emp[i].name, 50);

        cout << "Enter ID of employee " << i + 1 << " = ";
        cin >> emp[i].id;

        cout << "Enter Salary of employee " << i + 1 << " = ";
        cin >> emp[i].salary;

        cout << "Enter Gender of employee " << i + 1 << " = ";
        cin >> emp[i].gender;
    }

    
    
    employeedelete(emp, size);

    return 0;
}
  
  
  cout<<"displaying the id of employee";
  

  
  for(int i=0;i<n;i++)
  
  {
  	cout<<emp[i].name; cout<<endl;
  	cout<<emp[i].id; cout<<endl;
  	cout<<emp[i].salary; cout<<endl;
  	cout<<emp[i].gender; cout<<endl;
  }

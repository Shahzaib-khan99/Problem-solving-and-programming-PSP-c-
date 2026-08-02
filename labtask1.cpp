#include <iostream>
using namespace std;
int main() 
{
    int size;
    cout << "Enter the number of products in the store: ";
    cin >> size;

  
    int *inventory = new int[size];

  
    cout << "Enter the quantity for each product:\n";
    for (int i = 0; i < size; i++) {
        cout << "Product " << i + 1 << ": ";
        cin >> inventory[i];
    }

    int choice;
    
        cout << "\nMenu:\n";
        cout << "1. Add a new product\n";
        cout << "2. Remove a product\n";
        cout << "3. Update a product quantity\n";
        cout << "4. Display inventory\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
return 0;
}

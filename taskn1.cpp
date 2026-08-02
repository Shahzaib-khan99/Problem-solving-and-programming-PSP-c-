#include <iostream>
using namespace std;

void displayInventory(int *inventory, int size) {
    cout << "\nCurrent Inventory:\n";
    for (int i = 0; i < size; i++) {
        cout << "Product " << i + 1 << ": " << inventory[i] << " units\n";
    }
}

int main() {
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
    do {
        cout << "\nMenu:\n";
        cout << "1. Add a new product\n";
        cout << "2. Remove a product\n";
        cout << "3. Update a product quantity\n";
        cout << "4. Display inventory\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { 
                int newSize = size + 1;
                int *newInventory = new int[newSize];

              
                for (int i = 0; i < size; i++) {
                    newInventory[i] = inventory[i];
                }

               
                cout << "Enter quantity for new product: ";
                cin >> newInventory[newSize - 1];

                delete[] inventory;
                inventory = newInventory;
                size = newSize;
                break;
            }

            case 2: { 
                int index;
                cout << "Enter product number to remove (1-" << size << "): ";
                cin >> index;
                index--;

                if (index < 0 || index >= size) {
                    cout << "Invalid index!\n";
                    break;
                }

                int newSize = size - 1;
                int *newInventory = new int[newSize];

               
                for (int i = 0, j = 0; i < size; i++) {
                    if (i != index) {
                        newInventory[j++] = inventory[i];
                    }
                }

                delete[] inventory;
                inventory = newInventory;
                size = newSize;
                break;
            }

            case 3: { 
                int index, newQty;
                cout << "Enter product number to update (1-" << size << "): ";
                cin >> index;
                index--;

                if (index < 0 || index >= size) {
                    cout << "Invalid index!\n";
                    break;
                }

                cout << "Enter new quantity: ";
                cin >> newQty;
                inventory[index] = newQty;
                break;
            }

            case 4: 
                displayInventory(inventory, size);
                break;

            case 5 :
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    
    delete[] inventory;

    return 0;
}


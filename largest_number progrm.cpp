#include <iostream>
using namespace std;

int main() {
    int arr[10];
    int largest;

    cout << "Enter 10 integers: ";
    for (int i = 0; i < 10; i++) {
        cin >> arr[i];
    }

    largest = arr[0];

    for (int i = 1; i < 10; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    cout << "The largest element is: " << largest << endl;

    return 0;
}

#include <iostream>
#include <cstring> // Provides strcpy(), strcmp(), etc.
#include <cctype>  // Provides toupper(), tolower(), etc.
using namespace std;

const int MAX_SIZE = 10;      // Maximum number of students
const int NAME_LENGTH = 27;   // Maximum length of a student's name

struct Student {
    char name[NAME_LENGTH]; // Name of student
    int student_number;     // Student number of student
    float gpa;              // Grade point average of student
};

Student students[MAX_SIZE] = {
    {"Hassan", 66, 3.9},
    {"Ali", 40, 3.2},
    {"Hammad", 30, 3.1},
    {"Hamid", 5, 3.8},
    {"Haris", 1, 3.1}
};
int currentSize = 5; // Current number of students

// Function prototypes
void displayStudents(const Student[], int);
void searchStudent(const Student[], int, const char[]);
void deleteStudent(Student[], int&);
void modifyStudent(Student[], int);
void addStudent(Student[], int&);

int main() {
    int choice;
    char searchName[NAME_LENGTH];

    do {
        cout << "\n====== Student Management System ======\n";
        cout << "1. Display All Students\n";
        cout << "2. Search Student\n";
        cout << "3. Add Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Modify Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore leftover newline character

        switch (choice) {
            case 1:
                displayStudents(students, currentSize);
                break;
            case 2:
                cout << "Enter student name to search: ";
                cin.getline(searchName, NAME_LENGTH);
                searchStudent(students, currentSize, searchName);
                break;
            case 3:
                addStudent(students, currentSize);
                break;
            case 4:
                deleteStudent(students, currentSize);
                break;
            case 5:
                modifyStudent(students, currentSize);
                break;
            case 6:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

// Function to display all students
void displayStudents(const Student students[], int size) {
    if (size == 0) {
        cout << "No students to display.\n";
        return;
    }

    cout << "====== Student Records ======\n";
    cout << "Name\t\tStudent No\tGPA\n";
    cout << "==================================\n";
    for (int i = 0; i < size; i++) {
        cout << students[i].name << "\t\t"
             << students[i].student_number << "\t"
             << students[i].gpa << endl;
    }
}


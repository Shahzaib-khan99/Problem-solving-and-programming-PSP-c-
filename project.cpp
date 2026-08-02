#include <iostream>
#include <iomanip> // For setw
#include <cstring> // For strcpy, strcmp
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
    cout << left << setw(20) << "Name"
         << setw(15) << "Student No"
         << setw(5) << "GPA" << endl;
    cout << "--------------------------------------\n";
    for (int i = 0; i < size; i++) {
        cout << left << setw(20) << students[i].name
             << setw(15) << students[i].student_number
             << setw(5) << students[i].gpa << endl;
    }
}

// Function to search for a student by name
void searchStudent(const Student students[], int size, const char searchName[]) {
    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            cout << "Student Found:\n";
            cout << "Name: " << students[i].name << "\n";
            cout << "Student Number: " << students[i].student_number << "\n";
            cout << "GPA: " << students[i].gpa << "\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// Function to delete a student by name
void deleteStudent(Student students[], int& size) {
    if (size == 0) {
        cout << "No students to delete.\n";
        return;
    }

    char nameToDelete[NAME_LENGTH];
    cout << "Enter the name of the student to delete: ";
    cin.getline(nameToDelete, NAME_LENGTH);

    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, nameToDelete) == 0) {
            for (int j = i; j < size - 1; j++) {
                students[j] = students[j + 1];
            }
            size--;
            cout << "Student deleted successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// Function to modify a student's details
void modifyStudent(Student students[], int size) {
    char nameToModify[NAME_LENGTH];
    cout << "Enter the name of the student to modify: ";
    cin.getline(nameToModify, NAME_LENGTH);

    for (int i = 0; i < size; i++) {
        if (strcmp(students[i].name, nameToModify) == 0) {
            cout << "Enter new name: ";
            cin.getline(students[i].name, NAME_LENGTH);
            cout << "Enter new student number: ";
            cin >> students[i].student_number;
            cout << "Enter new GPA: ";
            cin >> students[i].gpa;
            cin.ignore(); // Clear newline from buffer
            cout << "Student modified successfully.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

// Function to add a new student
void addStudent(Student students[], int& size) {
    if (size >= MAX_SIZE) {
        cout << "Cannot add more students. Maximum limit reached.\n";
        return;
    }

    cout << "Enter name of the student: ";
    cin.getline(students[size].name, NAME_LENGTH);
    cout << "Enter student number: ";
    cin >> students[size].student_number;
    cout << "Enter GPA: ";
    cin >> students[size].gpa;
    cin.ignore(); // Clear newline from buffer
    size++;
    cout << "Student added successfully.\n";
}

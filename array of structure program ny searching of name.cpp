#include <iostream>
#include <iomanip>
#include <cstring>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
using namespace std;

//////////////////////////////////////
// Function Prototypes
//////////////////////////////////////
void gotoxy(short, short);
void display();
void add();
void search();
void sort();
void del();
void modify();

struct employee {
    char name[40];
    int id;
    int salary;
    int rank;
};

employee emp[50];
int n = 0;

//////////////////////////////////////
// Main Function
//////////////////////////////////////
int main() {
    char ch;
    while (1) {
        system("cls");
        cout << setw(25) << "-------------" << endl
             << setw(25) << "| MAIN MENU |" << endl
             << setw(25) << "-------------" << endl
             << endl
             << setw(52)
             << "Please choose one of the options below: " << endl
             << setw(71)
             << "--------------------------------------------------------------" << endl
             << endl
             << setw(25) << "( A ) Add Record" << endl
             << setw(31) << "( O ) Sort All Records" << endl
             << setw(34) << "( S ) Search for a Record" << endl
             << setw(31) << "( D ) Display Records" << endl
             << setw(32) << "( T ) Delete Record" << endl
             << setw(28) << "( M ) Update Record" << endl
             << setw(19) << "( Q ) Quit" << endl
             << endl
             << setw(30) << "Enter Option [ ]" << endl;

        gotoxy(28, 21);
        ch = getche();

        switch (ch) {
            case 'a':
            case 'A':
                add();
                break;
            case 'o':
            case 'O':
                sort();
                break;
            case 's':
            case 'S':
                search();
                break;
            case 'd':
            case 'D':
                display();
                break;
            case 't':
            case 'T':
                del();
                break;
            case 'm':
            case 'M':
                modify();
                break;
            case 'q':
            case 'Q':
                exit(0);
                break;
            default:
                cout << "\nPlease enter a valid option from the list.\n";
                getch();
        }
    }
    return 0;
}

//////////////////////////////////////
// Function Definitions
//////////////////////////////////////

// Display Function
void display() {
    system("cls");
    cout << "Employee Records:\n";
    cout << setw(15) << "Name" << setw(15) << "ID" << setw(15) << "Salary" << setw(15) << "Rank" << endl;
    cout << setw(15) << "-----" << setw(15) << "---" << setw(15) << "------" << setw(15) << "----" << endl;

    for (int i = 0; i < n; i++) {
        cout << setw(15) << emp[i].name << setw(15) << emp[i].id << setw(15) << emp[i].salary << setw(15) << emp[i].rank << endl;
    }
    cout << "Press Enter to return to the main menu...";
    getch();
}

// Add Function
void add() {
    char ch;
    do {
        system("cls");
        cout << "Add New Employee Record:\n";

        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(emp[n].name, 40);

        cout << "Enter ID: ";
        cin >> emp[n].id;

        cout << "Enter Salary: ";
        cin >> emp[n].salary;

        cout << "Enter Rank: ";
        cin >> emp[n].rank;

        n++;
        cout << "Do you want to add another record? (y/n): ";
        ch = getche();
    } while (ch == 'y' || ch == 'Y');
}

// Search Function
void search() {
    system("cls");
    char sname[40];
    cout << "Search Employee Record:\n";
    cout << "Enter Name to Search: ";
    cin.ignore();
    cin.getline(sname, 40);

    int flag = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(emp[i].name, sname) == 0) {
            flag = 1;
            cout << "Record Found:\n";
            cout << "Name: " << emp[i].name << "\nID: " << emp[i].id
                 << "\nSalary: " << emp[i].salary << "\nRank: " << emp[i].rank << endl;
            break;
        }
    }
    if (!flag) {
        cout << "Record Not Found.\n";
    }
    cout << "Press Enter to return to the main menu...";
    getch();
}

// Sort Function
void sort() {
    cout << "Sort Functionality Under Construction.\n";
    getch();
}

// Delete Function
void del() {
    cout << "Delete Functionality Under Construction.\n";
    getch();
}

// Modify Function
void modify() {
    cout << "Modify Functionality Under Construction.\n";
    getch();
}

// Gotoxy Function
void gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


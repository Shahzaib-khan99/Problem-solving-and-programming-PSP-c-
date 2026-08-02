#include<iostream>
#include<iomanip>
#include<fstream>
#include<conio.h>
#include<cstring>
#include<stdio.h>
#include<cstdlib>
#include<windows.h>
using namespace std;

//////////////////////////////////////
//////function prototypes/////////////
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
};

struct employee emp[50];
int n = 0;

//////////////////////////////////////
///////////////////main///////////////                                                       
/////////////////////////////////////
int main() {
    char ch1;
    while (1) {
        system("cls");

        cout << setw(25) << "-------------" << endl
             << setw(25) << "| MAIN MENU |" << endl
             << setw(25) << "-------------" << endl << endl
             << setw(52) << "Please choose one of the options below: " << endl
             << setw(71) << "--------------------------------------------------------------" << endl << endl
             << setw(25) << "( A ) add record" << endl << endl
             << setw(31) << "( O ) sort all records" << endl << endl
             << setw(34) << "( S ) search for a record" << endl << endl
             << setw(31) << "( D ) display a record" << endl << endl
             << setw(32) << "( T ) delete / undelete" << endl << endl
             << setw(28) << "( M ) update record" << endl << endl
             << setw(19) << "( Q ) Quit" << endl << endl
             << setw(30) << "Enter Option      [ ]" << endl << endl;

        gotoxy(28, 21);
        
        switch (getche()) {
            case 'a':
            case 'A': add(); break;
            case 'd':
            case 'D': display(); break;
            case 's':
            case 'S': search(); break;
            case 't':
            case 'T': del(); break;
            case 'o':
            case 'O': sort(); break;
            case 'm':
            case 'M': modify(); break;
            case 'q':
            case 'Q': exit(0); break;
            default: puts("\nEnter only from selection listed");
        }
    }
    return 0;
}

//////////////////////////////////////
///////////////////Display///////////////
/////////////////////////////////////
void display(void) {
    system("cls");
    cout << "In display function\n";
    cout << setw(15) << "Name:" << setw(15) << "Id:" << setw(15) << "Salary" << "\n";
    cout << setw(15) << "-------" << setw(15) << "-------" << setw(15) << "-------" << "\n";
    for (int i = 0; i < n; i++) {
        cout << setw(15) << emp[i].name << setw(15) << emp[i].id << setw(15) << emp[i].salary << "\n";
    }
    cout << "Press enter to go to main menu.....";
    getch();
}

//////////////////////////////////////
///////////////////Add///////////////
/////////////////////////////////////
void add(void) {
    char ch;
    do {
        system("cls");
        cout << endl << "In ADD function\n";
        cout << "Enter name: ";
        cin.ignore();
        cin.getline(emp[n].name, 40);
        cout << "Enter ID: ";
        cin >> emp[n].id;
        cout << "Enter the salary: ";
        cin >> emp[n].salary;
        n++;
        cout << "Do you want to add more records [y/n]: ";
        ch = getche();
    } while (ch != 'n' && ch != 'N');
}

//////////Search////////////////////
void search() {
    system("cls");
    char searchName[40];
    int searchId, found = 0;

    cout << "Enter the name or ID to search: ";
    cin.ignore();
    cin.getline(searchName, 40);

    for (int i = 0; i < n; i++) {
        if (strcmp(emp[i].name, searchName) == 0 || emp[i].id == atoi(searchName)) {
            cout << "Record found: \n";
            cout << setw(15) << "Name:" << setw(15) << "Id:" << setw(15) << "Salary" << "\n";
            cout << setw(15) << emp[i].name << setw(15) << emp[i].id << setw(15) << emp[i].salary << "\n";
            found = 1;
        }
    }
    if (!found) {
        cout << "No record found!\n";
    }
    cout << "Press enter to go to main menu.....";
    getch();
}

//////////Sort///////////////////////
void sort() {
    system("cls");
    struct employee temp;

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (emp[i].id > emp[j].id) {
                temp = emp[i];
                emp[i] = emp[j];
                emp[j] = temp;
            }
        }
    }
    cout << "Records sorted by ID.\n";
    cout << "Press enter to go to main menu.....";
    getch();
}

////////////Delete//////////////////////
void del() {
    system("cls");
    char delName[40];
    int delId, found = 0;

    cout << "Enter the name or ID to delete: ";
    cin.ignore();
    cin.getline(delName, 40);

    for (int i = 0; i < n; i++) {
        if (strcmp(emp[i].name, delName) == 0 || emp[i].id == atoi(delName)) {
            for (int j = i; j < n - 1; j++) {
                emp[j] = emp[j + 1];
            }
            n--;
            found = 1;
            cout << "Record deleted successfully!\n";
            break;
        }
    }
    if (!found) {
        cout << "No record found to delete!\n";
    }
    cout << "Press enter to go to main menu.....";
    getch();
}

///////////Modify//////////////////////
void modify() {
    system("cls");
    char modName[40];
    int modId, found = 0;

    cout << "Enter the name or ID to modify: ";
    cin.ignore();
    cin.getline(modName, 40);

    for (int i = 0; i < n; i++) {
        if (strcmp(emp[i].name, modName) == 0 || emp[i].id == atoi(modName)) {
            cout << "Record found. Enter new details:\n";
            cout << "Enter new name: ";
            cin.getline(emp[i].name, 40);
            cout << "Enter new ID: ";
            cin >> emp[i].id;
            cout << "Enter new salary: ";
            cin >> emp[i].salary;
            found = 1;
            cout << "Record modified successfully!\n";
            break;
        }
    }
    if (!found) {
        cout << "No record found to modify!\n";
    }
    cout << "Press enter to go to main menu.....";
    getch();
}

////////////////////////////////////////
/////////////////gotoxy //////////////////////////
void gotoxy(short x, short y) {
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}


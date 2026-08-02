
#include <iostream>
#include <string>
using namespace std;

// Book class
class Book {
private:
    int id;
    string title;
    string author;
    bool available;

public:
    // Constructor
    Book(int i = 0, string t = "", string a = "") {
        id = i;
        title = t;
        author = a;
        available = true;
    }

    // Function to display book details
    void display() {
        cout << "ID: " << id
            << " | Title: " << title
            << " | Author: " << author
            << " | Status: " << (available ? "Available" : "Issued")
            << endl;
        cout <<" ......................................................................................." << endl;
    }

    // Getters
    int getId() { return id; }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    bool isAvailable() { return available; }

    // Borrow book
    void issueBook() {
        if (available) {
            available = false;
            cout << "Book issued successfully!\n";
            cout << "..................................................................................." << endl;
        }
        else {
            cout << "Sorry, this book is already issued!\n";
            cout << "..................................................................................." << endl;
        }
    }

    // Return book
    void returnBook() {
        if (!available) {
            available = true;
            cout << "Book returned successfully!\n";
            cout << "..................................................................................." << endl;
        }
        else {
            cout << "This book was not issued!\n";
            cout << "..................................................................................." << endl;
        }
    }
};

// Library class
class Library {
private:
    Book books[50];
    int count;

public:
    Library() {
        count = 0;
    }

    // Add new book
    void addBook(int id, string title, string author) {
        books[count] = Book(id, title, author);
        count++;
        cout << "Book added successfully!\n";
        cout << "......................................................................................" << endl;
    }

    // Display all books
    void showBooks() {
        if (count == 0) {
            cout << "No books in library!\n";
            cout << ".................................................................................." << endl;
            return;
        }
        cout << "\n--- Library Books ---\n";
        cout << "......................................................................................" << endl;
        for (int i = 0; i < count; i++) {
            books[i].display();
        }
    }

    // Search book by title
    void searchBook(string title) {
        for (int i = 0; i < count; i++) {
            if (books[i].getTitle() == title) {
                cout << "Book found!\n";
                books[i].display();
                return;
            }
        }
        cout << "Book not found!\n";
        cout << "....................................................................................." << endl;
    }

    // Issue book by ID
    void issueBook(int id) {
        for (int i = 0; i < count; i++) {
            if (books[i].getId() == id) {
                books[i].issueBook();
                return;
            }
        }
        cout << "Book ID not found!\n";
        cout << "......................................................................................" << endl;
    }

    // Return book by ID
    void returnBook(int id) {
        for (int i = 0; i < count; i++) {
            if (books[i].getId() == id) {
                books[i].returnBook();
                return;
            }
        }
        cout << "Book ID not found!\n";
        cout << "....................................................................................." << endl;
    }
};

// Main function
int main() {
    Library lib;
    int choice, id;
    string title, author;

    do {
        cout << "....................................................................................................." << endl;
        cout << "\n--- Library Menu ---\n";
        cout << "....................................................................................................." << endl;
        cout << "1. Add Book\n";
        cout << "....................................................................................................." << endl;
        cout << "2. Show All Books\n";
        cout << "....................................................................................................." << endl;
        cout << "3. Search Book\n";
        cout << "....................................................................................................." << endl;
        cout << "4. Issue Book\n";
        cout << "....................................................................................................." << endl;
        cout << "5. Return Book\n";
        cout << "....................................................................................................." << endl;
        cout << "6. Exit\n";
        cout << "....................................................................................................." << endl;
        cout << "Enter your choice:\n ";
        cout << "....................................................................................................." << endl;
        cin >> choice;
        cout << "......................................................................................................." << endl;

        switch (choice) {
        case 1:
            cout << "Enter Book ID: ";
            cin >> id;
            cin.ignore();
            cout << "Enter Book Title: ";
            getline(cin, title);
            cout << "Enter Author Name: ";
            getline(cin, author);
            lib.addBook(id, title, author);
            break;

        case 2:
            lib.showBooks();
            break;

        case 3:
            cin.ignore();
            cout << "Enter Book Title to Search: ";
            getline(cin, title);
            lib.searchBook(title);
            break;

        case 4:
            cout << "Enter Book ID to Issue: ";
            cin >> id;
            lib.issueBook(id);
            break;

        case 5:
            cout << "Enter Book ID to Return: ";
            cin >> id;
            lib.returnBook(id);
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file


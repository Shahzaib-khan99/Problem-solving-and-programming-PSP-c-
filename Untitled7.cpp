
#include <bits/stdc++.h>
using namespace std;



// --------------------------- Configuration --------------------------------
const int MAX_STUDENTS = 300;    // maximum records in array (adjust if needed)
const string DATA_FILE = "students_big.csv"; // default CSV file for save/load
const int PAGE_SIZE = 8;         // for paginated display

// --------------------------- Structure ------------------------------------
struct Student {
    int rollNo;
    string name;
    int age;
    char gender;   // 'M', 'F', 'O' (other)
    float marks;   // numeric marks
    string contact;
    string address;
    string grade;  // computed grade A/B/C...
    bool valid;    // indicates if this record slot is used
};

// Simple undo buffer for last deleted student
struct UndoRecord {
    Student data;
    int index;     // position it was at
    bool exists;
};

// --------------------------- Global Data ----------------------------------
Student students[MAX_STUDENTS];
int studentCount = 0;
UndoRecord lastDeleted = { Student(), -1, false };

// --------------------------- Utility Helpers ------------------------------
void clearInput() {
    // clear remainder of input buffer
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string trim(const string &s) {
    // remove leading/trailing spaces
    size_t a = s.find_first_not_of(" \t\r\n");
    if (a == string::npos) return "";
    size_t b = s.find_last_not_of(" \t\r\n");
    return s.substr(a, b - a + 1);
}

string toLower(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    return s;
}

// --------------------------- Validation -----------------------------------
bool isRollExists(int roll) {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (students[i].valid && students[i].rollNo == roll) return true;
    }
    return false;
}

int findIndexByRoll(int roll) {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (students[i].valid && students[i].rollNo == roll) return i;
    }
    return -1;
}

int nextFreeIndex() {
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (!students[i].valid) return i;
    }
    return -1;
}

// --------------------------- Grade Computation -----------------------------
string computeGrade(float marks) {
    if (marks >= 85.0) return "A+";
    if (marks >= 75.0) return "A";
    if (marks >= 65.0) return "B";
    if (marks >= 50.0) return "C";
    if (marks >= 40.0) return "D";
    return "F";
}

// --------------------------- Display Helpers -------------------------------
void printHeaderLine() {
    cout << "+------+-------------------------------+-----+--------+--------+-----------------+-------------------------------+\n";
}

void printTableHeader() {
    printHeaderLine();
    cout << "| Roll | Name                          | Age | Gender | Marks  | Grade           | Contact                       |\n";
    printHeaderLine();
}

void printStudentRow(const Student &s) {
    // format and limit widths
    string name = s.name;
    if ((int)name.size() > 30) name = name.substr(0,27) + "...";
    string contact = s.contact;
    if ((int)contact.size() > 29) contact = contact.substr(0,26) + "...";

    cout << "| " << setw(4) << left << s.rollNo << " | "
         << setw(30) << left << name << " | "
         << setw(3) << right << s.age << " | "
         << setw(6) << right << s.gender << " | "
         << setw(6) << fixed << setprecision(2) << s.marks << " | "
         << setw(14) << left << s.grade << " | "
         << setw(29) << left << contact << " |\n";
}

// --------------------------- CRUD Operations -------------------------------

void addStudentSimple() {
    // Simple add (minimal prompts) for faster input
    if (studentCount >= MAX_STUDENTS) {
        cout << "Database is full! Max capacity reached.\n";
        return;
    }
    Student s;
    cout << "\n--- Add Student (Simple) ---\n";
    cout << "Enter roll number: ";
    while (!(cin >> s.rollNo)) {
        cout << "Invalid. Enter numeric roll number: ";
        clearInput();
    }
    if (isRollExists(s.rollNo)) {
        cout << "A student with this roll number already exists. Add aborted.\n";
        clearInput();
        return;
    }
    clearInput();
    cout << "Enter name: ";
    getline(cin, s.name);
    s.name = trim(s.name);
    cout << "Enter age: ";
    while (!(cin >> s.age)) {
        cout << "Invalid. Enter numeric age: ";
        clearInput();
    }
    cout << "Enter gender (M/F/O): ";
    cin >> s.gender;
    s.gender = toupper(s.gender);
    cout << "Enter marks: ";
    while (!(cin >> s.marks)) {
        cout << "Invalid. Enter numeric marks: ";
        clearInput();
    }
    clearInput();
    cout << "Enter contact: ";
    getline(cin, s.contact);
    cout << "Enter address: ";
    getline(cin, s.address);

    s.grade = computeGrade(s.marks);
    s.valid = true;

    int idx = nextFreeIndex();
    if (idx == -1) {
        cout << "Unexpected error: no free slot found.\n";
        return;
    }
    students[idx] = s;
    studentCount++;
    cout << "Student added successfully at slot " << idx << ".\n";
}

void addStudentDetailed() {
    // Detailed interactive add with confirmations
    if (studentCount >= MAX_STUDENTS) {
        cout << "Database is full! Max capacity reached.\n";
        return;
    }
    Student s;
    cout << "\n*** Add Student (Detailed) ***\n";
    cout << "(You can type 'cancel' in name to abort at any prompt)\n";
    cout << "Roll number: ";
    while (!(cin >> s.rollNo)) {
        cout << "Invalid. Enter numeric roll number: ";
        clearInput();
    }
    if (isRollExists(s.rollNo)) {
        cout << "Roll number already exists. Try modify or pick another roll.\n";
        clearInput();
        return;
    }
    clearInput();
    cout << "Full name: ";
    getline(cin, s.name);
    s.name = trim(s.name);
    if (toLower(s.name) == "cancel") { cout << "Add cancelled.\n"; return; }
    cout << "Age: ";
    while (!(cin >> s.age)) {
        cout << "Invalid. Enter numeric age: ";
        clearInput();
    }
    cout << "Gender (M/F/O): ";
    cin >> s.gender;
    s.gender = toupper(s.gender);
    cout << "Marks: ";
    while (!(cin >> s.marks)) {
        cout << "Invalid. Enter numeric marks: ";
        clearInput();
    }
    clearInput();
    cout << "Contact: ";
    getline(cin, s.contact);
    cout << "Address: ";
    getline(cin, s.address);

    s.grade = computeGrade(s.marks);
    s.valid = true;

    int idx = nextFreeIndex();
    students[idx] = s;
    studentCount++;
    cout << "Student added (index " << idx << ").\n";
}

void displayAllPaginated() {
    if (studentCount == 0) {
        cout << "No records to show.\n";
        return;
    }

    // Collect valid students into a temporary vector of indices for easy pagination
    vector<int> idxs;
    for (int i = 0; i < MAX_STUDENTS; ++i) if (students[i].valid) idxs.push_back(i);

    int total = (int)idxs.size();
    int pages = (total + PAGE_SIZE - 1) / PAGE_SIZE;
    int page = 0;

    while (true) {
        system(NULL); // noop but placeholder for cross-compat; not portable clear
        cout << "\n>>> Student Records — Page " << (page+1) << " of " << pages << "\n";
        printTableHeader();

        int start = page * PAGE_SIZE;
        int end = min(start + PAGE_SIZE, total);
        for (int i = start; i < end; ++i) {
            printStudentRow(students[idxs[i]]);
        }
        printHeaderLine();

        cout << "[n]ext page, [p]revious, [f]irst, [l]ast, [q]uit display: ";
        char c; cin >> c;
        c = tolower(c);
        if (c == 'n') {
            if (page < pages - 1) page++;
            else cout << "Already last page.\n";
        } else if (c == 'p') {
            if (page > 0) page--;
            else cout << "Already first page.\n";
        } else if (c == 'f') page = 0;
        else if (c == 'l') page = pages - 1;
        else if (c == 'q') break;
        else cout << "Unknown command.\n";
    }
    clearInput();
}

void displayAllSimple() {
    if (studentCount == 0) {
        cout << "No student records found.\n";
        return;
    }
    printTableHeader();
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (!students[i].valid) continue;
        printStudentRow(students[i]);
    }
    printHeaderLine();
}

void searchByRoll() {
    cout << "Enter roll number to search: ";
    int roll;
    while (!(cin >> roll)) {
        cout << "Invalid. Enter numeric roll: ";
        clearInput();
    }
    int idx = findIndexByRoll(roll);
    if (idx == -1) {
        cout << "No student with roll " << roll << ".\n";
        return;
    }
    printTableHeader();
    printStudentRow(students[idx]);
    printHeaderLine();
}

void searchByNamePartial() {
    clearInput();
    cout << "Enter name or part of name to search (case-insensitive): ";
    string q; getline(cin, q);
    q = toLower(trim(q));
    if (q.empty()) { cout << "No query entered.\n"; return; }

    bool found = false;
    printTableHeader();
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (!students[i].valid) continue;
        if (toLower(students[i].name).find(q) != string::npos) {
            printStudentRow(students[i]);
            found = true;
        }
    }
    if (!found) cout << "|            No matches found for the query.                                                  |\n";
    printHeaderLine();
}

void modifyStudentRecord() {
    cout << "Enter roll number to modify: ";
    int roll;
    while (!(cin >> roll)) {
        cout << "Invalid. Enter numeric roll: ";
        clearInput();
    }
    int idx = findIndexByRoll(roll);
    if (idx == -1) {
        cout << "Student not found.\n";
        return;
    }
    Student &s = students[idx];
    clearInput();
    cout << "\n--- Modifying student: " << s.name << " (Roll " << s.rollNo << ") ---\n";
    cout << "Leave a field blank to keep current value.\n";

    cout << "Current name: " << s.name << "\nNew name: ";
    string tmp;
    getline(cin, tmp);
    tmp = trim(tmp);
    if (!tmp.empty()) s.name = tmp;

    cout << "Current age: " << s.age << "\nNew age (blank to keep): ";
    string line;
    getline(cin, line);
    if (!trim(line).empty()) {
        try { s.age = stoi(trim(line)); } catch (...) { cout << "Invalid age, kept old.\n"; }
    }

    cout << "Current gender: " << s.gender << "\nNew gender (M/F/O blank): ";
    getline(cin, line);
    if (!trim(line).empty()) s.gender = toupper(line[0]);

    cout << "Current marks: " << s.marks << "\nNew marks (blank to keep): ";
    getline(cin, line);
    if (!trim(line).empty()) {
        try { s.marks = stof(trim(line)); } catch(...) { cout << "Invalid marks, kept old.\n"; }
    }

    cout << "Current contact: " << s.contact << "\nNew contact: ";
    getline(cin, line);
    if (!trim(line).empty()) s.contact = line;

    cout << "Current address: " << s.address << "\nNew address: ";
    getline(cin, line);
    if (!trim(line).empty()) s.address = line;

    s.grade = computeGrade(s.marks);

    cout << "Record updated.\n";
}

void deleteStudentRecord() {
    cout << "Enter roll number to delete: ";
    int roll;
    while (!(cin >> roll)) {
        cout << "Invalid. Enter numeric roll: ";
        clearInput();
    }
    int idx = findIndexByRoll(roll);
    if (idx == -1) {
        cout << "No student with that roll.\n";
        return;
    }
    cout << "Are you sure you want to delete " << students[idx].name << " (Roll " << roll << ")? (y/n): ";
    char c; cin >> c;
    if (c == 'y' || c == 'Y') {
        // save to undo buffer
        lastDeleted.data = students[idx];
        lastDeleted.index = idx;
        lastDeleted.exists = true;

        students[idx].valid = false;
        studentCount--;
        cout << "Student deleted (undo available).\n";
    } else {
        cout << "Delete cancelled.\n";
    }
}

// Undo last delete
void undoDelete() {
    if (!lastDeleted.exists) {
        cout << "Nothing to undo.\n";
        return;
    }
    if (students[lastDeleted.index].valid) {
        // slot used by new record; find new free slot
        int idx = nextFreeIndex();
        if (idx == -1) {
            cout << "Cannot undo: no free slot.\n";
            lastDeleted.exists = false;
            return;
        }
        students[idx] = lastDeleted.data;
        students[idx].valid = true;
        studentCount++;
        cout << "Undo completed, restored to slot " << idx << ".\n";
    } else {
        students[lastDeleted.index] = lastDeleted.data;
        students[lastDeleted.index].valid = true;
        studentCount++;
        cout << "Undo completed, restored to original slot " << lastDeleted.index << ".\n";
    }
    lastDeleted.exists = false;
}

// --------------------------- Sorting --------------------------------------
void swapStudentSlots(int a, int b) {
    Student tmp = students[a];
    students[a] = students[b];
    students[b] = tmp;
}

// Simple bubble sort for the array using comparison lambda
void sortStudents(function<bool(const Student&, const Student&)> cmp) {
    // Collect indices of used slots to perform stable sorting by copying
    vector<Student> list;
    for (int i = 0; i < MAX_STUDENTS; ++i) if (students[i].valid) list.push_back(students[i]);

    // simple stable sort
    stable_sort(list.begin(), list.end(), cmp);

    // clear existing valid flags
    for (int i = 0; i < MAX_STUDENTS; ++i) students[i].valid = false;

    // write back from 0...list.size()-1
    int idx = 0;
    for (auto &s : list) {
        students[idx] = s;
        students[idx].valid = true;
        idx++;
    }
    // remaining slots already invalid
    cout << "Sorting completed. Use display to view sorted results.\n";
}

void sortMenu() {
    cout << "\n--- Sort Students ---\n";
    cout << "1) By roll (ascending)\n";
    cout << "2) By roll (descending)\n";
    cout << "3) By name (A-Z)\n";
    cout << "4) By name (Z-A)\n";
    cout << "5) By marks (high to low)\n";
    cout << "6) By marks (low to high)\n";
    cout << "Choice: ";
    int ch; cin >> ch;
    if (ch == 1) {
        sortStudents([](const Student &a, const Student &b){ return a.rollNo < b.rollNo; });
    } else if (ch == 2) {
        sortStudents([](const Student &a, const Student &b){ return a.rollNo > b.rollNo; });
    } else if (ch == 3) {
        sortStudents([](const Student &a, const Student &b){ return toLower(a.name) < toLower(b.name); });
    } else if (ch == 4) {
        sortStudents([](const Student &a, const Student &b){ return toLower(a.name) > toLower(b.name); });
    } else if (ch == 5) {
        sortStudents([](const Student &a, const Student &b){ return a.marks > b.marks; });
    } else if (ch == 6) {
        sortStudents([](const Student &a, const Student &b){ return a.marks < b.marks; });
    } else {
        cout << "Invalid choice.\n";
    }
}

// --------------------------- Statistics -----------------------------------
void statisticsReport() {
    if (studentCount == 0) {
        cout << "No data to compute statistics.\n";
        return;
    }
    float sum = 0.0, highest = -1.0, lowest = 9999.0;
    int pass = 0, fail = 0;
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (!students[i].valid) continue;
        sum += students[i].marks;
        if (students[i].marks > highest) highest = students[i].marks;
        if (students[i].marks < lowest) lowest = students[i].marks;
        if (students[i].marks >= 40.0) pass++; else fail++;
    }
    float avg = sum / studentCount;
    cout << fixed << setprecision(2);
    cout << "\n--- Statistics ---\n";
    cout << "Total students: " << studentCount << "\n";
    cout << "Average marks: " << avg << "\n";
    cout << "Highest marks: " << highest << "\n";
    cout << "Lowest marks: " << lowest << "\n";
    cout << "Pass: " << pass << " | Fail: " << fail << "\n";
}

// Show top N students by marks
void showTopN() {
    if (studentCount == 0) { cout << "No students.\n"; return; }
    cout << "Show top N students (enter N): ";
    int N; cin >> N;
    if (N <= 0) { cout << "Invalid N.\n"; return; }
    // Collect list and sort copy
    vector<Student> list;
    for (int i = 0; i < MAX_STUDENTS; ++i) if (students[i].valid) list.push_back(students[i]);
    sort(list.begin(), list.end(), [](const Student &a, const Student &b){ return a.marks > b.marks; });

    int show = min((int)list.size(), N);
    printTableHeader();
    for (int i = 0; i < show; ++i) printStudentRow(list[i]);
    printHeaderLine();
}

// --------------------------- File I/O -------------------------------------
string safeCSV(const string &s) {
    string out = s;
    // replace quotes with single quote to avoid breaking simple CSV
    for (char &c : out) if (c == '"') c = '\'';
    return out;
}

void saveToCSV(const string &filename = DATA_FILE) {
    ofstream fout(filename);
    if (!fout) {
        cout << "Error opening file for write: " << filename << "\n";
        return;
    }
    // header
    fout << "rollNo,name,age,gender,marks,grade,contact,address\n";
    for (int i = 0; i < MAX_STUDENTS; ++i) {
        if (!students[i].valid) continue;
        fout << students[i].rollNo << ","
             << "\"" << safeCSV(students[i].name) << "\"" << ","
             << students[i].age << ","
             << students[i].gender << ","
             << fixed << setprecision(2) << students[i].marks << ","
             << students[i].grade << ","
             << "\"" << safeCSV(students[i].contact) << "\"" << ","
             << "\"" << safeCSV(students[i].address) << "\"\n";
    }
    fout.close();
    cout << "Saved " << studentCount << " records to " << filename << "\n";
}

void loadFromCSV(const string &filename = DATA_FILE) {
    ifstream fin(filename);
    if (!fin) {
        cout << "File not found: " << filename << " (no data loaded)\n";
        return;
    }
    // clear existing data
    for (int i = 0; i < MAX_STUDENTS; ++i) students[i].valid = false;
    studentCount = 0;

    string line;
    getline(fin, line); // header
    while (getline(fin, line)) {
        // naive CSV parse (handles quoted fields)
        vector<string> fields;
        string cur;
        bool inQuotes = false;
        for (size_t i = 0; i < line.size(); ++i) {
            char c = line[i];
            if (c == '"' ) {
                inQuotes = !inQuotes;
            } else if (c == ',' && !inQuotes) {
                fields.push_back(cur);
                cur.clear();
            } else {
                cur.push_back(c);
            }
        }
        fields.push_back(cur);
        if (fields.size() < 8) continue; // skip malformed

        Student s;
        try {
            s.rollNo = stoi(trim(fields[0]));
            s.name = trim(fields[1]);
            s.age = stoi(trim(fields[2]));
            s.gender = trim(fields[3]).empty() ? 'O' : trim(fields[3])[0];
            s.marks = stof(trim(fields[4]));
            s.grade = trim(fields[5]);
            s.contact = trim(fields[6]);
            s.address = trim(fields[7]);
            s.valid = true;
            int idx = nextFreeIndex();
            if (idx == -1) break; // no space
            students[idx] = s;
            studentCount++;
        } catch (...) {
            // skip bad line
            continue;
        }
    }
    fin.close();
    cout << "Loaded " << studentCount << " records from " << filename << "\n";
}

// --------------------------- Sample Data ----------------------------------
void loadSampleData() {
    // clears existing and load ~20 sample entries for testing
    for (int i = 0; i < MAX_STUDENTS; ++i) students[i].valid = false;
    studentCount = 0;
    vector<Student> sample;

    vector<pair<string,float>> names = {
        {"Ali Khan", 88.5}, {"Sara Qureshi", 92.0}, {"Ahmed Raza", 76.5}, {"Zara Ali", 69.0},
        {"Hassan Mir", 54.0}, {"Ayesha Iqbal", 81.2}, {"Bilal Ahmed", 33.5}, {"Noor Javed", 46.0},
        {"Usman Noor", 59.5}, {"Maryam Khan", 74.4}, {"Sami Malik", 67.8}, {"Faiza N", 95.0},
        {"Imran Hashmi", 48.0}, {"Kiran S", 61.0}, {"Naveed Syed", 77.2}, {"Hira P", 85.6},
        {"Omar Farooq", 90.5}, {"Anum R", 39.0}, {"Tariq Aziz", 55.5}, {"Zainab M", 71.0}
    };

    int rollBase = 1001;
    for (size_t i = 0; i < names.size(); ++i) {
        Student s;
        s.rollNo = rollBase + (int)i;
        s.name = names[i].first;
        s.age = 17 + (int)(i % 6);
        s.gender = (i % 2 == 0) ? 'M' : 'F';
        s.marks = names[i].second;
        s.contact = "03xx-xxxxxxx";
        s.address = "City, Country";
        s.grade = computeGrade(s.marks);
        s.valid = true;
        int idx = nextFreeIndex();
        if (idx == -1) break;
        students[idx] = s;
        studentCount++;
    }
    cout << "Sample data loaded (" << studentCount << " records).\n";
}

// --------------------------- Help / About ---------------------------------
void showHelp() {
    cout << "\n=== Help: How to use Student Management System ===\n";
    cout << "1) Use menu numbers to select actions. Enter number and press Enter.\n";
    cout << "2) For searches you can use roll exact or partial name.\n";
    cout << "3) Save to CSV before exiting if you want to keep data.\n";
    cout << "4) Use undo delete to restore last deletion (single-level undo).\n";
    cout << "5) Sorting rearranges internal storage; display shows current order.\n";
}

// --------------------------- Main Menu -----------------------------------
void showMainMenu() {
    cout << R"(
  ===========================================================
   ____  _               _    _        _   _               _
  / ___|| |__   ___  ___| | _| |_ __ _| |_(_) ___  _ __   / \
  \___ \| '_ \ / _ \/ __| |/ / __/ _` | __| |/ _ \| '_ \ /  /
   ___) | | | |  __/ (__|   <| || (_| | |_| | (_) | | | /\\_/ 
  |____/|_| |_|\___|\___|_|\_\\__\__,_|\__|_|\___/|_| |_\/
  Student Management System (Array + struct) - Big Edition
  ===========================================================
    )" << "\n";
    cout << "1. Add Student (Simple)\n";
    cout << "2. Add Student (Detailed)\n";
    cout << "3. Display (Paginated)\n";
    cout << "4. Display (Simple Table)\n";
    cout << "5. Search by Roll\n";
    cout << "6. Search by Name (partial)\n";
    cout << "7. Modify Student\n";
    cout << "8. Delete Student\n";
    cout << "9. Undo last delete\n";
    cout << "10. Sort students\n";
    cout << "11. Statistics (average/high/low/pass-fail)\n";
    cout << "12. Show top N students\n";
    cout << "13. Save to CSV\n";
    cout << "14. Load from CSV\n";
    cout << "15. Load sample data\n";
    cout << "16. Help / How-to\n";
    cout << "17. About / Credits\n";
    cout << "0. Exit\n";
    cout << "Choose option: ";
}

// About
void about() {
    cout << "\nStudent Management System - Big Edition\n";
    cout << "Designed for learning: demonstrates struct, array, file I/O, sorting, and more.\n";
    cout << "Author: Generated by assistant. Use and modify freely for learning.\n";
    cout << "Note: Data stored in memory until saved to CSV.\n";
}

// --------------------------- Main ----------------------------------------
int main() {
    // initialize all slots to invalid
    for (int i = 0; i < MAX_STUDENTS; ++i) students[i].valid = false;
    studentCount = 0;
    lastDeleted.exists = false;

    // Auto-load if default file exists (optional)
    ifstream fin(DATA_FILE);
    if (fin.good()) {
        cout << "Default data file found (" << DATA_FILE << "). Load it? (y/n): ";
        char c; cin >> c;
        if (c == 'y' || c == 'Y') {
            loadFromCSV(DATA_FILE);
        } else {
            cout << "Starting with empty database.\n";
        }
    } else {
        cout << "No default data file. Starting fresh.\n";
    }

    while (true) {
        showMainMenu();
        int opt;
        if (!(cin >> opt)) {
            cout << "Invalid input. Please enter a number from menu.\n";
            clearInput();
            continue;
        }
        switch (opt) {
            case 1: addStudentSimple(); break;
            case 2: addStudentDetailed(); break;
            case 3: displayAllPaginated(); break;
            case 4: displayAllSimple(); break;
            case 5: searchByRoll(); break;
            case 6: searchByNamePartial(); break;
            case 7: modifyStudentRecord(); break;
            case 8: deleteStudentRecord(); break;
            case 9: undoDelete(); break;
            case 10: sortMenu(); break;
            case 11: statisticsReport(); break;
            case 12: showTopN(); break;
            case 13: {
                cout << "Enter filename to save (or press enter for default): ";
                clearInput();
                string fname;
                getline(cin, fname);
                fname = trim(fname);
                if (fname.empty()) saveToCSV(DATA_FILE);
                else saveToCSV(fname);
                break;
            }
            case 14: {
                cout << "Enter filename to load (or press enter for default): ";
                clearInput();
                string fname;
                getline(cin, fname);
                fname = trim(fname);
                if (fname.empty()) loadFromCSV(DATA_FILE);
                else loadFromCSV(fname);
                break;
            }
            case 15: loadSampleData(); break;
            case 16: showHelp(); break;
            case 17: about(); break;
            case 0: {
                cout << "Do you want to save data before exit? (y/n): ";
                char c; cin >> c;
                if (c == 'y' || c == 'Y') saveToCSV(DATA_FILE);
                cout << "Exiting. Goodbye!\n";
                return 0;
            }
            default: cout << "Invalid choice.\n";
        }
        // short pause for readability
        cout << "\n(Press Enter to continue...)";
        clearInput();
    }
    return 0;
}

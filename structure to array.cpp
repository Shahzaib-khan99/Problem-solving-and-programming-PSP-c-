 
 #include<iostream>
 using namespace std;
 
 
 struct Student {
    int rollNo;
    string name;
    float marks;
};

int main() {
    Student s[3]; 

    s[0] = {101, "Ali", 90.5};
    s[1] = {102, "Sara", 85.0};
    s[2] = {103, "Ahmed", 78.9};

    for(int i=0; i<3; i++){
        cout << s[i].rollNo << " " << s[i].name << " " << s[i].marks << endl;
    }
}

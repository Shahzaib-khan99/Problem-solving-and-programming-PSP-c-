  #include<iostream>
  using namespace std;
  struct Student {
    int rollNo;
    string name;
    float marks;

    void display() {
        cout << rollNo << " " << name << " " << marks << endl;
    }
};

int main() {
    Student s1 = {101, "Ali", 90.5};
    s1.display();  
}

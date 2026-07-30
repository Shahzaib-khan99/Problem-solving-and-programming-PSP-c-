  #include<iostream>
  using namespace std;
  
  
  
  struct Address {
    string city;
    int zip;
};

struct Student {
    int rollNo;
    string name;
    Address addr; // nested structure
};

int main() {
    Student s1 = {101, "Ali", {"Lahore", 54000}};
    cout << s1.name << " lives in " << s1.addr.city << endl;
}

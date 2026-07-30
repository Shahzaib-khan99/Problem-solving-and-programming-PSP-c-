   
   
   #include<iostream>
   using namespace std;
   
   struct Student {
    int rollNo;
    string name;
};

int main() {
    Student s1 = {101, "Ali"};
    Student *ptr = &s1;

    cout << ptr->rollNo << " " << ptr->name << endl; 
}

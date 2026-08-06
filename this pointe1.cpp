//this pointer

#include <iostream>  
using namespace std;  
class Employee {  
   public:  
       int id; //data member (also instance variable)      
       string name; //data member(also instance variable)  
       float salary;  
       Employee(int id, string name, float salary)   // constructor with parameter 
        {    
            this->id = id;    
            this->name = name;    
            this->salary = salary;   
        }    
       void display()    
        {    
            cout<<id<<"  "<<name<<"  "<<salary<<endl;    
        }    
};  
int main(void) {  
    Employee e1 =Employee(101, "Haris", 890000); //creating an object of Employee   
    Employee e2=Employee(102, "Nouman", 59000); //creating an object of Employee  
    e1.display();    
    e2.display();    
    return 0;  
}  

//To initialize the const value using constructor, we have to use the initialize list. 
//This initializer list is used to initialize the data member of a class.
#include <iostream>
using namespace std;
class MyClass{
   private:
      const int x;
   public:
      MyClass(int a) : x(a){
      //constructor
      //x=a;
   }
   void show_x(){
      cout << "Value of constant x: " << x ;
   }
};
int main() {
   MyClass ob1(40);
   ob1.show_x();
}

#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

const int MAX = 4;
 int MyFunction(int*, int );
int main () 
{

   int r, s = 5, t = 6;
   int *tp = &t;
   r = MyFunction(tp,s);
   cout<<"\nr="<<r;
   cout<<"\ntp="<<*tp;
   r = MyFunction(&t,s);
    cout<<"\nr="<<r;
    cout<<"\nt="<<t;
   r = MyFunction(&s,*tp);
   cout<<"\nr="<<r;
    cout<<"\sr="<<s;
}

int MyFunction(int *p, int i)
{
   *p = 3;
   i = 4;
   return i;
}

/*const char *names[MAX] = { "Zara Ali", "Hina Ali", "aiza Ali", "Sara Ali" };

   for (int i = 0; i < MAX; i++) {
      cout << "Value of names[" << i << "] = ";
      //cout << *(names + i) << endl;
      cout << names[i] << endl;
   }*/
   


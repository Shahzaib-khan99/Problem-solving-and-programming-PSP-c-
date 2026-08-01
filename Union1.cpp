//Pass structure to a function as a pointer

#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

union unionJob
{
   //defining a union
   char name[32];//32 bytes
   float salary;//4
   int workerNo;//4
} ;

struct structJob
{
   char name[32];//32
   float salary;//4
   int workerNo;//4
} ;

int main()
{	
	unionJob uJob;
	structJob sJob;
   cout<<"\nsize of union bytes="<< sizeof(uJob);
   cout<<"\nsize of structure bytes="<<sizeof(sJob);
   return 0;
}

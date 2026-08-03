#include<iostream>
using namespace std;
int main()
{
   int grade;
   cout<<"enter a grade";
   cin>> grade;
   if(grade>=90)   
   {
   
   cout<<"grade='A'";
}
else if(grade<90&& grade>=80)
{

   cout<<"grade= 'B'";
}    else  if (grade<80&&grade>=70)
{
	cout<<"grade='C'";

}
    else if(grade<70&&grade>=60)
    {
    cout<<"grade='D";
}
  else
    {
	cout<<"grade='F'";
}
	
}

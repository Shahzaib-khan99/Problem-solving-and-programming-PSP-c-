#include<iostream>

#include<climits>
using namespace std;



struct employee
{
	char name[40];
	int idno;
	int salary;
	char gender;
};

void employee(employee[],int count , int size);

 int main()
{

const int size=5;


for(int i=0;i<size;i++)
{
    cout<< "employee"<<i+1<<endl;	
}

cout<<"enter the name of employee";
cin.ignore();
cin.getline(employee[i].name,40);

cout<<"enter the idno of employee ";

cin>>employee[i].idno;

cout<<"enter the salary of employee";

cin>> employee[i].salary;

cout<<"enter the gender";

cin>>gender[i].gender;


}
 
 void employee_salary(employee employee[],int size){
 
 
int  highest Malesalary=INT_MIN;
 int lowest Female_salary=INT_MAX;
 
string highest Malesalary, string lowest Femalesalary;


for(i=0; i<size; i++){
	if(employee[i].gender=="M" || employee[i].gender=="m");
	{
	 if (employee[i].salary>highest Malesalary) 
	 
	 highest Malesalary=employee[i].salary;
	
	}
}
   
   if(employee[i].gender=="F" || employee[i].gender=="f")
   {
   	if (employee[i].salary< highest Femalesalary)
   	lowest Female_salary=employee[i].salary;
   
   }

}

  cout<<"Male employee with highest salary";
  
  if (Male employee!= INT_MAX){
  	cout<<"highest Male salary"<<Male salary<<endl;
  }
  else{
  	cout<<"Male salary not found";
  	
  }
  
  cout<<"Female employee with lowest salary";
if(Female employee!= INT_MAX) {
  	cout<<"lowest Female salary"<< Female salary<<endl;
  }
  else{
     cout<<" Female not found";	
  }
  
  
  cout<<"name\t\t"<< "idno\t\t"<<"salary\t\t"<<"gender\t\t";
  
  
  
  

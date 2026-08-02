s#include<iostream>
#include<climits>
using namespace std;

struct employee
{
	char name[50];
	int id;
	double salary;
	char  gender;
};
int main()

{  

const int size=5;
 int max,min,fe=0,ma=0;
 char female;
     max=INT_MIN;
     min =INT_MAX;
	employee emp[size];
	for(int i=0; i<size; i++)
	{
		cout<<"Enter  Name of employee " << i+1 <<" = ";
		gets(emp[i].name);
		cout<<"Enter  id of employee " << i+1 <<" = ";
		cin>>emp[i].id;
		cout<<"Enter  salary of employee " << i+1<<" = ";
	    cin>>emp[i].salary;
	    
		cout<<"Enter  Gender of employee " << i+1<<" = ";
	
	cin>>emp[i].gender;
      	cin.ignore();
	}
	
	// calculating maximum and minimum salary
		for(int i=0; i<size; i++)
		{
			
			
			if(emp[i].gender ==  'm')
			{
			  if(emp[i].salary>max)	
			  {
			  	max=emp[i].salary;
			  	ma=i;
			  }
			}
			else if(emp[i].gender ==  'f')
			{
				
			  if(emp[i].salary<min)	
			  {
			  	min=emp[i].salary;
			 
			  	fe=i;
			  }
			}
		}
	// for displaying data
		cout<<"Name\t\t"<<"id\t\t"<<"Salary\t\t"<<"Gender\n";
		
		
		for(int j=0; j<size; j++)
		{
			cout<<   emp[j].name<<"\t\t"   <<emp[j].id<<"\t\t"<< emp[j].salary<<"\t\t"<< emp[j].gender<<endl;		
		}
	  cout<<"Maximum salary of employee is   "<<max<<"  and their record is \n";
	  cout<<   emp[ma].name<<"\t\t"   <<emp[ma].id<<"\t\t"<< emp[ma].salary<<"\t\t"<< emp[ma].gender<<endl;		
	  cout<<"Manimum salary of employee is   "<<min<<"  and their record is \n";

	  
	  	cout<<   emp[fe].name<<"\t\t"   <<emp[fe].id<<"\t\t"<< emp[fe].salary<<"\t\t"<< emp[fe].gender<<endl;	
	  
	  		
		

		
	
	
}

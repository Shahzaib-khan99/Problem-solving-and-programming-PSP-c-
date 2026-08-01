#include<iostream>	

#include<cstring>	// Provides strcpy(), etc.
#include<cctype>	// Provides toupper()
using namespace std;

const int size = 3;	// Maximum of 5 students in class


struct student
{
	char name[27];			// Name of student
	int student_number;		// Student number of student
	float gpa;				// Grade point average of student
};


student stu[]={ {"hassan", 66,  3.9},
				{"ali"   , 40,  3.2}, 
				{"hammad", 30,  3.1}
			};


void Search(student[],int , int);// array of record, size of array of stuct, student number you want to search

int main()
{
	student s1[size]; int sn;
	
	
	
	cout<< "======Origional Record Displayed ==================\n\n\n";
	cout<< "Name\t student no\t GPA\n";
	cout<< "==================================\n\n";
	for(int i=0; i<size; i++)
	{
		cout << stu[i].name; cout<<"\t\t";			// Prints student name
					
		cout<< stu[i].student_number;cout<<"\t";	// Prints student number
						
		cout << stu[i].gpa << endl;					// Prints GPA
	}

	cout<<"\n\n enter student number you wanted to search=";
	cin>>sn;
	cout<< "===============================================\n";
	cout<< "====Calling Search Function====\n";

	Search(stu,size , sn);// calling search function
	cout<<"\n\n\n\n\n\n";

	
	return 0;
}


///////////////////////////////////////////////////////////
void Search(student s1[],int n, int sn)				//n=size of array of structure

{
    int flag=0, loc;
	for(int i = 0; i < n; i++)
    {
        if(s1[i].student_number == sn)
        {
            loc = i;
            flag=1;
            break;
        }
    }
    if (flag==1)
    	{	
    		cout<< "==================================\n";//stu[loc].student_number=78
    		cout<< "record found\n";			//strcpy(stu[loc].name, "ali hassan")
    		cout<< "==================================\n";
			cout<< "Name\t student no\t GPA\n";
			cout<< "==================================\n";
    		cout << stu[loc].name; cout<<"\t\t";			// Prints student name
					
			cout<< stu[loc].student_number;cout<<"\t";	// Prints student number
						
			cout << stu[loc].gpa << endl;		// Prints GPA
		}
	else 
		{
		cout<< "==================================\n";
		cout<<"\n\t\trecord not found\n";
		cout<< "==================================\n";
    	}
    
}


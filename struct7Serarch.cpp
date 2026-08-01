#include<iostream>	

#include<cstring>	// Provides strcpy(), etc.
#include<cctype>	// Provides toupper()
using namespace std;

//const int MAXNAMESIZE = 27;		// Allows for 26 characters in name and null character '\o'
const int MAXCLASSSIZE = 5;	// Maximum of 5 students in class
const char QUIT = 'Q';			// Allows user to quit program

struct student
{
	char name[27];			// Name of student
	int student_number;		// Student number of student
	double gpa;				// Grade point average of student
};


student stu[]={ {"hassan", 66,  3.9},
				{"ali"   , 40,  3.2}, 
				{"hammad", 30,  3.1}
			};


void Search(student[],int , int);// array of record, size of array of stuct, student number you want to search

void sort_on_name(student [], int n);

void sort_on_number(student [], int n);


int main()
{
student s1[3]; int sn;
cout<<"enter student no you wanted to search=";
cin>>sn;

cout<< "======Origional Record Displayed ==================\n";
cout<< "Name\t student no\t GPA\n";
	cout<< "========================\n";
	for(int i=0; i<3; i++)
	{
		cout << stu[i].name; cout<<"\t\t";			// Prints student name
					
		cout<< stu[i].student_number;cout<<"\t";	// Prints student number
						
		cout << stu[i].gpa << endl;		// Prints GPA
	}
cout<< "===============================================\n";
cout<< "===Calling Search Function==\n";

	Search(stu,3 , sn);// calling search function
	cout<<"\n\n\n\n\n\n";
//	cout<<"enter sn t"
	cout<< "====Calling Sort Function(by student number)====\n";
	sort_on_name( stu, 3);
	//sort_on_number( stu, 3);
	cout<<"\ndata after sorting by Name\n";
	cout<<"=====================\n";
		cout<< "Name\t student no\t GPA\n";
			cout<<"\n=====================\n";
	for( int i=0; i<3; i++)
	{
		cout << stu[i].name; cout<<"\t\t";			// Prints student name
					
		cout<< stu[i].student_number;cout<<"\t";	// Prints student number
						
		cout << stu[i].gpa << endl;		// Prints GPA
	}
	
	return 0;
}

void sort_on_name(student s[], int n)
{
	student temp;	// Local variable used to swap records

	for(int i=0; i<n; i++)
	{
		for(int i=0; i<n-1; i++)
		{
			// If s[i].name is later in alphabet than s[i+1].name, swap the two records
			if(strcmp(s[i].name,s[i+1].name) > 0)
			{
				temp = s[i];
				s[i] = s[i+1];
				s[i+1] = temp;
			}
		}
	}
}
////////////////////////////////////////////
void sort_on_number(student s[], int n)
{
	student temp;	// Local variable used to swap records

	for(int i=0; i<n; i++)
	{
		for(int i=0; i<n-1; i++)
		{
			// If s[i].student_number is greater than s[i+1].student_number, swap the records
			if(s[i].student_number > s[i+1].student_number)
			{
				temp = s[i];
				s[i] = s[i+1];
				s[i+1] = temp;
			}
		}
	}
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
    		cout<< "\t\t========================\n";//stu[loc].student_number=78
    		cout<< "\t\trecord found\n";			//strcpy(stu[loc].name, "ali hassan")
    		cout<< "\t\t========================\n";
			cout<< "\t\tName\t student no\t GPA\n";
			cout<< "\t\t========================\n";
    		cout << stu[loc].name; cout<<"\t\t";			// Prints student name
					
			cout<< stu[loc].student_number;cout<<"\t";	// Prints student number
						
			cout << stu[loc].gpa << endl;		// Prints GPA
		}
	else 
		{
		cout<< "========================\n";
		cout<<"\n\t\trecord not found\n";
		cout<< "========================\n";
    	}
    
}


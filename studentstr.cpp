#include<iostream>
using namespace std;

struct student{
	int age;
	char name [20];
	int rollno;
	
};
int main()
{
student arr[3];

  
for(int i =0; i<3; i++)
{
	cout<<"input the student record" << endl;
	
	cout<< "enter the name ="<<endl;
	cin>> arr[i].name;
	
	cout<<"enter the age =" << endl;
	cin>>arr[i].age;
	
	cout<< "enter the roll no =" << endl;
	cin>>arr[i].rollno;
	 arr[i].age = arr[i].age +10;
	
	
}

student *s3 = arr;
cout<< "display the record of student" << endl;
    for(int i =0; i<3; i++)
    {
    	cout<<s3[i].name<<endl ;
    	cout<<s3[i].age <<endl;
    	cout<<s3[i].rollno <<endl;
    	 
	}
}
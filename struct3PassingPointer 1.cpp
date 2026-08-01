//Pass structure to a function as a pointer

#include <iostream>
#include <string.h>
using namespace std;

struct student
{
       char name[20];
       int num;
       float score[3];
};

void print( student );// function prototype

void print(student p)
{ 
	   cout<<"\ntudent Number="<<p.num;
	   cout<<"\n Name="<<p.name;
	   cout<<" \n marks for ist subject=>"<<p.score[0];
	   cout<<" \n marks for 2nd subject=>"<<p.score[1];
	   cout<<" \n marks for 3rd subject=>"<<p.score[2];
	   
	   //cout<<p->num<<"\n"<<p->name<<"\n"<<p->score[0]<<"\n"
        //       <<p->score[1]<<"\n"<<p->score[2]<<"\n";     
}

int main()
{
       student stu;
       cout<<"enter Name=";
       //cin.getline(stu.name, 20);
       gets(stu.name);
	   cout<<"enter student reg no=";
       cin>>stu.num;
       
       for(int i=0;i<3;i++)
       {
       	  cout<<"enter marks for subject "<<i+1<<"=>";
       	  cin>>stu.score[i];
	   }
	   /*stu.num=12345;
       strcpy(stu.name,"ahmad ali");
       stu.score[0]=67.5;
       stu.score[1]=89;
       stu.score[2]=78.6;*/
       
	   print(stu);// function call
       
       return 0;
}

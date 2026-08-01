
#include<iostream>
#include<iomanip>
#include<fstream>
#include<conio.h>
#include<cstring>
#include<stdio.h>
#include<cstdlib>
#include<windows.h>
using namespace std;
//////////////////////////////////////
//////function prototypes/////////////
//////////////////////////////////////
void gotoxy(short , short ); // 
void display();	// for record displaying
void add();
void search();
void sort();
void del();
void modify();

struct employee
    {
      char name[40];
      int id;
      
    };
   
    struct employee emp[50];
    int n=0;
//////////////////////////////////////
///////////////////main///////////////
/////////////////////////////////////
int main()
 {
 char ch1;
   while (1)
     {
        system("cls");
	   
	   cout << setw( 25 ) << "-------------" << endl

          << setw( 25 ) << "| MAIN MENU |" << endl

          << setw( 25 ) << "-------------" << endl << endl

          << setw( 52 )

          << "Please choose one of the options below: "

          << endl << setw( 71 )

          << "--------------------------------------------------------------"

          << endl << endl

 

          << setw( 25 ) << "( A ) add record" << endl << endl

          << setw( 31 ) << "( O ) sort all records" << endl << endl

          << setw( 34 ) << "( S ) search for a record" << endl << endl

          << setw( 31 ) << "( D ) display a record" << endl << endl

          << setw( 32 ) << "( T ) delete / undelete" << endl << endl

          << setw( 28 ) << "( M ) update record" << endl << endl
         
		  << setw( 19 ) << "( Q ) Quit" << endl << endl
		  <<setw( 30 ) << "Enter Option      [ ]" << endl << endl;
			gotoxy(28,21);
		//	cin>>ch1;
	     
	   
	  
      
	   switch(getche())
	  //switch(ch1)
       {
         case 'a':
		 case 'A':add();break;
         
		 case 'd':
		 case 'D': display();break;
         
		 case 'S':
		 case 's':search();break;
         
		 case 't':
		 case 'T':del();break;
		 
		 case 'O':
		 case 'o':sort();break;
         
		 case 'm':
		 case 'M':modify();break;
		 
		 case 'q':
		 case 'Q':exit(0);break;
         default:
		puts("\n enter only from selection listed");
       } //end switch
     }//end while
    
	getch();
 }//end main

//////////////////////////////////////
///////////////////Display///////////////
/////////////////////////////////////

void display(void)
	{	
		system("cls");
		cout<< "in display function\n";
		cout<<setw(10)<<" Name:"<<setw(20)<<"Id:"<<endl;
		cout<<setw(10)<<"-------"<<setw(20)<<"----"<<endl;
		for(int i=0;i<n;i++)
			{
				cout<<setw(10)<<emp[i].name<<setw(20)<<emp[i].id<<endl;
			}
			
		cout<<"Press enter to goto main manu.....";
		getch();
			
	}
	

//////////////////////////////////////
///////////////////Add///////////////
/////////////////////////////////////
void add(void)
	{
		char ch;char id1[6];
		do
		{
			system("cls");
			cout<<endl;
			cout<< "in ADD function\n";
			cout<<"enter name:";    
			gets(emp[n].name);
			//cin.getline(emp[n].name,40);
			//cin.ignore(40,'\n');
			cout<<"eneter ID:";
			gets(id1);
			emp[n].id=atoi(id1);
			//cin.ignore();
			n++;
		cout<<"do you want to add more recors [y/n]";
		ch=getch();
		}
		while(ch!='n'&& ch!='N');
	}

//////////Search////////////////////
void search(void)
	{
		cout<< "in SEARCH function\n";
	}

//////////sort///////////////////////
void sort(void)
	{
		cout<< "in SORT function\n";
	}

////////////Delete//////////////////////
void del(void)
	{
		cout<< "in DELETE function\n";
	}

///////////Modify//////////////////////
void modify(void)
	{
		cout<< "in MODIFY function\n";
	}

////////////////////////////////////////
/////////////////gotoxy //////////////////////////
void gotoxy(short x, short y) 
{
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//////////////////////////////////////////

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


void del();
void modify();

struct employee
    {
      char name[40];
      int id;
      int salary;
      int rank;
    };
    void search(employee [],int);
    void sort(employee [],int);
     employee emp[50];
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
		
	     
	   
	  
      
	   switch(getche())
	  //switch(ch1)
       {
                     case 'a':
		 case 'A':add();break;
          
		 case 'd':
		 case 'D': display();break;
         
		 case 'S':
		 case 's':search(emp,n);break;
         
		 case 't':
		 case 'T':del();break;
		 
		 case 'o':
		 case 'O':sort(emp,n);break;
         
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
///////////////////Display///////////
////////////////////////////////////

void display(void)
	{	
		system("cls");	
		
		cout<< "in display function\n";
	
		cout<<setw(15)<<" Name:"<<setw(15)<<"Id:"<<setw(15)<<"salary"<<setw(15)<<"rank:"<<"\n";
		cout<<setw(15)<<"-------"<<setw(15)<<"-------"<<setw(15)<<"-------"<<setw(15)<<"------"<<"\n";
		
		for(int i=0;i<n;i++)
			{
		         	cout<<setw(15)<<emp[i].name<<setw(15)<<emp[i].id<<setw(15)<<emp[i].salary<<setw(15)<<emp[i].rank<<"\n";
			}
			
		cout<<"Press enter to go to main menu.....";
		getch();
			
	}
	

//////////////////////////////////////
///////////////////Add///////////////
/////////////////////////////////////
void add(void)
	{
		char ch;int id1;
		do
		{
			system("cls");
			cout<<endl;
			cout<< "in ADD function\n";
			cin.ignore();
			cout<<"enter name:";    
			cin.getline(emp[n].name,40);
			cout<<"eneter ID:";
			cin >> emp[n].id;
	          	cout<<"enter the salary:";
			cin>>emp[n].salary;
			cout<<"enter the rank:";
			cin>>emp[n].rank;
			n++;
		cout<<"do you want to add more records [y/n]";
		ch = getch();
		}
		while(ch=='y');
	}

//////////Search////////////////////

void search(employee emp[], int n)
    {
    system("cls");
    cout << "==== In SEARCH function ====\n";
    cout << "1. Search by Name\n";
    cout << "2. Search by ID\n";
    cout << "Enter your choice (1 or 2): ";
    int choice;
    cin >> choice;

    bool found = false;

    if (choice == 1) {
        char sname[40];
        cout << "\nEnter the Name to search: ";
        cin.ignore(); 
        cin.getline(sname, 40);

        cout << "\n==============================================================\n";
        cout << setw(15) << "Name" << setw(15) << "ID" << setw(15) << "Salary" << setw(15) << "Rank\n";
        cout << "=================================================================\n";

        for (int i = 0; i < n; i++) {
            if (strcmp(emp[i].name, sname) == 0) {
                cout << setw(15) << emp[i].name << setw(15) << emp[i].id 
                     << setw(15) << emp[i].salary << setw(15) << emp[i].rank << "\n";
                found = true;
            }
        }
    } else if (choice == 2) {
        int sid;
        cout << "\nEnter the ID to search: ";
        cin >> sid;

        cout << "\n===============================================================\n";
        cout << setw(15) << "Name" << setw(15) << "ID" << setw(15) << "Salary" << setw(15) << "Rank\n";
        cout << "=================================================================\n";

        for (int i = 0; i < n; i++) {
            if (emp[i].id == sid) {
                cout << setw(15) << emp[i].name << setw(15) << emp[i].id 
                     << setw(15) << emp[i].salary << setw(15) << emp[i].rank << "\n";
                found = true;
            }
        }
    } else {
        cout << "Invalid choice! Please enter 1 or 2.\n";
        return;
    }

    if (!found) {
        cout << "\n===============================================================\n";
        cout << "Record not found!\n";
        cout << "=================================================================\n";
    }

    cout << "\nPress Enter to return to the main menu...";
    getch();
}

//////////sort///////////////////////
void sort(employee emp[], int n)
	{
		system("cls");
		cout<< "=====in SORT function=====\n";
		cout<<"1.sort by name\n";
		cout<<"2.sort by id\n";
		cout<<"enter your choice(1 or 2):";
		int choice;
		cin>>choice;
		if(choice==1)
		{
        
	              char temp[50];	
                         
	               for(int i=0;i<n-1; i++)
	                   {
		             for(int j=0; j<n-i-1; j++)
		                 {
			
		         	     if(strcmp(emp[j].name,emp[j+1].name)>0)
			       {
			         strcpy(temp, emp[j].name);
				strcpy(emp[j].name, emp[j+1].name);
				strcpy(emp[j+1].name ,temp);
				
			       }
			       
		          }
		                 
                 	          }
                          	
                         	for(int i=0;i<n;i++)
          
		{
		cout << setw(15) << emp[i].name << setw(15) << emp[i].id 
                     << setw(15) << emp[i].salary << setw(15) << emp[i].rank << "\n";	
	}
                          	
                          	
                          	cout<<"Press enter to go to main menu.....";
		getch();
		}
	    
     
     else if(choice == 2)
         {
         
     		employee temp;	

	for(int i=0;i<n-1; i++)
	{
		for(int j=0; j<n-i-1; j++)
		{
		
			if(emp[j].id > emp[j+1].id)
			{
				temp = emp[j];
				emp[j] = emp[j+1];
				emp[j+1] = temp;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		cout << setw(15) << emp[i].name << setw(15) << emp[i].id 
                     << setw(15) << emp[i].salary << setw(15) << emp[i].rank << "\n";	
	}
	cout<<"Press enter to goto main manu.....";
		getch();

}
     
		
	else
	{
		cout<<"invalid choice.please enter 1 or 2 \n";
	}
	
	cout<<"Press enter to goto main manu.....";
		getch();	
		
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

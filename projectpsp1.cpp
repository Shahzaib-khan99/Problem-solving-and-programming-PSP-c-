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
void gotoxy(short , short ); 
void display();
void add();	


struct employee
    {
      char name[40];
      int id;
      int salary;
      int rank;
    };
    void search(employee [],int);
    void sort(employee [],int);
    void modify(employee [],int);
    void del(employee [],int &);
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
	  
       {
                     case 'a':
		 case 'A':add();break;
          
		 case 'd':
		 case 'D': display();break;
         
		 case 'S':
		 case 's':search(emp,n);break;
         
		 case 't':
		 case 'T':del(emp,n);break;
		 
		 case 'o':
		 case 'O':sort(emp,n);break;
         
		 case 'm':
		 case 'M':modify(emp,n);break; 
		 
		 case 'q':
		 case 'Q':exit(0);break;
         default:
		puts("\n enter only from selection listed");
       } 
     }
    
	getch();
 }

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
			cout<<"eneter ID:";
			cin >> emp[n].id;
			
			cout<<"enter name:";  
			cin.ignore(40,'\n');  
			cin.getline(emp[n].name,40);

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
        
	              employee temp;	
                         
	               for(int i=0;i<n-1; i++)
	                   {
		             for(int j=0; j<n-i-1; j++)
		                 {
			
		         	     if(strcmp(emp[j].name,emp[j+1].name)>0)
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
	
	cout<<"Press enter to go to main menu.....";
		getch();	
		
 }	

////////////Delete//////////////////////
void modify( employee emp[],int n)
	{
	int i;	
	int id2;
	char ch;
	int found=0;
	cout<<" enter the id of employee to modify his data=";
	cin>>id2;
	
	for(i=0;i<n;i++)
	
	{
           if (emp[i].id==id2)
           {
	 found=1;
           cout<<"what kind of data do you want to modify\n";
           cout<<" name(n),id(i),salary(s),rank(r)=";
           cin>>ch;
           
	
	 switch(ch)
	  
       {
                     case 'n':
		  cout<<"enter the name that you want to modify:";
		  cin.ignore();
		  gets(emp[i].name);
		      cout<<"name record added successfully";
		 break;
          
		 case 'i':
	            cout<<"enter the id that you want to modify:";
	            cin>>emp[i].id;
	            cout<<"id record added successfully";
		 break;
         
		 case 's':
		cout<<"enter the salary that you wanted to modify:";
          	cin>>emp[i].salary;
          	cout<<"salary record added successfully";
		 break;
         
		 case 'r':
	          cout<<"enter the rank that you wanted to modify:";
	          cin>>emp[i].rank;
	          cout<<"rank record added successfully";
	           break;
	           
		 default:
		  	
                       cout<<"invalid record";
       } 
     }
    

 }
	if(found==0)
	{
	 cout<<"the record entered is not found please again entered\n";	
	}
	cout<<"please enter to go to main menu";
      getch();
}


void del(employee emp[],int &n)


	{
            int del=0;
	int id1;	
	cout<<"enter the id you want to delete";
	cin>>id1;
	for(int i=0;i<n;i++)
	{
		if(emp[i].id==id1)
		{
			for(int j=i;j<n;j++)
			{
				emp[j]=emp[j+1];
			}
			n--;
			del=1;
			cout<<"record deleted";
			break;
		}
	}
	if(del==0)
	{
		cout<<"Record is not found";
	}
	getch();
	}

////////////////////////////////////////
/////////////////gotoxy //////////////////////////



void gotoxy(short x, short y) 
{
COORD pos = {x, y};
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
//////////////////////////////////////////

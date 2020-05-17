#include <iostream>
#include <fstream>
#include <string.h>
#include "pageDisplayer.h"

using namespace std;
//---------------------------function prototypes---------------------------------
void errorAct();
void startPageAct();
void registerAct();
void startAct();
void loginAct();
void exitAct();
void loginActAdm();
void aboutAct();
void dashboard();

//logindata format:userid pw  //seperated by space
//userdata format:user tickerseatc
//showdata : show ticketsold


int state=0; // 0 means guest 1 means logged in  . 2 for wrong password


//--------------------------class for login data----------------------------
class logindata{
	//this is for user to register and login
	public:
	char username[20];
	char userpw[20];
	int age;//for movie rating
	
	public:
		void registeruser(){
			//need to add conf pw verification
			cout<<"\n|Enter new Username: ";cin>>username;
			cout<<"\n|Enter new User password: ";cin>>userpw;
			cout<<"\n|Enter your age: ";cin>>age;
		}
	

};

//---------------------------class for movie data-----------------------------
//to handle movie show data
class showdata{
	//admin can add
	char moviename[20];
	char genre[10];
	char about[30];
	int review;
	int rating;//age viewers
	
	int pricegold;
	int pricesilver;
	int priceplatinium;
	
	int seatsgold;
	int seatssilver;
	int seatsplatinium;
	
	public:
	showdata(){
		//default number of seats
		seatssilver=80;
		seatsgold=112;
		seatsplatinium=60;
		
	}
	
	void inputmoviedata(){
		cout<<"\nEnter movie name: ";cin>>moviename;
		cout<<"\nEnter genre: ";cin>>genre;
		cout<<"\nEnter about: ";cin>>about;
		cout<<"\nEnter review: ";cin>>review;		
		cout<<"\nEnter Rating: ";cin>>rating;
		
		cout<<"\nEnter Silver Ticket Price: ";cin>>pricesilver;
		cout<<"\nEnter Gold Ticket Price: ";cin>>pricegold;
		cout<<"\nEnter Platinium Ticket Price: ";cin>>priceplatinium;		
		
	}
	
	void displaymoviedata(){
		cout<<"\n-----------------------------------------------";
		cout<<"\nMovie Name: "<<moviename;
		cout<<"\nMovie Genre: "<<genre;
		cout<<"\nMovie About: "<<about;
		cout<<"\nMovie Review: "<<review<<"*Star";
		cout<<"\nMovie Rating: "<<rating<<"+Age";
		cout<<"\nTicket Price: "<<" Silver:rs"<<pricesilver<<" Gold:rs"<<pricegold<<" Platinium:rs"<<priceplatinium;
		cout<<"\nSeat Availibility: ";
		if(seatssilver>0)
		{cout<<"Silver";
		}
		if(seatsgold>0)
		{cout<<" Gold";
		}
		if(seatsplatinium>0)
		{cout<<" Platinium";
		}
		if((seatssilver<=0)&&(seatsgold<=0)&&(seatsplatinium<=0))
		{
			cout<<"HouseFUll!!";
		}
		cout<<"\n-----------------------------------------------";
		
	}
	
	void updateseatno(int ticketsbought,int tickettype){
		//this updates number of seats availible
		switch(tickettype){
			case 1:seatssilver-=ticketsbought;
			break;
			case 2:seatsgold-=ticketsbought;
			break;
			case 3:seatsplatinium-=ticketsbought;
		}
	}
	
};


//--------------------------------main----------------------------------

int main()
{
	//start startPage activity
	startAct();
	return 0;
}

//-------------------------------dashboard------------------------------
void dashboard()
{
	//keep a count variable
	//to read file
	//run loop 
	//display all the objects 
	//then ask for choice on what to do
}

//------------------------------exit--------------------------------------
//to exit the program //done
void exitAct()
{
	system("cls");
	exitPage();
	exit(0);
	
	
}

//--------------------------------error for wrong option selected---------------------------------
//to show a error page in case of wrong input  //done
void errorAct()
{//for wrong choices
int ch1;
	system("cls");
	errorPage();
	cin>>ch1;			  
	if(ch1==2)
	{
	  	exitAct;
	}
	else if(ch1==1)
	{
		startAct();
	}
	
}

//---------------------------------------register new user----------------------------------------
//To register new user
void registerAct()
{ //to make account for user
 
	//char userid[20],pw[20];int age;
	logindata l;
	ofstream fout;
	
	int ch;
	system("cls");
	registerPage();
	cin>>ch;
	switch(ch)
	{
		case 1: 
		//making account
		fout.open("logindata.dat",ios::binary | ios::app);
		//need to add an exception handling here for existing username redundancy
		l.registeruser();
		fout.write((char *)&l,sizeof(l));
		fout.close();
		cout<<"\nUser Registered Succesfully !";
		cout<<"\nYou may login to continue\n|Press 1:StartPage\n|Press 2:LoginPage \nYour choice: ";
		cin>>ch;
		switch(ch){
			case 1:startAct();
			break;
			case 2:loginAct();
			break;
			default:errorAct();
		}
		 
		break;
		
		case 2:loginAct();
		break;
		
		case 3:startAct();
		break;
		
		default:errorAct();
	}
	
}


//------------------------------------------login-------------------------------------------------
void loginAct()
{ //Login activity for user 
	ifstream fin;
	logindata l;
	char usernam[20],pw[20];

	int ch;
	system("cls");
	loginPage();
	cin>>ch;
	switch(ch)
	{
		case 1:
			//verify user and take to dashboard
			//run a loop to verify but at eof() ask to make id and
			cout<<"\n|Enter Your UserName: ";cin>>usernam;
			cout<<"\n|Enter password: ";cin>>pw;
			
			fin.open("logindata.dat",ios::binary);
			
			while(!fin.eof()){
				fin.read((char*)&l,sizeof(l));
				if(strcmp(l.username,usernam))
				{
					if(strcmp(l.userpw,pw)){
						state=1;
						//cout<<"\nVerified user!"
						break;
					}
					else
					{state=2;
					//cout<<"\nWrong password" // forgot pw action can be added
					break;
					}
				}
			}
			if(state==1)
			{cout<<"\nVerified user!";
			//******************* redirect to dashboard
			}
			if(state==2){
				cout<<"\nWrong Password try again !";
			}
			if(state==0){
				cout<<"\nNo user found!";
			}
			cout<<"\n|press 1:startPage\n|press 2:register\n|press 3:login again\n|press 4:exit \nYour choice--> ";
			cin>>ch;
			switch(ch){
				case 1: state=0;startAct();
				break;
				case 2: state=0;registerAct();
				break;
				case 3: state=0;loginAct();
				break;
				case 4: state=0;exitAct();
				break;
				default: state=0;errorAct();
			}
			
		break;
		
		case 2:registerAct();
		break;
		
		case 3:startAct();
		break;
		
		default:errorAct();
	}
	
}

//----------------------------------------admin------------------------------------------
void loginActAdm()
{ //Login activity for admin
	int ch;
	ofstream fout;
	ifstream fin;
	showdata m; 
	char adminid[20],adminpw[20];
	
	system("cls");
	loginAdmPage();
	cin>>ch;
	switch(ch)
	{
		case 1:
			//verify user and take to admin dashboard
			//This is temporary method
			cout<<"\n|Enter adminid: ";cin>>adminid;
			cout<<"\n|Enter password: ";cin>>adminpw;
			if((strcmp(adminid,"admin"))&&(strcmp(adminpw,"1234"))){
				cout<<"logged in !";
				cout<<"\n\n|Press 1:To add movies\n|Press 2:To remove movies";
				cin>>ch;
				switch(ch){
					case 1://add movies
					fout.open("showdata.dat",ios::binary|ios::app);
					m.inputmoviedata();
					fout.write((char*)&m,sizeof(m));
					cout<<"\n\nMovie added!";
					fout.close();
					
					
					
					
					break;
					
					case 2:
					
					
					
				}
			}
			else
			{
				cout<<"Wrong id! redirecting to start page";
				cout<<"\n|press 1: to continue \npress 2: to exit\nyour choice:--> ";
				
				cin>>ch;
				switch(ch){
					case 1:startAct();
					break;
					case 2: exitAct();
					break;
					default:errorAct();
			}
			
			}
			
			
			
		break;
		
		case 2:startAct();
		break;
		
		default:errorAct();
	}
	
}

//-------------------------------------------start\home-----------------------------------
void startAct()
{
	int ch;
	system("cls");
	startPage();
	cin>>ch;
		
	switch(ch)
	{
		case 1:registerAct();	   
		break;
		
		case 2:loginAct();
		break;
		
		case 3:dashboard();
		break;
		
		case 4:loginActAdm();
		break;
		
		case 5:aboutAct();
		break;
		
		case 6: exitAct();
		break;
		
		default:errorAct();
		 
		
	}
	
}

//----------------------------------------------dashboard---------------------------------------------
void aboutAct()
{
	int ch;
	system("cls");
	aboutPage();	
	cin>>ch;
	
	if(ch==1)
		startAct();
	if(ch==2)
		exitAct();
	else
		errorAct();
	
	
}

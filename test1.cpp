#include <iostream>
#include <fstream>
#include <string.h>
#include "pageDisplayer.h"

using namespace std;
//---------------------------function prototypes------------------------ //check if all strcmp has !
void errorAct(); 	//done
void startPageAct(); //done-check need
void registerAct();  //done-check need , account stop redundancy thing
void startAct();	//done
void loginAct();	//done-check need , additional feat. can be added
void exitAct();		//done
void loginActAdm(); //crashing here in add movies garbage values
void aboutAct();	//done but edit the features and limitations
void dashboard();	//todo

//logindata format:userid pw  //seperated by space
//userdata format:user tickerseatc
//showdata : show ticketsold


int state=0,currentuserage; // 0 means guest 1 means logged in  . 2 for wrong password
char currentusername[20],currentuserpw[20];


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
		void displayuser(){//admin only
			cout<<"\nUsername: "<<username;
			cout<<"\nPassword: "<<userpw;
			cout<<"\nAge: "<<age;
		}
	

};

//---------------------------class for movie data-----------------------------
//to handle movie show data
class showdata{
	//admin can add
	public:
	char moviename[30];
	char genre[20];
	char about[100];
	char status[20];//upcomming or ongoing
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
		//default number of seats //custom number for special shows make a fn for that
		seatssilver=80;
		seatsgold=112;
		seatsplatinium=60;
		
	}
	
	void inputmoviedata(){
		cout<<"\nEnter movie name: ";cin>>moviename;
		cout<<"\nEnter genre: ";cin>>genre;
		cout<<"\nEnter about: ";cin>>about;
		cout<<"\nEnter review: (max 5 stars): ";cin>>review;		
		cout<<"\nEnter Rating: (0,16,18): ";cin>>rating;
		cout<<"\nEnter Status: (upcomming or ongoing): ";cin>>status;
		
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
		cout<<"\nMovie Status: "<<status;
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
		cout<<"\n-----------------------------------------------\n";
		
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

bool is_empty(ifstream& pFile)
{
    return pFile.peek() == ifstream::traits_type::eof();
}


//--------------------------------main----------------------------------

int main()
{
	//start startPage activity
	startAct();
	return 0;
}

//-------------------------------dashboard------------------------------
void dashboard() //to show all movies
{	int ch,count=1;
	showdata obj;
	ifstream fin;//to open showdata.dat
	ofstream fout;//to write 
	//read file
	//run loop 
	//display all the objects 
	//then ask for choice on what to do
	
	system("cls");
	dashboardPage();
	if(::state==0){
		cout<<"Guest|NOT REGISTERED";
	}
	if(::state==1){
		cout<<currentusername<<"|REGISTERED";
	}
	
	fin.open("showdata.dat",ios::binary);
	//To display ongoing 
	while(!fin.eof()){	
		fin.read((char*)&obj,sizeof(obj));
		cout<<"\nMovie: |"<<count<<"|--->> ";
		obj.displaymoviedata();
		count++;	
	}
	fin.close();
	
	cout<<"\n\n|press 1:To book tickets\n|press 2:StartPage\n|press 3:To Exit\nEnter your choice---> ";
	cin>>ch;
	switch(ch){
		case 1://book
		
		if(state!=0){
			
			
		}
		else{
			cout<<"\n|press 1:Startpage\n|press 2:Exit\nYour choice: ";
			cin>>ch;
			if(ch==1)
				startAct();
			if(ch==2)
				exitAct();
			else
				errorAct();
		}
		
		break;
		
		case 2:startAct();
		
		break;
		
		case 3:exitAct();
			
	}
	
	
	
}

//------------------------------exit--------------------------------------
//to exit the program //done
void exitAct()
{	system("cls");
	exitPage();
	int c;cout<<"\nThank you for using my program!\nPress Enter to exit! ";cin>>c;
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
//To register new user		//done
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
		cout<<"\n*******\nYou may login to continue::\n|Press 1:StartPage\n|Press 2:LoginPage \nYour choice: ";
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
	logindata l; //to read objects 
	char un[20],pw[20];

	int ch;
	system("cls");
	loginPage();
	cin>>ch;
	switch(ch)
	{
		case 1:
			//verify user and take to dashboard
			//run a loop to verify but at eof() ask to make id and
			cout<<"\n|Enter Your UserName: ";cin>>un; 
			cout<<"\n|Enter password: ";cin>>pw;
			
			fin.open("logindata.dat",ios::binary);
			
			while(!fin.eof()){
				fin.read((char*)&l,sizeof(l));
				if(!strcmp(l.username,un))
				{
					if(!strcmp(l.userpw,pw)){
						::state=1;
						//cout<<"\nVerified user!"
						break;
					}
					else
					{::state=2;
					//cout<<"\nWrong password" // forgot pw action can be added
					break;
					}
				}
			}
			if(::state==1)
			{cout<<"\n\nVerified user!";
			//******************* redirect to dashboard
			//also store the info for session
			strcpy(currentusername,l.username);
			strcpy(currentuserpw,l.userpw);
			::currentuserage=l.age;
			dashboard();// To work in this now                       ***************
			
			}
			if(::state==2){
				cout<<"\n\nWrong Password! try again !";
			}
			if(::state==0){
				cout<<"\n\nNo user found! try again";
			}
			cout<<"\n********\n|press 1:startPage\n|press 2:register\n|press 3:login again\n|press 4:exit \nYour choice--> ";
			cin>>ch;
			switch(ch){
				case 1: ::state=0;startAct();
				break;
				case 2: ::state=0;registerAct();
				break;
				case 3: ::state=0;loginAct();
				break;
				case 4: ::state=0;exitAct();
				break;
				default: ::state=0;errorAct();
			}
			
		break;
		
		case 2:registerAct();
		break;
		
		case 3:startAct();
		break;
		
		default:errorAct();
	}
	
}

//----------------------------------------admin------------------------------------------ // need some workaround //can add 1 movie at time //security and password managemnt
//admin management program tobe made
void loginActAdm()
{ //Login activity for admin

	int ch;
	ofstream fout;
	ofstream fout2; //2 for 2.delete option
	ifstream fin2;
	ifstream fin3;
	
	showdata m,n,p; 
	char adminid[20],adminpw[20],deletemoviename[30];
	
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
			if(!(strcmp(adminid,"admin"))&&(strcmp(adminpw,"1234"))){   //temporary admin password
				cout<<"logged in !";
				
				cout<<"\n\n|Press 1:To add movies\n|Press 2:To remove movies\n|press 3:To view All\nYour choice--> ";
				cin>>ch;
				switch(ch){
					case 1://add movies
					fout.open("showdata.dat",ios::binary|ios::app);
					m.inputmoviedata();
					//<-------------crashing here
					fout.write((char*)&m,sizeof(m));
					cout<<"\n\nMovie added!";
					fout.close();
					
					cout<<"\n\n|press 1:Add More(adminPage)(login again)\n|press 2:startPage\n|press 3:Exit\nEnter your choice:-> ";
					cin>>ch;
					switch(ch){
						case 1:loginActAdm();  
						break;
						
						case 2:startAct();
						break;
						
						case 3:exitAct();
						break;
						default: errorAct();
					}
					
					break;
					
					case 2://delete movies
					cout<<"\n\nEnter movie you want to remove: ";cin>>deletemoviename;
					fout2.open("showdata2.dat",ios::binary|ios::app);
					fin2.open("showdata.dat",ios::binary);
					
					while(!fin2.eof()){
						
						fin2.read((char*)&n,sizeof(n));
						if(strcmp(deletemoviename,n.moviename)){
							fout2.write((char*)&n,sizeof(n));
						}
					}
					fin2.close();
					fout2.close();
					
					system("del showdata.dat");
					system("ren showdata2.dat showdata.dat");
					cout<<"\nMovie deleted!";
					cout<<"\n\n|press 1:delete More(adminPage)(login again)\n|press 2:startPage\n|press 3:Exit\nEnter your choice:-> ";
					cin>>ch;
					switch(ch){
						case 1:loginActAdm();  
						break;
						
						case 2:startAct();
						break;
						
						case 3:exitAct();
						break;
						default : errorAct();
					}			
						
					break;
					
					case 3://to view all movie
					fin3.open("showdata.dat",ios::binary);
					if(!is_empty(fin3)){
					
					while(!fin3.eof()){
						fin3.read((char*)&p,sizeof(p));
						p.displaymoviedata();
						
					}fin3.close();
					}
					else{
						cout<<"\nNo Movies Added!";
					}
					cout<<"\n\n|press 1:startPage \n|press 2:admin\nyour choice--> ";
					cin>>ch;
					switch(ch){
						case 1 : startAct();
						break;
						case 2 : loginActAdm();
						break;
						default: errorAct();
					}
					break;
					
					default:
						errorAct();
					
					
					
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

//----------------------------------------------about---------------------------------------------
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

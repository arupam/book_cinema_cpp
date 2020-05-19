//This is project for DSA subject by arupam kumar saha . report as markdown will be updated as readme.md soon in github repo
//github.com/arupam //repo:book_cinema_cpp
#include <iostream>
#include <fstream>
#include <string.h>
#include "pageDisplayer.h"

using namespace std;

//global Var
int state=0;int currentuserage; // 0 means guest 1 means logged in  . 2 for wrong password
char currentusername[20],currentuserpw[20];

//---------------------------function prototypes------------------------ 
void errorAct(); 	//done
void startPageAct(); //done-check need
void registerAct();  //done-check need , account stop redundancy thing
void startAct();	//done
void loginAct();	//done-check need , additional feat. can be added
void exitAct();		//done
void loginActAdm(); //crashing here in add movies garbage values
void aboutAct();	//done but edit the features and limitations
void dashboard();	//todo


//--------------------------Class for user login data----------------------------
class logindata{
	//this is for user to register and login
	public:
	char username[20];
	char userpw[20];
	int age;//for movie rating
	
	
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
	    int returnage(){
	    	return age;
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
	
		void setseatdefault(){
			seatssilver=80;
			seatsgold=112;
			seatsplatinium=60;
		}
		
		void setseatcustom(){
			cout<<"\nEnter seats for show:";
			cout<<"\n|silver: ";scanf("%d",&seatssilver);
			cout<<"\n|Gold: ";scanf("%d",&seatsgold);
			cout<<"\n|platinium: ";scanf("%d",&seatsplatinium);			
		}
		
		void updateseatno(int seatclass){
			switch(seatclass){
				case 1: seatssilver-=1;
				break;
				case 2: seatsgold-=1;
				break;
				case 3: seatsplatinium-=1;
				break;
			}
	}
	
	void inputmovie(){
		cin.ignore();
		cout<<"\n--------Enter movie details--------";
		cout<<"\nMovie/show name: ";gets(moviename);//scanf("%s",&moviename);//cin>>moviename;
		cout<<"\nGenre: ";gets(genre);//scanf("%s",&genre);//cin>>genre;
		cout<<"\nAbout: ";gets(about);//scanf("%s",&about);//cin>>about;
		cout<<"\nReview:(0-5 Stars) ";scanf("%d",&review);//cin>>review;
		cout<<"\nRating:(0,16,18) ";scanf("%d",&rating);//cin>>rating;
		cout<<"\nStatus:(upcoming||ongoing) ";scanf("%s",&status);//cin>>status;
		cout<<"\nSilver Ticket Price: ";scanf("%d",&pricesilver);//cin>>pricesilver;
		cout<<"\nGold Ticket Price: ";scanf("%d",&pricegold);//cin>>pricegold;
		cout<<"\nPlatinium Ticket Price: ";scanf("%d",&priceplatinium);//cin>>priceplatinium;
		
	cout<<"\n\n|press>> 1.Custom or 2.default Seat matrix: ";
			int i;
			cin>>i;
			switch(i){
				case 1:setseatcustom();
				break;
				case 2:setseatdefault();
				break;
				default: errorAct();
			}		
	}
	
	char* returnmoviename(){
		return moviename;
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
		{cout<<seatssilver<<" Silver ,";
		}
		if(seatsgold>0)
		{cout<<seatsgold<<" Gold ,";
		}
		if(seatsplatinium>0)
		{cout<<seatsplatinium<<" Platinium";
		}
		if((seatssilver<=0)&&(seatsgold<=0)&&(seatsplatinium<=0))
		{
			cout<<"HouseFUll!!";
		}
		cout<<"\n-----------------------------------------------\n";
		
	}
	int returnseatprice(int clas){
		switch(clas){
			case 1: return pricesilver;
			break;
			case 2: return pricegold;
			break;
			case 3: return priceplatinium;
		}
	}
	

};


//-----------------------------------class for tickets---------------------------------
class ticket{
	public:
		char holdername[30];
		char moviename[30];
		int beverage;
		int seatclass;
		int totalcost;
		
		void totalcostcal(int classprice){
			switch(beverage){
				case 1:totalcost=classprice+80;
				break;
				case 2:totalcost=classprice+20;
				break;
				case 3:totalcost=classprice+100;
			}
			
		}
		
		void ticketviewer(){
			cout<<"\n***************|Ticket|**************";
			cout<<"\nMovie: "<<moviename; 
			switch(seatclass)
			{case 1: cout<<"             -Silver-";
			 break;
			 case 2: cout<<"		   	 +Gold+";
			 break;
			 case 3:cout<<"               *Platinium*";
			}
			cout<<"\n-------------------------------------";
			cout<<"\nName: "<<holdername;
			cout<<"\nBeverage: ";
			switch(beverage)
			{case 1: cout<<"Popcorn";
			 break;
			 case 2: cout<<"Coldrink";
			 break;
			 case 3:cout<<"Combo(popcorn+coldrink)";
			}
			cout<<"\n			 Total: Rs"<<totalcost;
			cout<<"\n*************************************";
		}
		
};


//to check if file is empty or not
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
{	int ch,count=1,i=0;int moviechoice;
	char movielist[20][20];
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
		cout<<currentusername<<"|REGISTERED\n";
	}
	
	fin.open("showdata.dat",ios::binary);
	//To display ongoing 
	while(fin.read((char*)&obj,sizeof(obj))){	
		//fin.read((char*)&obj,sizeof(obj));
		cout<<"\nMovie: |"<<count<<"|--->> ";
		obj.displaymoviedata();
		strcpy(movielist[i],obj.returnmoviename());
		count++;i++;
	}
	fin.close();
	
	cin.ignore();
	cout<<"\n\n|press 1:To book tickets(registered)\n|press 2:StartPage\n|press 3: View book tickets(registered)\n|press 4:To Exit\nEnter your choice---> ";
	cin>>ch;
	switch(ch){
	case 1:
	{
		//book
		ifstream f;
		//ofstream t;
		showdata b;
		ticket tt;
		int clas,btype,clasprice;int cc;
		if(::state==1){
			cout<<"\n|*|Select Movie to book: ";
			for(int x=0;x<i;x++){
				cout<<"\n"<<x+1<<"."<<movielist[x];
			}cout<<"\n";
			cout<<"Enter your choice: ";cin>>moviechoice;cout<<" you selected: "<<movielist[moviechoice-1];
			
			//problem here____.::::fixed
			//garbage value  also seatdata not updating::: fixed
			f.open("showdata.dat",ios::binary);
			while(!f.eof()){
				f.read((char*)&b,sizeof(b));
				if(!strcmp(movielist[moviechoice-1],b.moviename))
				cout<<"\nmoviefound";
					break;
			}
			
			
			
			if(b.rating<currentuserage)
			{
				cout<<"\nAvailible Tickets and thier price :";
				cout<<"\n|1|Silver Seats(Rs"<<b.pricesilver<<"): "<<b.seatssilver;
				cout<<"\n|2|Gold Seats(Rs"<<b.pricesilver<<"): "<<b.seatssilver;
				cout<<"\n|3|Platinium Seats(Rs"<<b.pricesilver<<"): "<<b.seatssilver;
				cout<<"\nSelect class: ";cin>>clas;
				//return price of seat class u selected 
				//switch(clas){
				//	case 1: clasprice=b.pricesilver;
				//	break;
				//	case 2: clasprice=b.pricegold;
				///	break;
				//	case 3: clasprice=b.priceplatinium;
				//	}//**********
				clasprice=b.returnseatprice(clas);
				cout<<"\n\nSelect bevarage: "<<"\n|1.Popcorn(80rs)\n|2.coldrink(20rs)\n\3.Combo(100rs)";
				cin>>btype;
				cout<<"\nWait it may take some time";
				
				//generating ticket 
				strcpy(tt.moviename,b.moviename);
				strcpy(tt.holdername,currentusername); 
				tt.seatclass=clas;
				tt.beverage=btype;
				tt.totalcostcal(clasprice);//check here
				
				ofstream t;
				//saving ticket in file
				t.open("ticketdata.dat",ios::binary);
				t.write((char*)&tt,sizeof(tt));
				t.close();
				f.close();
				
				//update ticket :::seats not updating ///new issue
				fstream fin;showdata u;
				fin.open("showdata.dat",ios::binary|ios::in|ios::out);
				while(fin.read((char*)&u,sizeof(u)))
				{
					//fin.read((char*)&u,sizeof(u));
					if(!strcmp(movielist[moviechoice],u.moviename)){
						fin.seekp(-1*sizeof(u),ios::cur);
						u.updateseatno(clas);
						fin.write((char*)&u,sizeof(u));
						break;
					}
				}
				fin.close();
				
				
				cout<<"\nTicket generated! ";
				cout<<"\n\n|press 1 :showticket \n|press 2:startpage\nEnter choice: ";
				cin>>cc;
				switch(cc){
					case 1:tt.ticketviewer();cout<<"\n\n|press 1:startpage\n|press 2:exit\nEnter choice: "; //print tickit option add 
							cin>>cc;
							switch(cc){
								
								case 1:startAct();
								break;
								case 2:exitAct();
								default: errorAct();
										}
				
					break;
					case 2:startAct();
					break;
					default: errorAct();
				}
				
				
				
			}
		
			else{
				int c;
				cout<<"\nSOrry! Your age is less than "<<b.rating<<" for movie "<<b.moviename;
				cout<<"\n\n|press 1: startPage(use other account)\n|press 2:exit\nYour choice: ";
				cin>>c;
				if(c==1)
					startAct();
				if(c==2)
					exitAct();
				else
					errorAct();
			}
			
			
			
			
			
		}
		else{
			cout<<"\nYou are in guest mode! to buy login/register \n|press 1:login\n|press 2:Register \n|press 3:Exit\nYour choice: ";
			cin>>ch;
			if(ch==1)
				loginAct();
			if(ch==2)
				registerAct();
			if(ch==3)
				exitAct();
			else
				errorAct();
		}
		
		
	break;}
	
	case 2:{
		startAct();
		break;
	}
		
	case 3:{
		if(::state!=0){
			ifstream file;int ccc;
			ticket ff;
			cout<<"\n\n"<<currentusername<<"'s tickets: \n";
			file.open("ticketdata.dat",ios::binary);
			while(file.read((char*)&ff,sizeof(ff))){
				if(!strcmp(ff.holdername,currentusername)){
					ff.ticketviewer();
				}
			}
			cout<<"\n\n|press 1:startpage\n|press 2:exit\nEnter choice: "; //print tickit option add 
							cin>>ccc;
							switch(ccc){
								
								case 1:startAct();
								break;
								case 2:exitAct();
								default: errorAct();
										}
		
		}
		else
			{
			cout<<"\nYou are in guest mode! to buy login/register \n|press 1:login\n|press 2:Register \n|press 3:Exit\nYour choice: ";
			cin>>ch;
			if(ch==1)
				loginAct();
			if(ch==2)
				registerAct();
			if(ch==3)
				exitAct();
			else
				errorAct();
			}
		break;
	}
	
		
	case 4:{exitAct();
		break;
	}
	default : errorAct();		
	}
	
	
	
}

//------------------------------exit--------------------------------------
//to exit the program //done
void exitAct()
{	system("cls");
	exitPage();
	int c;cout<<"\nThank you for using my program!\nEnter bye to exit! ";cin>>c;
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
			currentuserage=l.returnage();
			fin.close(); 
			
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
			{
			
			//verify user and take to admin dashboard
			//This is temporary method
			cin.ignore();
			cout<<"\n|Enter adminid: ";cin>>adminid;
			cout<<"\n|Enter password: ";cin>>adminpw;
			if(!(strcmp(adminid,"admin"))&&(strcmp(adminpw,"1234"))){   //temporary admin password
				cout<<"logged in !";
				
				cout<<"\n\n|Press 1:To add movies\n|Press 2:To remove movies\n|press 3:To view All\n|press 4:To see all booked tickets\nYour choice--> ";
				
				cin.ignore();//cin buffer clear crashfixcin.ignore(INT_MAX);
				cin>>ch;
				switch(ch){
					case 1:
					{
					//add movies
					fout.open("showdata.dat",ios::binary|ios::app);
					m.inputmovie();
					//<-------------crashing here
					fout.write((char*)&m,sizeof(m));
					cout<<"\n\nMovie added!";
					fout.close();
					
					cout<<"\n\n|press 1:Add More(adminPage)(login again)\n|press 2:startPage\n|press 3:Exit\nEnter your choice:-> ";
					cin.ignore();
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
					
					break;}
					
					case 2:
					{
					//delete movies
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
						
					break;}
					
					
					case 3:
					{
					//to view all movie
					fin3.open("showdata.dat",ios::binary);
					if(!is_empty(fin3)){
					
					//while(!fin3.eof()){
					//	fin3.read((char*)&p,sizeof(p));
					//	p.displaymoviedata();
					//refer soln : while ( f.read( reinterpret_cast<char*>( &temp ), sizeof( temp ) ) ) {
 					  // temp.displaydata();	
					//	}
						while(fin3.read((char*)&p,sizeof(p))){
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
					break;}
					
					case 4: 
					{
					//to view all tickets booked till now
					ticket a;
					ifstream ff;
					ff.open("ticketdata.dat",ios::binary);
					cout<<"\nViewing all tickets booked::->";
					while(ff.read((char*)&a,sizeof(a))){
						 a.ticketviewer();
						 cout<<endl;
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
					break;}
					
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
			
			
			
		break;}
		
		case 2:{
			
		startAct();
		break;}
		
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

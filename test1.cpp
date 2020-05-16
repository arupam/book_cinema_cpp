#include <iostream>
#include <fstream>
#include <string.h>
#include "pageDisplayer.h"

using namespace std;

void errorAct();
void startPageAct();
void registerAct();
void startAct();
void loginAct();
void exitAct();
void loginActAdm();
void aboutAct();

//logindata format:userid pw  //seperated by space
//userdata format:user tickerseatc
//showdata : show ticketsold

class logindata{
	//this is for user to register and login
	char username[20];
	char userpw[20];
	int age;//for movie rating
	

};

class showdata{
	//admin can add
	char moviename[20];
	char genre[10];
	char about[30];
	int rating;
	
	int pricegold;
	int pricesilver;
	int priceplatinium;
	
	int seatsgold;
	int seatssilver;
	int seatsplatinium;
	
	showdata(){
		//default number of seats
		seatssilver=80;
		seatsgold=112;
		seatsplatinium=60;
		
	}
	
};



int main()
{
	//start startPage activity
	startAct();
	return 0;
}


//to exit the program //done
void exitAct()
{
	system("cls");
	exitPage();
	exit(0);
	
	
}

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

//To register new user
void registerAct()
{ //to make account for user

	char userid[20],pw[20];
	int ch;
	system("cls");
	registerPage();
	cin>>ch;
	switch(ch)
	{
		case 1: 
		//making account
		 
		 
		break;
		
		case 2:loginAct();
		break;
		
		case 3:startAct();
		break;
		
		default:errorAct();
	}
	
}

void loginAct()
{ //Login activity for user 
	int ch;
	system("cls");
	loginPage();
	cin>>ch;
	switch(ch)
	{
		case 1:
			//verify user and take to dashboard
		break;
		
		case 2:registerAct();
		break;
		
		case 3:startAct();
		break;
		
		default:errorAct();
	}
	
}


void loginActAdm()
{ //Login activity for admin
	int ch;
	system("cls");
	loginAdmPage();
	cin>>ch;
	switch(ch)
	{
		case 1:
			//verify user and take to admin dashboard
		break;
		
		case 2:startAct();
		break;
		
		default:errorAct();
	}
	
}

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
		
		case 3://dashboard
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





void makeNewAcc()
{
	
	char username[100];
	char password[100];
	char confPassword[100];
	
	//i can make class for user data as well as a file to store all data like keypairs
}

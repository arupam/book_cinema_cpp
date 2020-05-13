#include <iostream>
#include "pageDisplayer.h"

using namespace std;


int main()
{
	//start startPage activity
	startAct();
	
	return 0;
}


void errorAct()
{
	errorPage();
	cin>>ch;			  
	if(ch1==2)
	{
	  	return 0;
	}
	else if(ch1==1)
	{
		startPageAct();
	}
	
}

void registerAct()
{ 
	int ch;
	registerPage();
	cin>>ch;
	swtich(ch)
	{
		case 1: 
		 //Store password and userid if pw = cpw then take to startPage
		 
		break;
		
		case 2:loginAct();
		break
		
		case 3:startAct();
		break;
		
		default:errorAct();
	}
	
}

void loginAct()
{ 
	int ch;
	registerPage();
	cin>>ch;
	swtich(ch)
	{
		case 1:
			//verify user and take to dashboard
		break;
		
		case 2:registerAct();
		break
		
		case 3:startAct();
		break;
		
		default:errorAct();
	}
	
}


void loginActAdm()
{ //Login activity for admin
	int ch;
	registerPage();
	cin>>ch;
	swtich(ch)
	{
		case 1:
			//verify user and take to admin dashboard
		break;
		
		case 2:registerAct();
		break
		
		case 3:startAct();
		break;
		
		default:errorAct();
	}
	
}

void startAct()
{
	int ch;
	startPage();
	cin>>ch;
		
	switch(ch)
	{
		case 1;registerAct();	   
		break;
		
		case 2:
		break;
		
		case 3:
		break;
		
		case 4:
		break;
		
		case 5:
		break;
		
		case 6:
		break;
		
		default : errorAct();
		 
		
	}
	
	
}





void makeNewAcc()
{
	
	char username[100];
	char password[100];
	char confPassword[100];
	
	//i can make class for user data as well as a file to store all data like keypairs
}

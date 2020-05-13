#include <iostream>
#include <fstream>
using namespace std;

//This header file contains functions to display the interface pages
//rdbuf() is for outputting the file inputted through ifstream

void startPage()
{
	cout<<endl<<ifstream("startPage.txt").rdbuf();
}

void registerPage()
{
	cout<<endl<<ifstream("registerPage.txt").rdbuf();
}


void errorPage()
{
	cout<<endl<<ifstream("errorPage.txt").rdbuf();
}

void loginPage()
{
	cout<<endl<<ifstream("loginPage.txt").rdbuf();
}

void loginAdmPage()
{
	cout<<endl<<ifstream("logiAdmPage.txt").rdbuf();
}

void exitPage()
{
	cout<<endl<<ifstream("exitPage.txt").rdbuf();
}

#include <iostream>
#include <fstream>
using namespace std;

void startPage()
{
	cout<<endl<<ifstream("startPage.txt").rdbuf();
}


void registerPage()
{
	cout<<endl<<ifstream("registerPage.txt").rdbuf();
}

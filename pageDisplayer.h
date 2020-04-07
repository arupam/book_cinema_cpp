#include <iostream>
#include <fstream>
using namespace std;

void startPage()
{
	cout<<endl<<ifstream("startPage.txt").rdbuf();
}



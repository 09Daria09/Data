#include<iostream>
#include"Date.h"
using namespace std;

int main()
{
	setlocale(LC_ALL,"ru");
	Date firs;
//	firs.Print();
	firs.Input();
	firs.Print();
	//Date f = ++firs;
	/*cout << "--------------------" << endl;
	firs.Print();*/
	Date u = --firs;
	cout << "--------------------" << endl;
	firs.Print();

}
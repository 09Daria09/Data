#include<iostream>
#include"Date.h"
using namespace std;

int main()
{
	setlocale(LC_ALL,"ru");
Date firs(4,5,2);
firs.Print();
//	firs.Input();
//	firs.Print();
	//Date f = ++firs;
	/*cout << "--------------------" << endl;
	firs.Print();*/
	/*Date u = --firs;
	cout << "--------------------" << endl;
	firs.Print();*/
	//Date t = firs + 367;
	cout << "--------------------" << endl;
	/*Date g = firs - 256;
	g.Print();*/
	/*firs +=467;
	firs.Print();*/
	cout << "--------------------" << endl;
	Date d(3,7,5);
	d.Print();
	if (d > firs)
	{
		cout << "D";
	}
}
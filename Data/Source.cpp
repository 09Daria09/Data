#include<iostream>
#include"Date.h"
using namespace std;

int main()
{
	setlocale(LC_ALL,"ru");
	Date firstDate(14, 8, 2001);
	Date secondDate(12, 3, 2001);
	++firstDate;
	firstDate.Print();
	cout << "******************" << endl;
	secondDate++.Print();
	cout << "********************" << endl;
	secondDate.Print();
	cout << "********************" << endl;
	--firstDate;
	firstDate.Print();
	cout << "********************" << endl;
	secondDate--.Print();
	cout << "********************" << endl;
	secondDate.Print();
	cout << "********************" << endl;
	Date thirdDate = firstDate + 1220;
	thirdDate.Print();
	cout << "********************" << endl;
	Date fourthDate = secondDate - 123;
	fourthDate.Print();
	cout << "*******************" << endl;
	Date differenceDays = thirdDate - fourthDate;
	differenceDays.Print();
	cout << "*******************" << endl;
	firstDate += 365;
	firstDate.Print();
	cout << "*******************" << endl;
	firstDate -= 365;
	firstDate.Print();
	cout << "******************" << endl;
	bool a = firstDate < secondDate;
	cout << a<<endl;
	cout << "******************" << endl;
	bool b = firstDate > secondDate;
	cout << b<<endl;
	cout << "******************" << endl;
	bool c = firstDate <= secondDate;
	cout << c << endl;
	cout << "******************" << endl;
	bool d = firstDate >= secondDate;
	cout << d << endl;
	cout << "******************" << endl;
	bool e = firstDate == secondDate;
	cout << e << endl;
	cout << "******************" << endl;
	bool f = firstDate != secondDate;
	cout << f << endl;
}
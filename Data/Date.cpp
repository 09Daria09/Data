#include "Date.h"
#include<iostream>
using namespace std;
Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}
Date::Date(int d)
{
	d = day;
}
Date::Date(int d, int m) :Date(d)
{
	m = month;
}
Date::Date(int d, int m, int y) : Date(d, m)
{
	y = year;
}
///
void Date::Print()
{
	cout << "���� " << day << endl;
	cout << "����� " << month << endl;
	cout << "��� " << year << endl;
}
void Date::Input()
{
	Setd();
	Print_Month();
	Setm();
	Sety();
	//system("cls");//�������� �������
}
int Date::Getd()const
{
	return day;
}
void Date::Setd()
{
	cout << "������� ����(1-31): ";
	cin >> day;
	if (day > 31 || day < 1)
	{
		cout << "�� ����� ������������ ����� \n������� ��� ���" << endl;
		Setd();
	}
}//���� ���
int Date::Getm()const
{
	return month;
}
void Date::Setm()
{
	cout << "������� ����� (1-12): ";
	cin >> month;
	if (month > 12 || month < 1)
	{
		cout << "�� ����� ������������ ����� \n������� ��� ���" << endl;
		Setm();
	}
}//���� ������
int Date::Gety()const
{
	return year;
}
void Date::Sety()
{
	cout << "������� ���: ";
	cin >> year;
}//���� ����
///
bool Date::fouryear() const
{
	return (year % 4 == 0);
}
void Date::Print_Month()
{
	cout << JAN << ".������" << endl;
	cout << FEB << ".�������" << endl;
	cout << MAR << ".����" << endl;
	cout << APR << ".������" << endl;
	cout << MAY << ".���" << endl;
	cout << JUN << ".����" << endl;
	cout << JUL << ".����" << endl;
	cout << AUG << ".������" << endl;
	cout << SEP << ".��������" << endl;
	cout << OCT << ".�������" << endl;
	cout << NOV << ".������" << endl;
	cout << DEC << ".�������" << endl;
}
///
void Date::Febfun()
{
	if (fouryear() == 1)
	{
		if (day == 29)
		{
			day = 1;
			month = MAR;
		}
		else
		{
			day++;
		}
	}
	else
	{
		if (day == 28)
		{
			day = 1;
			month = MAR;
		}
		else
		{
			day++;
		}
	}

}
void Date::Day_30()
{
	if (day == 30)
	{
		Func_Month();
	}
	else
	{
		day++;
	}
}
void Date::Day_31()
{

	if (day == 31)
	{
		Func_Month();
	}
	else
	{
		day++;
	}
}
void Date::Func_Month()
{
	if (day == 31 && month == 12)
	{
		Func_Year();
		return;
	}
	day = 1;
	switch (month)
	{
	case JAN:
		month = FEB;
	case MAR:
		month = APR;
		break;
	case APR:
		month = MAY;
		break;
	case MAY:
		month = JUN;
		break;
	case JUN:
		month = JUL;
		break;
	case JUL:
		month = AUG;
		break;
	case AUG:
		month = SEP;
		break;
	case SEP:
		month = OCT;
		break;
	case OCT:
		month = NOV;
		break;
	case NOV:
		month = DEC;
		break;
	}
}
void Date::Func_Year()
{
	day = 1;
	year = year + 1;
	month = JAN;
}
Date& Date::operator++()
{
	if (month == APR || month == JUN || month == SEP || month == NOV)
	{
		Day_30();
		return *this;
	}
	else if (month == FEB)
	{
		Febfun();
		return *this;
	}
	else
	{
		Day_31();
		return *this;
	}
}
///
void Date::Jun_1()
{
	day = 31;
	year--;
	month = DEC;
}
void Date::Mart_1()
{
	if (fouryear() == 1)
	{
		day = 29;
		month--;
	}
	else
	{
		day = 28;
		month--;
	}
}
void Date::Day_Minus()
{
	for (int i = 1; i < 8; i++)
	{
		if (month == JAN)
		{
			Jun_1();
			return;
		}
		if (month == MAR)
		{
			Mart_1();
			return;
		}
		if (i % 2 == 0)
		{
			month--;
			day = 31;
		}
		else if (i % 2 != 0)
		{
			month--;
			day = 30;
		}
	}
	for (int i = 8; i < 12; i++)
	{
		if (i % 2 == 0)
		{
			month--;
			day = 30;
		}
		else
		{
			month--;
			day = 31;
		}
	}
}
Date& Date::operator--()
{
	if (day == 1)
	{
	Day_Minus();
	return *this;
	}
	else
	{
		day--;
		return *this;
	}
}
///
Date Date::operator+(int num)
{

}



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
	day = d;
	month = 0;
	year = 0;
}
Date::Date(int d, int m) :Date(d)
{
	month = m;
	year = 0;
}
Date::Date(int d, int m, int y) : Date(d, m)
{
	year = y;
}
///
void Date::Print()
{
	cout << "День " << day << endl;
	cout << "Месяц " << month << endl;
	cout << "Год " << year << endl;
}
void Date::Input()
{
	Setd();
	Print_Month();
	Setm();
	Sety();
	//system("cls");//стирание консоли
}
int Date::Getd()const
{
	return day;
}
void Date::Setd()
{
	cout << "Введите день(1-31): ";
	cin >> day;
	if (day > 31 || day < 1)
	{
		cout << "Вы ввели некорректное число \nВведите еще раз" << endl;
		Setd();
	}
}//Ввод дня
int Date::Getm()const
{
	return month;
}
void Date::Setm()
{
	cout << "Введите месяц (1-12): ";
	cin >> month;
	if (month > 12 || month < 1)
	{
		cout << "Вы ввели некорректное число \nВведите еще раз" << endl;
		Setm();
	}
}//Ввод месяца
int Date::Gety()const
{
	return year;
}
void Date::Sety()
{
	cout << "Введите год: ";
	cin >> year;
}//Ввод года
///
bool Date::fouryear() const
{
	return (year % 4 == 0);
}
void Date::Print_Month()
{
	cout << JAN << ".Январь" << endl;
	cout << FEB << ".Февраль" << endl;
	cout << MAR << ".Март" << endl;
	cout << APR << ".Апрель" << endl;
	cout << MAY << ".Май" << endl;
	cout << JUN << ".Июнь" << endl;
	cout << JUL << ".Июль" << endl;
	cout << AUG << ".Август" << endl;
	cout << SEP << ".Сентябрь" << endl;
	cout << OCT << ".Октябрь" << endl;
	cout << NOV << ".Ноябрь" << endl;
	cout << DEC << ".Декабрь" << endl;
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
		break;
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
Date Date::operator++(int)
{
	Date def(*this);
	if (month == APR || month == JUN || month == SEP || month == NOV)
	{
		Day_30();
		return def;
	}
	else if (month == FEB)
	{
		Febfun();
		return def;
	}
	else
	{
		Day_31();
		return def;
	}
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
Date Date::operator--(int)
{
	Date def(*this);
	if (day == 1)
	{
		Day_Minus();
		return def;
	}
	else
	{
		day--;
		return def;
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
void Date::Count_month()
{
	switch (month)
	{
	case JAN:
		month = FEB;
		day = 1;
		break;
	case FEB:
		month = MAR;
		day = 1;
		break;
	case MAR:
		month = APR;
		day = 1;
		break;
	case APR:
		month = MAY;
		day = 1;
		break;
	case MAY:
		month = JUN;
		day = 1;
		break;
	case JUN:
		month = JUL;
		day = 1;
		break;
	case JUL:
		month = AUG;
		day = 1;
		break;
	case AUG:
		month = SEP;
		day = 1;
		break;
	case SEP:
		month = OCT;
		day = 1;
		break;
	case OCT:
		month = NOV;
		day = 1;
		break;
	case NOV:
		month = DEC;
		day = 1;
		break;
	}
}
void Date::Count_year()
{
	day = 1;
	year++;
	month = JAN;
}
Date Date::operator+(int num)
{
	Date res;
	res.day = day;
	res.month = month;
	res.year = year;
	for (int i = 0; i < num; i++)
	{
		if (res.month == APR || res.month == JUN || res.month == SEP || res.month == NOV)
		{
			if (res.day == 30)
			{
				res.Count_month();
				continue;
			}
			res.day++;
			continue;
		}
		if (res.month == FEB)
		{
			if (fouryear() == 1)
			{
				if (res.day == 29)
				{
					res.Count_month();
					continue;
				}
				res.day++;
				continue;
			}
			if (res.day == 28)
			{
				res.Count_month();
				continue;
			}
			res.day++;
			continue;
		}
		if (res.month == DEC)
		{
			if (res.day == 31)
			{
				res.Count_year();
				continue;
			}
			res.day++;
			continue;
		}
		if (res.month == JAN || res.month == MAR || res.month == MAY || res.month == JUL || res.month == AUG || res.month == OCT)
		{
			if (res.day == 31)
			{
				res.Count_month();
				continue;
			}
			res.day++;
			continue;
		}
	}
	return res;
}
///
void Date::Count_month_minus()
{
	switch (month)
	{
	case DEC:
		month = NOV;
		day = 30;
		break;
	case NOV:
		month = OCT;
		day = 31;
		break;
	case OCT:
		month = SEP;
		day = 30;
		break;
	case SEP:
		month = AUG;
		day = 31;
		break;
	case AUG:
		month = JUL;
		day = 31;
		break;
	case JUL:
		month = JUN;
		day = 30;
		break;
	case JUN:
		month = MAY;
		day = 31;
		break;
	case MAY:
		month = APR;
		day = 30;
		break;
	case APR:
		month = MAR;
		day = 31;
		break;
	case FEB:
		month = JAN;
		day = 31;
		break;
	}
}
void Date::Year_minus()
{
	year--;
	month = DEC;
	day = 31;
}
Date Date::operator-(int num)
{
	Date res;
	res.day = day;
	res.month = month;
	res.year = year;
	for (int i = 0; i < num; i++)
	{
		if (res.month == MAR)
		{
			if (res.day == 1)
			{
				if (fouryear() == 1)
				{
					res.day = 29;
					res.month = FEB;
					continue;
				}
				res.month = FEB;
				res.day = 28;
				continue;
			}
			res.day--;
			continue;
		}
		else if (res.month == JAN)
		{
			if (res.day == 1)
			{
				res.Year_minus();
				continue;
			}
			res.day--;
			continue;
		}
		else
		{
			if (res.day == 1)
			{
				res.Count_month_minus();
				continue;
			}
			res.day--;
			continue;
		}
	}
	return res;
}
///
Date Date::operator-(Date& obj)
{
	int allday=0;
	int countmonth=0;
	int countmonth1 = 0;
	double y, y1;
	double res,res1;
	float highY = (float)year / 4;
	float highY1 = (float)obj.year / 4;
	y = highY+ (year * 365);
	y1 = highY1 + (obj.year * 365);
	int sim_month=month;
	int sim_month1 = obj.month;
	for (int i = 0; i < sim_month; i++)
	{
		if (month == APR || month == JUN || month == SEP || month == NOV)
		{
			allday = 30;
			month--;
		}
		else if (month == FEB)
		{
			if (fouryear() == 1)
			{
				allday = 29;
				month--;
			}
			else
			{
				allday = 28;
				month--;
			}
		}
		else
		{
			allday = 31;
			month--;
		}
		countmonth += allday;
	}
	for (int i = 0; i < sim_month1; i++)
	{
		if (month == APR || month == JUN || month == SEP || month == NOV)
		{
			allday = 30;
			obj.month--;
		}
		else if (month == FEB)
		{
			if (fouryear() == 1)
			{
				allday = 29;
				obj.month--;
			}
			else
			{
				allday = 28;
				obj.month--;
			}
		}
		else
		{
			allday = 31;
			month--;
		}
		countmonth1 += allday;
	}
	res = day + countmonth + y;
	res1 = obj.day +countmonth1 + y1;
	double allRes;
	allRes = res - res1;
	return allRes;
}
///
Date& Date::operator+=(int num)
{
	for (int i = 0; i < num; i++)
	{
		if (month == APR || month == JUN || month == SEP || month == NOV)
		{
			if (day == 30)
			{
				Count_month();
				continue;
			}
			day++;
			continue;
		}
		if (month == FEB)
		{
			if (fouryear() == 1)
			{
				if (day == 29)
				{
					Count_month();
					continue;
				}
				day++;
				continue;
			}
			if (day == 28)
			{
				Count_month();
				continue;
			}
			day++;
			continue;
		}
		if (month == DEC)
		{
			if (day == 31)
			{
				Count_year();
				continue;
			}
			day++;
			continue;
		}
		if (month == JAN || month == MAR || month == MAY || month == JUL || month == AUG || month == OCT)
		{
			if (day == 31)
			{
				Count_month();
				continue;
			}
			day++;
			continue;
		}
	}
	return *this;
}
Date& Date::operator-=(int num)
{
	for (int i = 0; i < num; i++)
	{
		if (month == MAR)
		{
			if (day == 1)
			{
				if (fouryear() == 1)
				{
					day = 29;
					month = FEB;
					continue;
				}
				month = FEB;
				day = 28;
				continue;
			}
			day--;
			continue;
		}
		else if (month == JAN)
		{
			if (day == 1)
			{
				Year_minus();
				continue;
			}
			day--;
			continue;
		}
		else
		{
			if (day == 1)
			{
				Count_month_minus();
				continue;
			}
			day--;
			continue;
		}
	}
	return *this;
}
///
bool Date::operator<(const Date& obj)const
{
	if (year < obj.year)
	{
		return true;
	}
	else if (year == obj.year)
	{
		if (month < obj.month)
		{
			return true;
		}
		else if (month == obj.month)
		{
			if (day < obj.day)
			{
				return true;
			}
		}
	}
	return false;
}
bool Date::operator>(const Date& obj)const
{
	if (year > obj.year)
	{
		return true;
	}
	else if (year == obj.year)
	{
		if (month > obj.month)
		{
			return true;
		}
		else if (month == obj.month)
		{
			if (day > obj.day)
			{
				return true;
			}
		}
	}
	return false;
}
bool Date::operator<=(const Date& obj)const
{
	if (year == obj.year && month == obj.month && day == obj.day)
	{
		return true;
	}
	if (year < obj.year)
	{
		return true;
	}
	if (year == obj.year && month < obj.month)
	{
		return true;
	}
	if (year == obj.year && month == obj.month && day < obj.day)
	{
		return true;
	}
	return false;
}
bool Date::operator>=(const Date& obj)const
{
	if (year == obj.year && month == obj.month && day == obj.day)
	{
		return true;
	}
	if (year > obj.year)
	{
		return true;
	}
	if (year == obj.year && month > obj.month)
	{
		return true;
	}
	if (year == obj.year && month == obj.month && day > obj.day)
	{
		return true;
	}
	return false;
}
bool Date::operator==(const Date& obj)const
{
	if (year == obj.year && month == obj.month && day == obj.day)
	{
		return true;
	}
	return false;
}
bool Date::operator!=(const Date& obj)const
{
	if (year == obj.year && month == obj.month && day == obj.day)
	{
		return false;
	}
	return true;
}
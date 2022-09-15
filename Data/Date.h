#pragma once
class Date
{
	int day;
	int month;
	int year;
public:
	Date();
	Date(int d);
	Date(int d, int m);
	Date(int d, int m, int y);
	///
	void Print();
	void Input();
	int Getd()const;
	void Setd();
	int Getm()const;
	void Setm();
	int Gety() const;
	void Sety();
	///
	enum { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };
	bool fouryear() const;

	void Print_Month();

	void Febfun();

	void Day_30();

	void Day_31();

	void Func_Month();

	void Func_Year();

	Date& operator++();

	//void Day_30M();

	void Jun_1();

	void Mart_1();

	void Day_Minus();

	Date& operator--();

	void Count_month();

	void Count_year();

	Date operator+(int num);

	void Count_month_minus();

	void Year_minus();

	Date operator-(int num);
	//Date operator-(const Date& obj);
	Date& operator+=(int a);
	Date& operator-=(int num);
	bool operator<(const Date& obj)const;
	bool operator>(const Date& obj) const;
	bool operator<=(const Date& obj) const;
};


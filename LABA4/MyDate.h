#pragma once
#include <stdio.h>
#include <iostream>
using namespace std;
typedef FILE* File;
class MyDate
{
	int day, month, year;
	static int daytab[2][13];
	static const char* MonthName[13];
	static const char* DayNames[8];
public:
	int get_day() { return day; }
	int get_month() { return month; }
	int get_year() { return year; }
	int get_day()const { return day; }
	int get_month()const { return month; }
	int get_year()const { return year; }
	char* get_DayOfWeek()const;
	//MyDate get_Now();
	MyDate Parser(char*);
	void AddDays(long); //�������� ����� ���� ������������� ������
	void AddMonth(long); //�������� ����� ���� ������������� ������
	void AddYear(long); //�������� ����� ���� ������������� ������
	int validate();
	void set_day(int d) { int tmp = day; day = d; if (!validate()) day = tmp; }
	void set_month(int m) { int tmp = month; month = m; if (!validate()) month = tmp; }
	// void set_year(int y) { int tmp = year; year = q; if (!validate()) year = tmp; 

	static int dayofyear(int y, int m, int d);
	static void day_month(int d, int y, int* m, int* dd);
	static int vis(int y) {
		return ((!(y % 4)) && (y % 100) || (!(y % 400)));
	}
	char* ToPchar();
	unsigned long ToLong()const;
	MyDate(void);
	~MyDate(void);
	MyDate(int d, int m, int y);
	MyDate(char* s);
	MyDate(const MyDate&);
	void assign(const MyDate& t);
	void dispose();
	MyDate* copy();
	int equal(const MyDate& t)const;
	int cmp(const MyDate& t)const;
	// int input(File fp);
	int input(std::istream& in = cin);
	// int output(File f);
	void output(std::ostream& out = cout)const;
	MyDate& operator = (const MyDate str); // �������� ������������ (���������� assign()) 
	operator const char* (); // �������� �������������� ���� �� MyDate � char* ���������� _itoa
	friend ostream& operator <<(ostream&, const MyDate&); // �������� ������ (����������output())
	friend istream& operator >>(istream&, MyDate&); // �������� ����� (���������� input()) 
	friend int operator ==(const MyDate&, const MyDate&); // �������� ��������� (����������equal())
	friend int operator !=(const MyDate&, const MyDate&); // �������� ��������� (����������equal())
	friend int operator <= (const MyDate&, const MyDate&); // �������� ��������� (����������cmp())
	friend int operator >= (const MyDate&, const MyDate&); // �������� ��������� (����������cmp())
	friend int operator < (const MyDate&, const MyDate&); // �������� ��������� (����������cmp())
	friend int operator > (const MyDate&, const MyDate&); // �������� ��������� (����������cmp())

	MyDate& operator +=(long); // �������� ���������� ���� (���������� add_Days()) 
	friend MyDate operator +(const MyDate&, long d); // �������� �������� (���������� +=) 
	friend long operator -(const MyDate&, const MyDate&); // �������� ��������� ���� ���.
	//���������� ���������� ���� ����� ���� ���������� ToLong

	MyDate& operator++(); //��������� (���������� +=)
	MyDate operator++(int);// ����������� (���������� +=)
	MyDate& operator--();//��������� (���������� +=)
	MyDate operator--(int);// ����������� (���������� +=)
};
#pragma once
#include <iostream>
#include "MyString.h"
#include "MyDate.h"
using namespace std;
class Product
{
	// ��������
	MyString name;
	long count; // ����������� �����
	double price; // ����
	MyDate date;
public:
	Product();
	Product(char* a, int n, int p, int d, int m, int y);
	Product(const Product&);
	~Product(); // ����������� ���������� ������ ��� �������� Product
	Product* copy();
	void dispose() {}
	int equal(const Product&)const; // �������, ����������� ��������� �������� ����� �������.������������ ��� ������
	int cmp(const Product&)const; // �������, ������������ ������ ������������ ��� ����������
	int input(istream& Cin = cin);
	void output(ostream& os = std::cout)const;


	friend int operator == (const Product&, const Product&);// �������� ���������(�������� equal())
	friend int operator != (const Product&, const Product&);
	friend int operator <(const Product&, const Product&);
	friend int operator <= (const Product&, const Product&);
	friend int operator > (const Product&, const Product&);
	friend int operator >= (const Product&, const Product&);
	friend ostream& operator <<(ostream&, const Product&); // �������� �����a(�������� output())
	friend istream& operator >>(istream&, Product&);// �������� ����� (��������input())
};
typedef Product* T;
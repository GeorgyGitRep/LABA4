#pragma once
#include <iostream>
using namespace std;
class MyString {
	char* s;
	int len;
public:
	MyString();
	MyString(const MyString&);
	MyString(char*);
	~MyString();
	char& item(int);
	MyString* copy();
	void assign(const MyString&);
	int cmp(const MyString&)const;
	int equal(const MyString&)const;
	int input(istream& Cin = cin);
	void output(ostream& Cout = cout)const;
	int length();
	int length()const;

	// ���������� ����������
	MyString& operator=(const MyString&);// �������� ������������ (�������� assign()) 
	operator char* ();// �������� �������������� ���� �� MyString � char*
	friend int operator == (const MyString&, const MyString&);// �������� ���������	(�������� equal())
	friend int operator != (const MyString&, const MyString&);
	friend int operator <(const MyString&, const MyString&);
	friend int operator <= (const MyString&, const MyString&);
	friend int operator > (const MyString&, const MyString&);
	friend int operator >= (const MyString&, const MyString&);
	char& operator[](int i); // �������� �������������� �������� (�������� item())
	MyString& operator+=(const MyString&);// �������� ���������� � ����� (������ strcat()
	friend MyString operator + (const MyString&, const MyString&);// ��������� ��� ������))
	friend ostream& operator<<(ostream&, const MyString&); // �������� ������ (��������	output())
	friend istream& operator>>(istream&, MyString&);// �������� ����� (�������� input()) 
};

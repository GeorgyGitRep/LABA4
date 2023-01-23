#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"	
#include <string.h>
int MyString::length()
{
	return len;
}
int MyString::length()const
{
	return len;
}
MyString::MyString()
{
	s = new char[1];
	*s = '\0';
	len = 0;
}
MyString::MyString(char* t)
{
	s = new char[strlen(t) + 1];
	*s = '\0'; strcpy(s, t);
	len = strlen(t);
}
MyString::MyString(const MyString& u)
{
	s = new char[u.len + 1];
	*s = '\0'; strcpy(s, u.s);
	len = u.len;
}
MyString::~MyString()
{
	delete[] s;
}
char& MyString::item(int t)
{
	if (t <= len && t >= 0)
		return s[t];
	cout << "Error.";
	exit(1);
}
MyString* MyString::copy()
{
	return new MyString(*this);
}
void MyString::assign(const MyString& u)
{
	s = new char[u.len + 1];
	*s = '\0'; strcpy(s, u.s);
	len = u.len;
}
int MyString::cmp(const MyString& t)const
{
	return strcmp(s, t.s);
}
int MyString::equal(const MyString& t)const
{
	return strcmp(s, t.s) == 0;
}
int MyString::input(istream& Cin)
{
	if (Cin.eof())return 0;
	char buf1[256];
	Cin.getline(buf1, 254, '\n');
	if (strlen(buf1) == 0) Cin.getline(buf1, 254, '\n');
	s = new char[strlen(buf1) + 1]; len = strlen(buf1);
	*s = '\0';
	strcpy(s, buf1);
	return 0;
}
void MyString::output(ostream& Cout)const {
	Cout << s << endl;

}
// ���������� ����������
MyString& MyString::operator=(const MyString& t) {
	if (this == &t) // ������������� �������� ����������� ������� ��� ������������ 	������ ����.��������.s = s
		return *this;
	delete[]s;
	s = new char[(len = t.len) + 1];
	strcpy(s, t.s);
	return *this;
} // ����������� ������� �� ������ ����������� ����������� ���������� ���������� ���������
MyString::operator char* ()// �������� �������������� ����
//�������� ��������:
//1. �� ����������� ������������ ��������
//2. ��� ��������� � ������ ����
//3. ����������� ���������
{
	char* p = new char[len + 1];
	strcpy(p, s);
	return p;
} //�������� ����� ��������� ������ s ��������� ������ ����� ��������� ������, //������� ��� �� ������������� �������������
int operator == (const MyString& a, const MyString& b) {
	return !(a.cmp(b));
}
int operator != (const MyString& a, const MyString& b) {
	return a.cmp(b);
}
int operator < (const MyString& a, const MyString& b) {
	return (a.cmp(b) < 0);
}
int operator <= (const MyString& a, const MyString& b) {
	return (a.cmp(b) <= 0);
}
int operator > (const MyString& a, const MyString& b) {
	return (a.cmp(b) > 0);
}
int operator >= (const MyString& a, const MyString& b) {
	return (a.cmp(b) >= 0);
}
char& MyString::operator[](int i) {
	if (i > 0 && i <= len) //�������������� �������� ������
		return s[i];
	cout << "Index error"; exit(1);
}
MyString& MyString::operator+=(const MyString& t) {
	char* p = new char[len = (len + t.len) + 1];
	strcpy(p, s); strcat(p, t.s);
	delete[]s; s = p;
	return *this;
}
MyString operator +(const MyString& a, const MyString& b) {
	MyString tmp = a;
	tmp += b;
	return tmp;
}
ostream& operator<<(ostream& os, const MyString& ms) {
	ms.output(os);

	return os;
} // ����������� ������� �� ������ ����������� ����������� ���������� ���������� ���������
istream& operator>>(istream& is, MyString& ms) {
	ms.input(is);
	return is;
}
#include<iostream>
using namespace std;


class A1
{
protected:
	int a1;
public:
	A1(int n = 0) { a1 = n; cout << "\nКонструктор класса 'A1'"; }
	virtual void print() { cout << "\nИмя класса: A1"; }
	virtual void show() { cout << "\na1 = " << a1; }
};

class B1 : virtual public A1
{
protected:
	int b1;
public:
	B1(int n = 0, int m = 0) : A1(m) 
	{
		b1 = n;
		cout <<"\nКонструктор класса 'B1'";
	}
	virtual void print() { cout << "\nИмя класса: B1"; }
	virtual void show()
	{
		cout << "\nb1 = " << b1 << ", a1 ="<<a1; 
	}

class C1 : virtual public B1
{
protected:
	int c1;
public:
	C1(int n = 0, int m = 0, int k = 0) : B1(k), A1(m)
	{
		c1 = n;
		cout << "\nКонструктор класса 'C1'";
	}

	virtual void print() { cout << "\nИмя класса: C1"; }
	virtual void show()
	{
		cout << "\nc1 = "<< c1 <<", b1 = " << b1 << ", a1 = " << a1;
	}

}

class C2 : virtual public B1
{
protected:
	int c2;
public:
	C2(int n = 0, int m = 0, int k = 0) : B1(k), A1(m)
	{
		c2 = n;
		cout << "\nКонструктор класса 'C2'";
	}

	virtual void print() { cout << "\nИмя класса: C2"; }
	virtual void show()
	{
		cout << "\nc2 = " << c2 << ", b1 = " << b1 << ", a1 = " << a1;
	}

}
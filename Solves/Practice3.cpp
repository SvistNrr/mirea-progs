#include<iostream>
using namespace std;


class A1
{
protected:
	int a1;
public:
	A1(int n = 0) { a1 = n; cout << "\nClass Constructor 'A1'"; }
	virtual void print() { cout << "\nClass: A1"; }
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
		cout << "\nClass Constructor 'B1'";
	}
	virtual void print() { cout << "\nClass: B1"; }
	virtual void show()
	{
		cout << "\nb1 = " << b1 << ", a1 =" << a1;
	}
};

class C1 : virtual public B1
{
protected:
	int c1;
public:
	C1(int n = 0, int m = 0, int k = 0) : B1(m, k), A1(k)
	{
		c1 = n;
		cout << "\nClass Constructor 'C1'";
	}

	virtual void print() { cout << "\nClass: C1"; }
	virtual void show()
	{
		cout << "\nc1 = " << c1 << ", b1 = " << b1 << ", a1 = " << a1;
	}

};

class C2 : virtual public B1
{
protected:
	int c2;
public:
	C2(int n = 0, int m = 0, int k = 0) : B1(m, k), A1(k)
	{
		c2 = n;

		cout << "\nClass Constructor 'C2'";
	}

	virtual void print() { cout << "\nClass: C2"; }
	virtual void show()
	{
		cout << "\nc2 = " << c2 << ", b1 = " << b1 << ", a1 = " << a1;
	}

};

int main()
{
	A1 test_a;
	cout << '\n' << "/////////////" << '\n';

	B1 test_b(4, 9);
	cout << '\n' << "/////////////" << '\n';

	C1 test_c1(7);
	cout << '\n' << "/////////////" << '\n';

	C2 test_c2(8, 6, 3);
	cout << '\n' << "/////////////" << '\n';

	test_a.print();
	test_b.print();
	test_c1.print();
	test_c2.print();

	cout << '\n' << "/////////////" << '\n';

	test_a.show();
	test_b.show();
	test_c1.show();
	test_c2.show();
	return 0;
}
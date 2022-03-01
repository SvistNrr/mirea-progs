#include <iostream>

using namespace std;

class Circle
{
private:
	double radius;
	double coord_x;
	double coord_y;
public:
	Circle() { cout << "\nConstructor_0 is working: "; radius = 1; coord_x = coord_y = 0; }

	Circle(double R) { cout << "\nConstructor_1 is working: "; radius = R; coord_x = coord_y = 0; }

	Circle(double R, double x) {cout << "\nConstructor_2 is working: "; radius = R; coord_x = x; coord_y = 0;}

	Circle(double R, double x, double y) {cout << "\nConstructor_3 is working: "; coefc = c; coefb = b; coefa = a;}

	//функция сложения полиномов(справа)
	Circle operator+(double number)
	{
		Circle Custom;
		Custom.radius = radius + number;
		Custom.coord_x= coord_x;
		Custom.coord_y = coord_y;
		return Custom;
	}

	//функция сложения полиномов(слева)
	friend Polynomial2 operator+(double chislo, Polynomial2 P);


	//функция вычитания полиномов
	Polynomial2 operator-(Polynomial2 P)
	{
		Polynomial2 Result2;
		Result2.coefc = coefc - P.coefc;
		Result2.coefb = coefb - P.coefb;
		Result2.coefa = coefa - P.coefa;
		return Result2;
	}

	//функция умножения полиномов на число(справа)
	Polynomial2 operator*(double chislo)
	{
		Polynomial2 Result3;
		Result3.coefc = coefc * chislo;
		Result3.coefb = coefb * chislo;
		Result3.coefa = coefa * chislo;
		return Result3;
	}

	//перегрузка функции сложения: вместо полинома объект стандартного типа(например число)
	Polynomial2 operator+(double c)
	{
		Polynomial2 Result1;
		Result1.coefc = coefc + c;
		return Result1;
	}

	//равенство полиномов
	Polynomial2 operator==(Polynomial2 P)
	{
		return ((coefc == P.coefc) && (coefb == P.coefb) && (coefa == P.coefa));
	}

	//неравенство полиномов
	Polynomial2 operator!=(Polynomial2 P)
	{
		return ((coefc != P.coefc) || (coefb != P.coefb) || (coefa != P.coefa));
	}

	//унарный оператор минус
	Polynomial2 operator-()
	{
		Polynomial2 Result;
		Result.coefc = -coefc;
		Result.coefb = -coefb;
		Result.coefa = -coefa;
	}


	//деструктор
	~Polynomial2() { cout << "\nDestructor is working"; }

	//геттеры и сеттеры
	double getCoef0() { return coefc; }
	double getCoef1() { return coefb; }
	double getCoef2() { return coefa; }

	void setCoef0(double value) { coefc = value; }
	void setCoef1(double value) { coefb = value; }
	void setCoef2(double value) { coefa = value; }

	//вывод
	void print() { cout << coefa << "x^2 + " << coefb << "x + " << coefc; }
};

Polynomial2 operator+(double chislo, Polynomial2 P)
{
	Polynomial2 Result;
	Result.coefc = chislo + P.coefc;
	Result.coefb = P.coefb;
	Result.coefa = P.coefa;
	return Result;
}


int main()
{
	Polynomial2 P1(1, 2, 3);
	Polynomial2 P2(3, 2, 1);
	Polynomial2 P3(5, 10, 16);
	Polynomial2 P_test1 = P1 + P2;
	Polynomial2 P_test2 = P3 - P1;
	Polynomial2 P_test3 = P1 * 4;

	cout << "\nSum: P1 + P2 = "; P_test1.print();
	cout << "\nSubtraction: P1 - P2 = "; P_test2.print();
	cout << "\nMultiplication by number: P1 * 4 = "; P_test3.print();
	cout << "\n";
}
© 2022 GitHub, Inc.
Terms
Privacy
Security
Status
Docs
Contact GitHub
Pricing
API
Training
Blog
About


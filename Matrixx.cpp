#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;


class BaseMatrix
{
protected:
	double** ptr;
	int height;
	int width;
public:
	BaseMatrix(int Height = 2, int Width = 2)
	{
		//по умолчанию
		height = Height;
		width = Width;
		ptr = new double* [height];
		for (int i = 0; i < height; i++)
			ptr[i] = new double[width];
	}

	BaseMatrix(const BaseMatrix& M)
	{
		height = M.height;
		width = M.width;
		ptr = new double* [height];
		for (int i = 0; i < height; i++)
			ptr[i] = new double[width];

		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; i++)
				ptr[i][j] = M.ptr[i][j];
	}

	~BaseMatrix()
	{
		//деструктор
		if (ptr != NULL)
		{
			for (int i = 0; i < height; i++)
				delete[] ptr[i];
			delete[] ptr;
			ptr = NULL;
		}
	}
	BaseMatrix& operator=(BaseMatrix& M2)
	{
		if (M2.height == height && M2.width == width)
		{
			for (int i = 0; i < height; i++)
				for (int j = 0; j < width; i++)
					ptr[i][j] = M2.ptr[i][j];
		}
		else
		{
			throw UnEqualSizeException("Unequal size of equaling matrices in operator", height, width, M2.height, M2.width);
		}
	}

	double* operator[](int index)
	{
		if (index < 0 || index >= height) { throw IndexOutOfBounds("Wrong Index in operator []", index, -1); }
	}

	double& operator()(int index1, int index2)
	{
		if (((index1 < height) & (index2 < width)) & ((index1 > 0) & (index2 > 0)))
		{
			return ptr[index1][index2];
		}
		else { throw IndexOutOfBounds("Wrong Index in operator ()", index1, index2); }
	}

	BaseMatrix operator+(BaseMatrix& M3)
	{
		if (height != M3.height || width != M3.width)
		{
			throw UnEqualSizeException("Unequal size of plusing matrices in operator", height, width, M3.height, M3.width);
		}
		else
		{
			for (int i = 0; i < height; i++)
				for (int j = 0; j < width; i++)
					ptr[i][j] += M3.ptr[i][j];
		}
	}
	BaseMatrix operator+(double d)
	{
		BaseMatrix Matrixx(height, width);
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; i++)
				if (i == j)
				{
					Matrixx.ptr[i][j] = ptr[i][j] + d;
				}
				else
				{
					Matrixx.ptr[i][j] = ptr[i][j];
				}
		return Matrixx;
	}



	BaseMatrix operator+() //транспонирование
	{
		BaseMatrix M_transpon(width, height);
		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; i++)
				ptr[i][j] = M_transpon.ptr[i][j];
		return M_transpon;
	}

	void print()
	{
		//âûâîä
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				cout << ptr[i][j] << " ";
			cout << "\n";
		}
	}

};

class Exception : public exception //ИСКЛЮЧЕНИЯ
{
protected:
	//сообщение об ошибке
	char* str;
public:
	Exception() { str = NULL; }

	Exception(const char* s)
	{
		str = new char[strlen(s) + 1];
		strcpy_s(str, strlen(s) + 1, s);
	}
	Exception(char* s)
	{
		str = new char[strlen(s) + 1];
		strcpy_s(str, strlen(s) + 1, s);
	}
	Exception()
	{
		str = NULL;
	}
	Exception(const Exception& e)
	{
		str = new char[strlen(e.str) + 1];
		strcpy_s(str, strlen(e.str) + 1, e.str);
	}
	~Exception()
	{
		delete[] str;
	}

	//функцию вывода можно будет переопределить в производных классах, когда будет ясна конкретика
	virtual void print()
	{
		cout << "Exception: " << str << "; " << what();
	}
};


class UnEqualSizeException : public Exception //ошибка совместимости размерности матриц
{
protected: 
	int Rows1; int Cols1; int Rows2; int Cols2;
public:
	UnEqualSizeException(char* s, int rows1, int cols1, int rows2, int cols2) : Exception(s)
	{rows1 = Rows1; cols1 = Cols1; rows2 = Rows2; cols2 = Cols2;}

	UnEqualSizeException(const char* s, int rows1, int cols1, int rows2, int cols2) : Exception(s)
	{rows1 = Rows1; cols1 = Cols1; rows2 = Rows2; cols2 = Cols2;}

	UnEqualSizeException(const UnEqualSizeException& e)
	{
		str = new char[strlen(e.str) + 1];
		strcpy_s(str, strlen(e.str) + 1, e.str);
		Rows1 = e.Rows1; Cols1 = e.Cols1; Rows2 = e.Rows2; Cols2 = e.Cols2;
	}

	virtual void print()
	{
		cout << "UnEqualSizeException:" << str << " ;" << what();
	}
};

class IndexOutOfBounds : public Exception //неадекватный индекс(слишком большой или отрицательный)
{
protected:
	int RowIndex; int ColumnIndex;
public:
	IndexOutOfBounds(char* s, int rowindex, int columnindex) : Exception(s)
	{
		RowIndex = rowindex; ColumnIndex = columnindex;
	}

	IndexOutOfBounds(const char* s, int rowindex, int columnindex) : Exception(s)
	{
		RowIndex = rowindex; ColumnIndex = columnindex;
	}

	IndexOutOfBounds(const IndexOutOfBounds& e)
	{
		str = new char[strlen(e.str) + 1];
		strcpy_s(str, strlen(e.str) + 1, e.str);
		RowIndex = e.RowIndex; ColumnIndex = e.ColumnIndex;
	}

	virtual void print()
	{
		cout << "IndexOutOfBounds:" << str << " ;" << what();
	}
};

friend ostream& operator<<(ostream& s, BaseMatrix M);
friend istream& operator>>(istream& s, BaseMatrix& M);

ostream& operator<<(ostream& s, BaseMatrix M)
{
	if (typeid(s) == typeid(ifstream))
	{
		s << M.height << " " << M.width << " ";
		for (int i = 0; i < M.height; i++)
			for (int j = 0; j < M.width; j++)
				s << M.ptr[i][j] << " ";
	}
	else
	{
		for (int i = 0; i < M.height; i++)
			for (int j = 0; j < M.width; j++)
				s << "\n" << "M[" << i << "][" << j << "] = " << M.ptr[i][j] << " ";
			s << "\n";
		return s
	}
}

istream& operator>>(istream& s, BaseMatrix& M)
{
	if (typeid(s) == typeid(ifstream))
	{
		int h, v;
		s >> h >> w;
		if (w!= M.width || h!= M.height)
			throw UnEqualSizeException("Matrixes of inequal sizes while reading file", h, w, M.height, M.width)
	}
	else
	{
		for (int i = 0; i < M.height; i++)
		{
			for (int j = 0; j < M.width; j++)
			{
				s >> M.ptr[i][j];
			}
		}
		return s
	}

}





int main()
{
	try
	{
		BaseMatrix M;
		M(0, 0) = 1; M(0, 1) = 2; M(1, 0) = 3; M(1, 1) = 4;
		BaseMatrix M2(3, 3); M2(0, 0) = 2; M2(1, 0) = 3; M2(1, 1) = 1;
		BaseMatrix M3 = M + M2;
		M.print();
	}

	catch (UnEqualSizeException e) { e.print(); }
	catch (IndexOutOfBounds e) { e.print(); }

	char c; cin >> c;

	return 0;
}


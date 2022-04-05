#include "stdafx.h"
#include <iostream>

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
		//конструктор
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
	}

	double& operator()(int index1, int index2)
	{
		return ptr[index1][index2]
	}

	BaseMatrix operator+(BaseMatrix& M3)
	{
		if (height != M3.height || width != M3.width)
		{

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
		return Matrixx
	}



	BaseMatrix operator+() //транспонирование
	{
		BaseMatrix M_transpon(width, height);
		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; i++)
				ptr[i][j] = M_transpon.ptr[i][j];
		return M_transpon
	}

	void print()
	{
		//вывод
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
				cout << ptr[i][j] << " ";
			cout << "\n";
		}
	}

};


int main()
{
	BaseMatrix M;

	M.print();
	
	char c; cin >> c;

	return 0;
}


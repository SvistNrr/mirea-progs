#include <iostream>

using namespace std;

class MyArrayParent

{

protected:
	int capacity;
	int count;
	double* ptr;

public:

	//конструкторы и деструктор

	MyArrayParent(int Dimension = 100)

	{

		cout << "\nMyArrayParent constructor";

		ptr = new double[Dimension];

		capacity = Dimension;

		count = 0;

	}

	//конструктор принимает существующий массив

	MyArrayParent(double* arr, int len)

	{

		cout << "\nMyArrayParent constructor";

		capacity = (len < 100) ? 100 : len;

		ptr = new double[capacity];

		count = len;

		for (int i = 0; i < len; i++)

			ptr[i] = arr[i];

	}

	//деструктор

	~MyArrayParent()

	{

		cout << "\nMyArrayParent destructor";

		if (ptr != NULL)

		{

			delete[] ptr;

			ptr = NULL;

		}

	}

	//обращение к полям

	int Capacity() { return capacity; }

	int Size() { return count; }

	double GetComponent(int index)

	{

		if (index >= 0 && index < count)

			return ptr[index];


		return -1;

	}

	void SetComponent(int index, double value)
	{
		if (index >= 0 && index < count)
			ptr[index] = value;
	}

	//добавление в конец нового значения

	void push(double value)
	{
		if (count < capacity)
		{
			ptr[count] = value;
			count++;
		}
	}

	//удаление элемента с конца

	void RemoveLastValue()
	{
		if (count > 0)
			ptr[count - 1] = 0;
		count--;
	}

	double& operator[](int index)
	{
		return ptr[index];
	}

	MyArrayParent(const MyArrayParent& V)
	{
		capacity = V.capacity;
		count = V.count;
		ptr = new double[capacity];

		for (int i = 0; i < V.count; i++)
		{
			ptr[i] = V.ptr[i];
		}
	}


	MyArrayParent& operator=(MyArrayParent& V)
	{
		if (capacity < V.capacity)
		{
			delete[] ptr; ptr = nullptr;

			ptr = new double[V.capacity];

			capacity = V.capacity;

		}
		if (capacity == V.capacity)
		{
			count = V.count;
			capacity = V.capacity;
			ptr = new double[capacity];
			for (int i = 0; i < count; i++)
				ptr[i] = V.ptr[i];
		}
		return *this;
	}

	void print()
	{
		cout << "\nMyArrParent, size: " << count << ", values: {";
		int i = 0;
		for (i = 0; i < count; i++)
		{
			cout << ptr[i];
			if (i != count - 1)
				cout << ", ";
		}
		cout << "}";
	}

};


class MyArrayChild : public MyArrayParent

{

public:

	//используем конструктор родителя. Нужно ли что-то ещё?

	MyArrayChild(int Dimension = 100) : MyArrayParent(Dimension) { cout << "\nMyArrayChild constructor"; }

	MyArrayChild(double* arr, int len) : MyArrayParent(arr, len) { cout << "\nMyArrayChild constructor"; }

	~MyArrayChild() { cout << "\nMyArrayChild destructor\n"; }

	//удаление элемента

	void RemoveAt(int index = -1)
	{
		if (index == -1)
		{
			RemoveLastValue();
			return;
		}
		int i;
		if (count > 0)
		{
			for (i = index + 1; i < count - 1; i++)
			{
				ptr[i] = ptr[i + 1];
			}
			count--;
		}
	}

	//поиск элемента

	int IndexOf(double value, bool bFindFromStart = true)
	{
		if (bFindFromStart)
		{
			int i;
			for (i = 0; i < count; i++)
			{
				if (ptr[i] == value)
					return i;
			}
			return -1;
		}
		else
		{
			int i;
			for (i = count - 1; i >= count; i--)
			{
				if (ptr[i] == value)
					return i;
			}
			return -1;
		}
	}

	//вставка элемента

	void InsertAt(double value, int index = -1)
	{
		if (index == -1)
		{
			push(value);
			return;
		}
		if (count < capacity)
		{
			for (int i = count - 1; i >= index; i--)
			{
				ptr[i + 1] = ptr[i];
			}
			ptr[index] = value;
			count++;
		}
	}

	void Average()
	{

		int i = 1;
		for (i = 1; i < count; i++)
		{
			ptr[i] = (ptr[i - 1] + ptr[i + 1]) / 2;
		}
	}
};

class MySortedArray : public MyArrayChild
{
protected:
	int BinSearch(double value, int left, int right) //бинарный поиск
	{
		int middle = (left + right) / 2;
		if (fabs(ptr[middle] - value) < 0.001)
			return middle;

		if (right - left <= 1)
		{
			if (fabs(ptr[right] - value) < 0.001)
				return right;
			if (ptr[left] > value)
				return left;
		}

		if (value > ptr[middle])
			return BinSearch(value, middle + 1, right);
		if (value < ptr[middle])
			return BinSearch(value, left, middle - 1);
	}
public:
	MySortedArray(int Dimension = 1000) : MyArrayChild(1000) { cout << "\nMySortedArray конструктор 1 был создан"; }

	MySortedArray(double* arr, int len)
	{

		cout << "\nMySortedArray constructor2 был создан";

		capacity = (len < 128) ? 128 : len;

		ptr = new double[capacity];

		count = len;

		for (int i = 0; i < len; i++)

			ptr[i] = arr[i];

	}

	~MySortedArray() { cout << "\nMySortedArray деструктор"; }

	int IndexOf(double value, bool bFindFrontStart = true)
	{
		return BinSearch(value, 0, count);
	}

	void push(double value)
	{
		if (count == 0)
		{
			MyArrayParent::push(value);
			return;
		}
		if (count == 1)
		{
			if (value > ptr[0]) { MyArrayChild::InsertAt(value, 0); }
			else {}
		}
		else
			if (value >= ptr[count - 1]) { (*this).MyArrayParent::push(value); }
			else if (value <= ptr[0]) { (*this).MyArrayChild::InsertAt(value, 0); }
			else {
				int index_new = (*this).BinSearch(value, 0, count);
				(*this).MyArrayChild::InsertAt(value, index_new);
			}
	}
};


int main()
{
	MyArrayParent arr;
	if (true)
	{
		double a[] = {1,2,3,4,5};
		MyArrayChild arr(a, 5);
		arr.print();
		arr.RemoveLastValue();
		arr.print();
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			arr.push(i + 1);
		}
		cout << "\n" << "5: " << arr.IndexOf(5) << "\n";
		arr.InsertAt(5, 2);
		arr.print();
		arr.RemoveAt(5);
		arr.print();
		arr.Average();
		arr.print();
		cout << "\n";

		//работа с указателем на базовый класс
		double b[] = {5,6,7,8,9};
		MySortedArray arr(b, 5);
		MyArrayChild* t;
		t = &arr;
		t->print();



	}
}

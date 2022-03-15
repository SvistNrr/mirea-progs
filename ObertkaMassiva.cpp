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

		//сгенерировать исключение, если индекс неправильный

		return -1;

	}

	void SetComponent(int index, double value)
	{
		if (index >= 0 && index < count)
			ptr[index] = value;
		//сгенерировать исключение, если индекс неправильный
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
		//что делаем, если пуст?
	}

	double& operator[](int index)
	{
		return ptr[index];
	}

	/*MyArrayParent& operator=(const Vector& V)

	{

	//оператор =

	//arr1 = arr2 = arr3; где arr_i - объекты нашего класса

	}*/

	MyArrayParent(const MyArrayParent& V)
	{
		count = V.count;
		capacity = V.capacity;
		ptr = new double[capacity];
		for (int i = 0; i < count; i++)
			ptr[i] = V.ptr[i];

	}

	MyArrayParent& operator=(MyArrayParent& V)
	{
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
	MySortedArray(int Dimension = 1000) : MyArrayChild(1000) {}
	~MySortedArray() {}

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

	}
};

void f(MyArrayParent P)

{

}

int main()
{
	// myArrayParent arr;
	if (true)
	{
		double a[] = { 1,2,3,4,5 };
		MyArrayChild arr(a, 5);
		arr.RemoveLastValue();
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			arr.push(i + 1);
		}
		cout << "\n" << "5: " << arr.IndexOf(5) << "\n";
		arr.InsertAt(5, 2);
		arr.RemoveAt(5);
		arr.print();
		cout << "\n";
		//cout « "\n" « sp « "\n";
	}
	char c; cin >> c;
	return 0;
}

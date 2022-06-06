#include <iostream>

using namespace std;

class BaseString
{
protected:
	char* p;
	int len;
	int capacity;
public:
	BaseString(char* ptr)
	{
		int itt = 0;
		while (ptr[itt] != '\0') { itt++; }
		len = itt;
		capacity = len * 4;
		p = new char[capacity];

		for (int itt = 0; itt < len; ++itt)
		{
			p[itt] = ptr[itt];
		}

		p[itt] = '\0';
		cout << "\nCopy getting работает\n";
	}

	BaseString(const char* ptr)
	{
		int itt = 0;
		while (ptr[itt] != '\0') { itt++; }
		len = itt;
		capacity = len * 4;
		p = new char[capacity];

		for (int itt = 0; itt < len; ++itt)
		{
			p[itt] = ptr[itt];
		}

		p[itt] = '\0';
		cout << "\nConst сopy getting работает\n";
	}

	BaseString(const BaseString& ptr)
	{
		p = new char[ptr.capacity];
		len = ptr.len;
		capacity = ptr.capacity;
		int itt = 0;
		while (ptr.p[itt++] != '\0') { p[itt] = ptr.p[itt]; }
		p[itt] = '\0';

	}

	BaseString(int Capacity = 256)
	{
		capacity = Capacity;
		p = new char[capacity];
		len = 0;
	}

	~BaseString()
	{
		cout << "\nДеструктор работает\n";
		if (p != NULL)
			delete[] p;
		len = 0;
	}

	int Length() { return len; }
	int Capacity() { return capacity; }
	
	char& operator[](int i) { return p[i]; }


	BaseString& operator=(const BaseString& s)
	{
		cout << "\nОператор = работает\n";
		int itt = 0;

		if (capacity < s.capacity)
		{
			delete[] p;
			p = nullptr;
			p = new char[s.capacity];
		}

		capacity = s.capacity;
		len = s.len;

		for (int itt = 0; itt < len; itt++) { p[itt] = s.p[itt]; }
		return *this;
	}


	virtual void print()
	{
		int i = 0;
		while (p[i] != '\0')
		{
			cout << p[i];
			i++;
		}
	}

};

class String_Practice4 : public BaseString
{
public:
	String_Practice4(int Capacity = 256) : BaseString(Capacity)
	{
		capacity = Capacity;
		p = new char[capacity];
		len = 0;
	}
	String_Practice4(char* ptr) : BaseString(ptr)
	{
		int itt = 0;
		while (ptr[itt] != '\0') { itt++; }
		len = itt;
		capacity = len * 4;
		p = new char[capacity + 1];

		for (int itt = 0; itt < len; ++itt)
		{
			p[itt] = ptr[itt];
		}

		p[itt] = '\0';
		cout << "\nConst сopy getting работает\n";
	}
	String_Practice4(const char* ptr) : BaseString(ptr)
	{
		int itt = 0;
		while (ptr[itt] != '\0') { itt++; }
		len = itt;
		capacity = len * 4;
		p = new char[capacity + 1];

		for (int itt = 0; itt < len; ++itt)
		{
			p[itt] = ptr[itt];
		}

		p[itt] = '\0';
		cout << "\nConst сopy getting работает\n";
	}

	~String_Practice4()
	{
		cout << "\nДеструктор работает\n";
		if (p != NULL)
			delete[] p;
		len = 0;
	}

	String_Practice4(const String_Practice4& ptr)
	{
		cout << "\nКонструктор копий работает\n";
		p = new char[ptr.capacity];
		len = ptr.len;
		capacity = ptr.capacity;
		int itt = 0;
		while (ptr.p[itt++] != '\0') { p[itt] = ptr.p[itt]; }
		p[len] = '\0';

	}

	int Length() { return len; }
	int Capacity() { return capacity; }
	char& operator[](int i) { return p[i]; }

	String_Practice4& operator=(const String_Practice4& s)
	{
		cout << "\nОператор = работает\n";
		int itt = 0;

		if (capacity < s.capacity)
		{
			delete[] p;
			p = nullptr;
			p = new char[s.capacity];
		}

		capacity = s.capacity;
		len = s.len;

		for (int itt = 0; itt < len; itt++) { p[itt] = s.p[itt]; }
		return *this;
	}

	String_Practice4 operator+(String_Practice4& s)
	{
		String_Practice4 contecate_string((capacity + s.capacity) * 2 >= 256 ? capacity + s.capacity : 256);
		contecate_string.len = len + s.len;
		for (int i = 0; i <= len; i++) { contecate_string.p[i] = p[i]; }
		for (int i = len; i < contecate_string.len; i++) { contecate_string.p[i] = s.p[i - len]; }
		contecate_string.p[contecate_string.len] = '\0';
		return contecate_string;
	};

	String_Practice4 reverse_function(String_Practice4& string_test)
	{
		String_Practice4 reverse_string;
		reverse_string.capacity = string_test.capacity;
		reverse_string.len = string_test.len;
		reverse_string.p = new char[string_test.capacity];
		for (int i = 0; i <= len; i++)
		{
			reverse_string.p[i] = string_test.p[len - i];
			reverse_string.p[len - i] = string_test.p[i];
		}
		return reverse_string;
	}


	int main()
	{
		if (true)
		{
			BaseString test1; test1 = "abcdef"; test1.print();
			BaseString* test2; test2 = &test1;
			test2->print();

			BaseString test3; test3 = "ggg";
			BaseString test4; test4 = "kkk";
			*test2 = test3 = test4; test2->print();

			String_Practice4 test_reverse; test_reverse = "strawberry";
			

		}
		char c; cin >> c;
		return 0;
	}
};
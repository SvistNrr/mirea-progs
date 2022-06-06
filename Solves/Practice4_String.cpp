#include <iostream>
#include <ostream>

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
	//char* get() {return p;}
	char& operator[](int i) { return p[i]; }


	BaseString& operator=(BaseString& s)
	{
		cout << "\nОператор = работает\n";
		int itt = 0;
		if (capacity >= s.capacity)
			while (s[itt++] != '\0') { p[itt] = s[itt]; }
		len = s.len;
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

	friend ostream& operator<<(ostream& os, const BaseString& str);
	friend ostream& operator>>(ostream& os, const BaseString& str);
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
		p = new char[capacity+1];

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
		p = new char[capacity+1];

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
		delete[] p;
		p = new char[ptr.capacity];
		len = ptr.len;
		capacity = ptr.capacity;
		int itt = 0;
		while (ptr.p[itt++] != '\0') { p[itt] = ptr.p[itt]; }
		p[itt] = '\0';

	}

	int Length() { return len; }
	int Capacity() { return capacity; }
	char& operator[](int i) { return p[i]; }

	String_Practice4& operator=(String_Practice4& s)
	{
		cout << "\nОператор = работает\n";
		int itt = 0;
		if (capacity >= s.capacity)
			while (s[itt++] != '\0') { p[itt] = s[itt]; }
		len = s.len;
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
		for (int i = 0; i <= len; i++)
			{
			char symbol;
			symbol = string_test.p[i];
			reverse_string.p[i] = string_test.p[len - i];
			reverse_string.p[len - i] = symbol;
			}
		return reverse_string;
	}


int main()
{
		if (true)
		{
			BaseString s("test");
			s.print();
			/*BaseString s1 = s;
			s1.print();
			BaseString s2;
			s2 = s;
			s2 = s + s1;
			s2.print();
			s1 = s2 + s;
			s1.print()*/
		}
		char c; cin >> c;
		return 0;
}
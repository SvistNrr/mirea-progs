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
		int itt=0;
		while (ptr[itt] != '\0') { itt++;}
		len = itt;
		capacity = len * 4;
		p = new char[capacity];

		for (int itt=0; itt<len; ++itt)
		{p[itt] = ptr[itt];}

		p[itt] = '\0';
		cout << "\nBase Constructor 1\n";
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
		cout << "\nBase Constructor 2\n";
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
		cout << "\nBase Constructor 0\n";
		capacity = Capacity;
		p = new char[capacity];
		len = 0;
	}

	~BaseString()
	{
		cout << "\nBase Destructor\n";
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
		cout << "\nBase Operator = \n";
		int itt=0;
		if (capacity >=s.capacity)
			while (s[itt++] != '\0') {p[itt] = s[itt];} 
		len = s.len;
		return *this;
	}

	BaseString(BaseString& s)
	{
		cout << "\nBase Copy Constructor\n";

	}
	BaseString operator+(BaseString& s)
	{

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

class String : public BaseString
{
public:
	String(int Capacity = 256) : BaseString(Capacity) {}
	String(char* ptr) : BaseString(ptr) {}
	String(const char* ptr) : BaseString(ptr) {}

	String(const String& ptr)
	{
		delete[] p;
		p = new char[ptr.capacity];
		len = ptr.len;
		capacity = ptr.capacity;
		int itt = 0;
		while (ptr.p[itt++] != '\0') { p[itt] = ptr.p[itt]; }
		p[itt] = '\0';
	}

	String operator+(String& s)
	{
		String contecate_string((capacity + s.capacity) * 2 >= 256 ? capacity + s.capacity : 256);
		contecate_string.len = len + s.len;
		for (int i = 0; i <= len; i++) { contecate_string.p[i] = p[i]; }
		for (int i = len; i < contecate_string.len; i++) { contecate_string.p[i] = s.p[i - len]; }
		contecate_string.p[contecate_string.len] = '\0';
		return contecate_string;
	};

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



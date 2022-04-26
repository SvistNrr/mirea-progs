
using namespace std;

#include <iostream>

template<class T>
class Element
{
	//protected:
public:
	//переместить в protected
	Element* next;
	Element* prev;
	T info;

	Element(T data)
	{
		next = prev = NULL;
		info = data;
	}

	Element(Element* Next, Element* Prev, T data)
	{
		next = Next;
		prev = Prev;
		info = data;
	}

	Element(const Element& el)
	{
		next = el.next;
		prev = el.prev;
		info = el.info;
	}

	template<class T1>
	friend ostream& operator<<(ostream& s, Element<T1>& el);

};

template<class T1>
ostream& operator<<(ostream& s, Element<T1>& el)
{
	s << "{";
	Element<T>* p = head;
	while (p != NULL)
	{
		s << p->info << " ";
		p = p->next;
	}
	s << "}"
		return s;
}

template<class T>
class LinkedList
{
	//protected:
public:
	//переместить в protected
	Element<T>* head;
	Element<T>* tail;
	int count;

	LinkedList()
	{
		head = tail = NULL;
		count = 0;
	}
	
	//получить первый/последний элемент списка
	//virtual Element<T>* front(T value) = 0;
	//virtual Element<T>* back(T value) = 0;

	//доступ по индексу
	//virtual Element<T>& operator[](int index) = 0;


	//доработать деструктор
	virtual ~LinkedList()
	{
		cout << "\nLinkedList destructor";
		Element<T>* p = head;
		Element<T>* q = head;
		for (; p != NULL; p = p->next)
		{
			q = p->next;
			delete p;
		}
	}

	template<class T1>
	friend ostream& operator<<(ostream& s, LinkedList<T1>& el);

};

template <class T>
class Stack : public LinkedList<T>
{
public:
	Stack() : LinkedList<T>() {}
	virtual ~Stack() { cout << "\Stack Destructor"; }
	
	virtual Element<T>* operator[](int index)
	{
		Element(T)* p == LinkedList<T>::head;
		while (index-- > 0)
			p = p->next;
		return p;
	}

	virtual Element<T>* pop()
	{
		if (LinkedList<T>::head == NULL)
			return NULL;
		Element<T>* result = LinkedList<T>::tail;

		if (LinkedList<T>::head == LinkedList<T>::tail)
		{
			LinkedList<T>::head == NULL;
			LinkedList<T>::tail == NULL;
			LinkedList<T>::count--;
			return result;

		}
		else
		{
		Element<T>* p = LinkedList<T>::head;
		while (p->next != LinkedList<T>::tail)
			p = p->next;
		Element<T>result = LinkedList<T>::tail;
		p->next = NULL;
		LinkedList<T>::tail = p;
		}
		LinkedList<T>::count--;

	}
	virtual Element<T>* push(T value)
	{
		if (LinkedList<T>::tail == NULL)
		{
			LinkedList<t>::tail = new Element<T>(value);
			LinkedList<t>::head = LinkedList<t>::tail;
		}
		else
		{
			Element<T>* newElem = new Element<T>*(value);
			LinkedList<t>::tail->next = newElem;
			LinkedList<t>::tail = LinkedList<t>::tail->next;
		}
		LinkedList<t>::count++;
		return LinkedList<t>::tail;
	}

	virtual Element<T>* insert(T value, Element<T>* predcessor = NULL)
	{
		if (LinkedList<T>::tail == NULL)
		{
			// if (Element<T>* predcessor != NULL) (throw ...)
			return push(value);
		}

		if (predcessor == NULL)
		{
			Element<T>* newElem = new Element<T>(value);
			newElem->next = LinkedList<t>::head;
			LinkedList<t>::head = newELem;
			LinkedList<t>::count++;
			return newElem;
		}
		Element<T>* newElem = new Element<T>(value);
		newElem->next = predecessor->next;
		predcessor->next = newElem;
		LinkedList<T>::count++;
		return newElem;

	}
	
	virtual Element<T>* find(T value) //поиск элемента и вывод указателя на него
	{
		Element<T>* p = LinkedList<t>::head;
		while (p != NULL)
		{
			if (p->info == value)
				return p;
			p = p->next;
		}
		return NULL
	}

	virtual Element<T>* find_r(T value) //рекурсивный поиск
	{
		return find_r(value, LinkedList<t>::head)
	}

	virtual Element<T>* find_r(T value, Element<T>* current) //рекурсивный поиск c текущим элементом
	{
		//база рекурсии
		if (current == NULL) return NULL;
		if (current->info == value) return current;

		return find_r(value, current->next)
	}
};

int main()
{

}

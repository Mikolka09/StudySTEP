#pragma once
#include"MyData.h"
#include<Windows.h>

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

template<class T, int size>
class List
{
	MyData<T>* first = nullptr;
	MyData<T>* last = nullptr;
	int length = 0;
public:
	~List();
	List<T, size>();
	List<T, size>(const List<T, size>& obj);//конструктор копирования
	void push_front(T val);
	void push_back(T val);
	void push_at(T val, int pos);
	T pop_front();
	T pop_back();
	T pop_at(int pos);
	T operator[](int pos);
	T peek_front();
	T peek_back();
	T peek_at(int pos) const;
	int getSize();
	bool ifEmpty();
	bool isFull();
	void print();
	void print(int x, int y);
	void clear();
	List<T, size> operator+(const List<T, size>& l);
	List<T, size> operator=(const List<T, size>& l);
	List<T, size> operator*(const List<T, size>& l);
	void sort();
	void sort_revers();
	friend ostream& operator<<(ostream& out, const List<T, size>& l);

};

template<class T, int size>
ostream& operator<<(ostream& out, const List<T, size>& l)
{
	l.print();
	return out;
}

template<class T, int size>
inline List<T, size>::~List()
{
	clear();
}

template<class T, int size>
inline List<T, size>::List()
{
	MyData<T>* first = nullptr;
	MyData<T>* last = nullptr;
	int length = 0;
}

template<class T, int size>
inline List<T, size>::List(const List<T, size>& obj)
{
	if (length)
	{
		clear();
	}
	this->first = obj.first;
	this->last = obj.last;
	this->length = obj.length;
}

template<class T, int size>
inline void List<T, size>::push_front(T val)
{
	if (length < size)
	{
		if (length == 0)
		{
			first = new MyData<T>;
			first->value = val;
			last = first;
		}
		else
		{
			MyData<T>* temp = new MyData<T>;
			temp->value = val;
			temp->next = first;
			first = temp;
		}
		length++;
	}
	else
		cout << "List overflow!" << endl;
}

template<class T, int size>
inline void List<T, size>::push_back(T val)
{
	if (length < size)
	{
		if (length == 0)
		{
			first = new MyData<T>;
			first->value = val;
			last = first;
		}
		else
		{
			MyData<T>* temp = new MyData<T>;
			temp->value = val;
			last->next = temp;
			last = temp;
		}
		length++;
	}
}

template<class T, int size>
inline void List<T, size>::push_at(T val, int pos)
{
	if (pos == 0)
		push_front(val);
	else
	{
		if (pos == length - 1)
			push_back(val);
		else
		{
			if (length < size)
			{
				MyData<T>* temp = new MyData<T>;
				temp->value = val;
				MyData<T>* num = first;
				for (size_t i = 0; i < pos - 1; i++)
				{
					num = num->next;
				}
				temp->next = num->next;
				num->next = temp;
				length++;
			}
			else
				cout << "List overflow" << endl;
		}
	}
}

template<class T, int size>
inline T List<T, size>::pop_front()
{
	if (length)
	{
		MyData<T>* temp = first;
		first = first->next;
		T val = temp->value;
		//delete temp;
		length--;
		return val;
	}
	else
		cout << "List Empty" << endl;
}

template<class T, int size>
inline T List<T, size>::pop_back()
{
	MyData<T>* temp = first;
	T val = last->value;
	for (size_t i = 0; i < length - 2; i++)
	{
		temp = temp->next;
	}
	delete last;
	last = temp;
	last->next = nullptr;
	length--;
	return val;
}

template<class T, int size>
inline T List<T, size>::pop_at(int pos)
{
	if (pos == 0)
		pop_front();
	else
	{
		if (pos == length - 1)
			pop_back();
		else
		{
			MyData<T>* temp = first;
			for (size_t i = 0; i < pos - 1; i++)
			{
				temp = temp->next;
			}
			MyData<T>* num = temp->next;
			T val = num->value;
			temp->next = num->next;
			delete num;
			length--;
			return val;
		}
	}

}

template<class T, int size>
inline T List<T, size>::operator[](int pos)
{
	if (pos >= 0 && pos < length)
	{
		MyData<T>* temp = first;
		for (size_t i = 0; i < pos; i++)
		{
			temp = temp->next;
		}
		return temp->value;
	}
	return last->value;
}

template<class T, int size>
inline T List<T, size>::peek_front()
{
	return first->value;
}

template<class T, int size>
inline T List<T, size>::peek_back()
{
	return last->value;
}

template<class T, int size>
inline T List<T, size>::peek_at(int pos) const
{
	if (pos >= 0 && pos < length)
	{
		MyData<T>* temp = first;
		for (size_t i = 0; i < pos; i++)
		{
			temp = temp->next;
		}
		return temp->value;
	}
	return last->value;
}

template<class T, int size>
inline int List<T, size>::getSize()
{
	return length;
}

template<class T, int size>
inline bool List<T, size>::ifEmpty()
{
	return length == 0;
}

template<class T, int size>
inline bool List<T, size>::isFull()
{
	return length == size;
}

template<class T, int size>
inline void List<T, size>::print()
{
	if (length == 0)
	{
		cout << "List empty" << endl;
		return;
	}
	MyData<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

template<class T, int size>
inline void List<T, size>::print(int x, int y)
{
	int y1 = y;
	gotoxy(x, y1);
	int begin = (length < 10) ? 0 : length - 10;
	for (size_t i = begin; i < length; i++)
	{
		gotoxy(x, y1);
		cout << this->operator[](i);
		y1++;
	}
}

template<class T, int size>
inline void List<T, size>::clear()
{
	while (length)
	{
		pop_front();
	}
	first = last = nullptr;
	cout << "List cleared!" << endl;
}

template<class T, int size>
inline List<T, size> List<T, size>::operator+(const List<T, size>& l)
{
	this->last->next = l.first;
	this->last = l.last;
	this->last->next = nullptr;
	this->length += l.length;
	return *this;
}

template<class T, int size>
inline List<T, size> List<T, size>::operator=(const List<T, size>& obj)
{
	if (length)
	{
		clear();
	}
	this->first = obj.first;
	this->last = obj.last;
	this->length = obj.length;
	return *this;
}

template<class T, int size>
inline List<T, size> List<T, size>::operator*(const List<T, size>& l)
{
	List<T, 10> temp;
	int val = 0;
	for (size_t i = 0; i < this->length; i++)
	{
		for (size_t j = 0; j < l.length; j++)
		{
			if (this->peek_at(i) == l.peek_at(j))
			{
				val = l.peek_at(j);
				temp.push_front(val);
			}

		}
	}
	this->clear();
	*this = temp;
	return *this;
}

template<class T, int size>
inline void List<T, size>::sort()
{
	List<T, 10> temp;
	while (length)
	{
		int i = 0;
		int max = this->peek_at(0);
		int imax = 0;
		for (size_t j = i + 1; j < length; j++)
		{
			if (this->peek_at(j) > max)
			{
				max = this->peek_at(j);
				imax = j;
			}
			i++;
		}
		temp.push_front(max);
		this->pop_at(imax);
	}
	this->clear();
	*this = temp;
}

template<class T, int size>
inline void List<T, size>::sort_revers()
{
	List<T, 10> temp;
	while (length)
	{
		int i = 0;
		int min = this->peek_at(0);
		int imin = 0;
		for (size_t j = i + 1; j < length; j++)
		{
			if (this->peek_at(j) < min)
			{
				min = this->peek_at(j);
				imin = j;
			}
			i++;
		}
		temp.push_front(min);
		this->pop_at(imin);
	}
	this->clear();
	*this = temp;
}


//////ДВУСВЯЗНЫЙ СПИСОК////////////


template<class T, int size>
class ForwardList
{
	MyData<T>* first = nullptr;
	MyData<T>* last = nullptr;
	int length = 0;

public:
	~ForwardList() { }//clear(); }
	void push_front(T val);
	void push_back(T val);
	void push_at(T val, int pos);
	T pop_front();
	T pop_back();
	T pop_at(int pos);
	T operator[](int pos);
	T peek_front();
	T peek_back();
	T peek_at(int pos) const;
	int getSize();
	bool isEmpty();
	bool isFull();
	void print();
	void print_reverse();
	void clear();
	ForwardList<T, size> operator+(const ForwardList<T, size>& l);
	ForwardList<T, size> operator*(const ForwardList<T, size>& l);
	void sort();
	void sort_revers();
};

template<class T, int size>
inline void ForwardList<T, size>::push_front(T val)
{
	if (length < size)
	{
		if (!length)
		{
			first = last = new MyData<T>;
			first->value = val;
		}
		else
		{
			MyData<T>* temp = new MyData<T>;
			temp->value = val;
			temp->next = first;
			first->prev = temp;
			first = temp;
		}
		length++;
	}
	else
		cout << "List overflow" << endl;
}

template<class T, int size>
inline void ForwardList<T, size>::push_back(T val)
{
	if (length < size)
	{
		if (!length)
		{
			first = last = new MyData<T>;
			first->value - val;
		}
		else
		{
			MyData<T>* temp = new MyData<T>;
			temp->value = val;
			last->next = temp;
			temp->prev = last;
			last = temp;
		}
		length++;
	}
	else
		cout << "List overflow" << endl;
}

template<class T, int size>
inline void ForwardList<T, size>::push_at(T val, int pos)
{
	if (length < size)
	{
		if (pos == 0)
			push_front(val);
		else
		{
			if (pos == length)
				push_back(val);
			else
			{
				MyData<T>* temp = new MyData<T>;
				temp->value = val;
				MyData<T>* num;
				if (pos <= length / 2)
				{
					num = first;
					for (size_t i = 0; i < pos - 1; i++)
					{
						num = num->next;

					}
				}
				else
				{
					num = last;
					for (size_t i = 0; i < length - pos; i++)
					{
						num = num->prev;
					}
				}
				temp->next = num->next;
				temp->next->prev = temp;
				num->next = temp;
				temp->prev = num;
				length++;

			}
		}
	}
	else
		cout << "List overflow" << endl;
}

template<class T, int size>
inline T ForwardList<T, size>::pop_front()
{
	if (length)
	{
		MyData<T>* temp = first;
		T val = first->value;
		if (length > 1)
			first->next->prev = nullptr;
		first = first->next;
		delete temp;
		length--;
		return val;
	}
	else
		cout << "List Empty" << endl;
}

template<class T, int size>
inline T ForwardList<T, size>::pop_back()
{
	if (length)
	{
		MyData<T>* temp = last;
		T val = last->value;
		last->prev->next = nullptr;
		last = last->prev;
		delete temp;
		length--;
		return val;
	}
	else
		cout << "List Empty" << endl;
}

template<class T, int size>
inline T ForwardList<T, size>::pop_at(int pos)
{
	if (length)
	{
		if (pos == 0)
			pop_front();
		else
		{
			if (pos == length - 1)
				pop_back();
			else
			{
				T val;
				MyData<T>* num, * temp;
				if (pos <= length / 2)
				{
					num = first;
					for (size_t i = 0; i < pos - 1; i++)
					{
						num = num->next;
					}
				}
				else
				{
					num = last;
					for (size_t i = 0; i < length - pos; i++)
					{
						num = num->prev;
					}
				}
				temp = num->next;
				val = temp->value;
				num->next = temp->next;
				temp->next->prev = num;
				delete temp;
				length--;
				return val;
			}
		}
	}
	else
		cout << "List Empty" << endl;
}

template<class T, int size>
inline T ForwardList<T, size>::operator[](int pos)
{
	if (pos >= 0 && pos < length)
	{
		MyData<T>* temp = first;
		for (size_t i = 0; i < pos; i++)
		{
			temp = temp->next;
		}
		return temp->value;
	}
	return last->value;
}

template<class T, int size>
inline T ForwardList<T, size>::peek_front()
{
	return first->value;
}

template<class T, int size>
inline T ForwardList<T, size>::peek_back()
{
	return last->value;
}

template<class T, int size>
inline T ForwardList<T, size>::peek_at(int pos) const
{
	if (pos >= 0 && pos < length)
	{
		MyData<T>* temp = first;
		for (size_t i = 0; i < pos; i++)
		{
			temp = temp->next;
		}
		return temp->value;
	}
	return last->value;
}

template<class T, int size>
inline int ForwardList<T, size>::getSize()
{
	return length;
}

template<class T, int size>
inline bool ForwardList<T, size>::isEmpty()
{
	return length == 0;
}

template<class T, int size>
inline bool ForwardList<T, size>::isFull()
{
	return length == size;
}

template<class T, int size>
inline void ForwardList<T, size>::print()
{
	if (length == 0)
	{
		cout << "List empty" << endl;
		return;
	}
	MyData<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

template<class T, int size>
inline void ForwardList<T, size>::print_reverse()
{
	if (length == 0)
	{
		cout << "List empty" << endl;
		return;
	}
	MyData<T>* temp = last;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->prev;
	}
	cout << endl;
}

template<class T, int size>
inline void ForwardList<T, size>::clear()
{
	while (length)
	{
		pop_front();
	}
	first = last = nullptr;
	cout << "List cleared!" << endl;
}

template<class T, int size>
inline ForwardList<T, size> ForwardList<T, size>::operator+(const ForwardList<T, size>& l)
{
	MyData<T>* temp = last;
	this->last->next = l.first;
	l.first->prev = temp;
	this->last = l.last;
	this->length += l.length;
	return *this;
}

template<class T, int size>
inline ForwardList<T, size> ForwardList<T, size>::operator*(const ForwardList<T, size>& l)
{
	ForwardList<T, 5> temp;
	int val = 0;
	for (size_t i = 0; i < this->length; i++)
	{
		for (size_t j = 0; j < l.length; j++)
		{
			if (this->peek_at(i) == l.peek_at(j))
			{
				val = l.peek_at(j);
				temp.push_front(val);
			}

		}
	}
	this->clear();
	*this = temp;
	return *this;
}

template<class T, int size>
inline void ForwardList<T, size>::sort()
{
	ForwardList<T, 5> temp;
	while (length)
	{
		int i = 0;
		int max = this->peek_at(0);
		int imax = 0;
		for (size_t j = i + 1; j < length; j++)
		{
			if (this->peek_at(j) > max)
			{
				max = this->peek_at(j);
				imax = j;
			}
			i++;
		}
		temp.push_front(max);
		this->pop_at(imax);
	}
	this->clear();
	*this = temp;
}

template<class T, int size>
inline void ForwardList<T, size>::sort_revers()
{
	ForwardList<T, 5> temp;
	while (length)
	{
		int i = 0;
		int min = this->peek_at(0);
		int imin = 0;
		for (size_t j = i + 1; j < length; j++)
		{
			if (this->peek_at(j) < min)
			{
				min = this->peek_at(j);
				imin = j;
			}
			i++;
		}
		temp.push_front(min);
		this->pop_at(imin);
	}
	this->clear();
	*this = temp;
}


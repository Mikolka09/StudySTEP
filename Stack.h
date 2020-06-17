#pragma once
#include"MyData.h"

template<class T, int size>
class StaticStack
{
private:
	MyData<T> data[size];
	int top = 0;//вершины у стека по началу нет
public:
	void push(T val);//добавление в стек (положить)
	T pop(); //удаление из стека (удалить)
	int getSize();//количество элементов
	T pick();//смотреть кто на вершине (последний)
	bool isEmpty();//проверка на пустоту
	bool isFull();//проверка на полноту
	void clear();//очистка стека
	void print();//печать стека

};

template<class T, int size>
inline void StaticStack<T, size>::push(T val)
{
	if (top < size)
		data[top++].value = val;
	else
		cout << "Stack overflow!" << endl;
}

template<class T, int size>
inline T StaticStack<T, size>::pop()
{
	T val = data[top].value;
	top--;
	return val;
}

template<class T, int size>
inline int StaticStack<T, size>::getSize()
{
	return top;
}

template<class T, int size>
inline T StaticStack<T, size>::pick()
{
	return data[top - 1].value;
}

template<class T, int size>
inline bool StaticStack<T, size>::isEmpty()
{
	return top == 0;;
}

template<class T, int size>
inline bool StaticStack<T, size>::isFull()
{
	return top == size;
}

template<class T, int size>
inline void StaticStack<T, size>::clear()
{
	top = 0;
}

template<class T, int size>
inline void StaticStack<T, size>::print()
{
	for (size_t i = 0; i < top; i++)
	{
		cout << data[i].value << " ";
	}
	cout << endl;
}


////////////////////////////////////////////////

template<class T, int size>
class DynamicStack
{
private:
	MyData<T> *data = nullptr;
	int top = 0;
public:
	void push(T val);//добавление в стек (положить)
	T pop(); //удаление из стека (удалить)
	int getSize();//количество элементов
	T pick();//смотреть кто на вершине (последний)
	bool isEmpty();//проверка на пустоту
	bool isFull();//проверка на полноту
	void clear();//очистка стека
	void print();//печать стека
	~DynamicStack();



};

template<class T, int size>
inline void DynamicStack<T, size>::push(T val)
{
	if (top < size)
	{
		if (top == 0)
		{
			data = new MyData<T>;
			data->value = val;
		}
		else
		{
			MyData<T> *temp = new MyData<T>;
			temp->value = val;
			temp->next = data;
			data = temp;
		}
		top++;
	}
	else
		cout << "Stack overflow!" << endl;
}

template<class T, int size>
inline T DynamicStack<T, size>::pop()
{
	T val = data->value;
	MyData<T> *temp = data;
	data = data->next;
	delete temp;
	top--;
	return val;
}

template<class T, int size>
inline void DynamicStack<T, size>::print()
{
	if (top == 0)
	{
		cout << "Stack empty!" << endl;
		return;
	}
	MyData<T> *temp = data;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;

}

template<class T, int size>
inline DynamicStack<T, size>::~DynamicStack()
{
	clear();
}

template<class T, int size>
inline T DynamicStack<T, size>::pick()
{
	return data->value;
}

template<class T, int size>
inline bool DynamicStack<T, size>::isEmpty()
{
	return top == 0;;
}

template<class T, int size>
inline bool DynamicStack<T, size>::isFull()
{
	return top == size;
}
template<class T, int size>
inline void DynamicStack<T, size>::clear()
{
	MyData<T> *temp = data;
	while (data)
	{
		data = temp->next;
		delete temp;
		temp = data;
		top--;
	}
	cout << "Stack cleared!" << endl;
}
template<class T, int size>
inline int DynamicStack<T, size>::getSize()
{
	return top;
}

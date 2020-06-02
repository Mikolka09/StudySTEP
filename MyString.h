#pragma once


class MyString
{
private:

	int len;
	char* str;
	static int count;

public:

	static int getCount();

	MyString();
	MyString(int len);
	MyString(const char* str);

	void inputString();
	void print() const;

	MyString(const MyString& obj);

	~MyString();

	char* getString() const;


};


int MyString::count = 0;

int MyString:: getCount()
{
	return count;
}

MyString::MyString() :MyString(80){}

MyString::MyString(int len)
{
	this->str = new char[len + 1];
	strcpy(this->str, str);
	this->str[0] = '\0';
	count++;
}

MyString::MyString(const char* str)
{
	this->len = strlen(str);
	this->str = new char[this->len + 1];
	strcpy(this->str, str);
	count++;
}

inline void MyString::inputString()
{
	char *str=new char[1024];
	cout << "Введите строку :";
	cin.getline(str,1024);
	delete[]this->str;
	this->len = strlen(str);
	this->str = new char[this->len + 1];
	strcpy(this->str, str);
	this->len = strlen(this->str);
}

inline void MyString::print() const
{
	cout << "Вывод строки: " << getString() << endl;
}

MyString::MyString(const MyString& obj)
{
	this->len = strlen(obj.str);
	this->str = new char[this->len + 1];
	strcpy(this->str, obj.str);
}

MyString::~MyString()
{
	delete[]str;
	count--;
}

char* MyString::getString() const
{
	return this->str;
}


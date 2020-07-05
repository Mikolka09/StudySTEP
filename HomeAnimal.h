#pragma once

#include<iostream>
#include<string>
using namespace std;

class HomeAnimal
{
protected:
	string name;   //кличка или имя
	int age;       //возраст
	string pol;    //пол(М или Ж)
	string paroda; //парода
	string pokrov; //покрытие кожи (размер или отсутствие шерсти, перья и др.)
	string color;  //цвет шерсти, перьев и др.
public:
	HomeAnimal(string n, int a, string p, string par, string pok, string c)
	{
		name = n; age = a; pol = p; paroda = par; pokrov = pok; color = c;
	}

	virtual string getName() { return " ??? "; }

	void print()
	{
		cout << "Имя: " << name << endl; cout << "Возраст: " << age << endl; cout << "Пол: " << pol << endl;
		cout << "Парода: " << paroda << endl; cout << "Покров: " << pokrov << endl; cout << "Цвет: " << color << endl;
	}

	virtual void voice() { cout << "????" << endl; }


};

class Dog :public HomeAnimal
{
private:
	string type; //тип породы (охотничья, гончая, старожевая, спасатель и др.)

public:
	Dog(string n, int a, string p, string par, string pok, string c, string t) : type(t), HomeAnimal(n, a, p, par, pok, c) {}
	void print()
	{
		HomeAnimal::print();
		cout << "Тип пароды: " << type << endl;
	}

	virtual string getName() override { return "Dog " + name; }
	virtual void voice() override { cout << "ГАВ-ГАВ" << endl; }
};



class Cat :public HomeAnimal
{
private:
	string haracter; //характер кошки (покладистая и др.)

public:
	Cat(string n, int a, string p, string par, string pok, string c, string h) : haracter(h), HomeAnimal(n, a, p, par, pok, c) {}
	void print()
	{
		HomeAnimal::print();
		cout << "Характер: " << haracter << endl;
	}

	virtual string getName() override { return "Cat " + name; }
	virtual void voice() override { cout << "МЯУ-МЯУ" << endl; }
};



class Popuga :public HomeAnimal
{
private:
	string krilo; //характер кошки (покладистая и др.)
	string klyuv; //наличие крыльев
	string golos; //говорящий или нет

public:
	Popuga(string n, int a, string p, string par, string pok, string c, string kr, string kl, string g) : krilo(kr), klyuv(kl), golos(g), HomeAnimal(n, a, p, par, pok, c) {}
	void print()
	{
		HomeAnimal::print();
		cout << "Крылья: " << krilo << endl;
		cout << "Клюв: " << klyuv << endl;
		cout << "Возможность говорить: " << golos << endl;
	}

	virtual string getName() override { return "Popuga " + name; }

	virtual void voice() override
	{
		if (golos == "ДА")
			cout << "Я ХОРОШИЙ!" << endl;
		else if (golos == "НЕТ")
			cout << "КАР-КАР" << endl;
	}
};
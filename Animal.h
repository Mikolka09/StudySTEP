#pragma once
#include<iostream>
#include<string>
using namespace std;


class Animal //final//final - закрывает дальнейшее наследование
{
protected:
	string name;
	int age;
public:
	Animal(string n, int a): name(n), age(a) {}
	virtual string getName() { return " ??? "; }
	virtual void voice() { cout << " Я немая! "; }
	//виртуальная функция вызывает функции самого нижнего подкласса 
};

class Dog : public Animal
{
public:
	Dog(string n, int a) :Animal(n, a) { voice(); }
	virtual string getName() override { return "Dog " + name; }
	virtual void voice() override { cout << "Gaw-Gaw" << endl; }

	//override - следит за правельностью переопределения метода
};


class Cat : public Animal
{
public:
	Cat(string n, int a) :Animal(n, a) {}
	virtual string getName() override { return "Cat " + name; }
	virtual void voice() override { cout << "Myau-Myau" << endl; }
};

class Medusa : public Animal
{
public:
	Medusa (string n, int a) :Animal(n, a) {}
	virtual string getName() override { return "Medusa " + name; }
	//virtual void voice() override { cout << "Я немая!" << endl; }
};
#pragma once
#include<iostream>
#include<string>
using namespace std;

class Human
{
public:
	string name;
	int age;

	Human(string n = "", int a = 0) :name(n), age(a) { cout << "HUman constr" << endl; }
	void print() const
	{
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
	}
};


class FootballPlayer :public Human
{
public:
	int goals;
	int rating;

	FootballPlayer(string n, int a, int g = 0, int r = 0) :goals(g), rating(r), Human(n, a) { cout << "FP constr" << endl; }
	FootballPlayer(int g = 0, int r = 0) :goals(g), rating(r), Human() { cout << "FP constr" << endl; }
	void print() const
	{
		Human::print();
		cout << "Goals: " << goals << endl;
		cout << "Rating: " << rating << endl;
	}
protected://нельзя использовать с наружи, только у последователя
	int getGoals() const { return goals; }
};

class TypeFP:public FootballPlayer
{
public:
	string typeFP;
	TypeFP(string n, int a, int g, int r, string tfp):typeFP(tfp), FootballPlayer(n, a, g, r)
	{ 
		cout << "TyFP constr" << endl; 
	}
	int getGoals() = delete;//закрывается с наружи, но  в нутри работает
	void print() const
	{
		cout << FootballPlayer::getGoals() << endl;
		FootballPlayer::print();
		cout << "TypeFP: " << typeFP << endl;
	}
	using Human::print;
};

class Device
{
public:
	void print() { cout << "Im Device!" << endl; }
};

class  USBDevice:public Device
{
	int id;
public:
	USBDevice(int i):id(i){}
	int getID() { return id; }
};

class NetworkDevice: public Device
{
	int id;
public:
	NetworkDevice(int i) :id(i) {}
	int getID() { return id; }
};

class WiFiAdapter :public USBDevice, public NetworkDevice
{
public:
	WiFiAdapter(int idUSB, int idND):USBDevice(idUSB),NetworkDevice(idND){}
	
};


/*WiFiAdapter wf(121, 345);
cout << wf.USBDevice::getID() << endl;
wf.USBDevice::Device::print();*/

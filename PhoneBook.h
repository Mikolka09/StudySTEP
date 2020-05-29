#pragma once

#include<iostream>

using namespace std;

class PhoneBook
{
private:
	class Abonent
	{
	private:
		char* FIO;//ФИО
		int phoneH;//домашний телефон
		int phoneW;//рабочий телефон
		int phoneM;//мобильный телефон
	public:
		Abonent() {};
		Abonent(char *FIO, int pH, int pW, int pM)
		{
			int lenFIO = strlen(FIO);
			this->FIO = new char[lenFIO + 1];
			strcpy(this->FIO, FIO);
			this->phoneH = pH;
			this->phoneW = pW;
			this->phoneM = pM;
		}

		char setFIO(char* FIO) { this->FIO = FIO; };
		int setpH(int pH) { this->phoneH = pH; };
		int setpW(int pW) { this->phoneW = pW; };
		int setpM(int pM) { this->phoneM = pM; };

		void print()
		{
			cout << this->FIO << "  " << this->phoneH << "  " << this->phoneW << "  " << this->phoneM << endl;
		}

		~Abonent()
		{
			delete[]this->FIO;
		}
	};
	PhoneBook *phBook=nullptr;//телефонная книга(массив абонентов)
	Abonent abon;//абонент
	int sizeAb = 0;//количесвто абонентов

public:
	PhoneBook();
	void addPhoneBook();
	void addElemArray(PhoneBook*& p, int& size, Abonent elem);
	void print();
	~PhoneBook();



};

PhoneBook::PhoneBook()
{
}

void PhoneBook::addElemArray(PhoneBook*& p, int& size, Abonent elem)
{
	PhoneBook* t = new PhoneBook[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		t[i] = p[i];
	}
	t[size] = elem;
	delete[]p;
	p = t;
	size++;
}


void PhoneBook::addPhoneBook()
{
	Abonent abon;
	cout << "Создание абонента в телефонной книге: " << endl;
	char buff[80];
	cout << "Введите ФИО: ";
	cin.getline(buff, 80);
	cin.ignore();
	abon.setFIO(buff);
	int pH, pW, pM;
	cout << "Введите домашний номер: ";
	cin >> pH;
	abon.setpH(pH);
	cout << "Введите рабочий номер: ";
	cin >> pW;
	abon.setpW(pW);
	cout << "Введите мобильный номер: ";
	cin >> pM;
	abon.setpM(pM);
	addElemArray(phBook, this->sizeAb, abon);
	

}

inline void PhoneBook::print()
{
	for (size_t i = 0; i < sizeAb; i++)
	{
		phBook[i].print();
	}
	cout << endl;
}


PhoneBook::~PhoneBook()
{
	delete[]this->phBook;
}

#pragma once

#include<iostream>

using namespace std;

class PhoneBook
{
private:
	class Abonent
	{
	private:
		char* FIO = { 0 };//���
		int phoneH = 0;//�������� �������
		int phoneW = 0;//������� �������
		int phoneM = 0;//��������� �������
	public:
		Abonent() {};

		Abonent(char* f, int pH, int pW, int pM)
		{
			/*int lenFIO = strlen(fio);
			FIO = new char[lenFIO + 1];
			FIO[lenFIO - 1] = '\0';
			strcpy(FIO, fio);*/
			FIO = f;
			phoneH = pH;
			phoneW = pW;
			phoneM = pM;
		}

		void setFIO(char* fio) { FIO = fio; };
		void setpH(int pH) { phoneH = pH; };
		void setpW(int pW) { phoneW = pW; };
		void setpM(int pM) { phoneM = pM; };

		void print()
		{
			cout << FIO << "  " << phoneH << "  " << phoneW << "  " << phoneM << endl;
		}

		~Abonent()
		{

		}
	};

	Abonent* phBook;//���������� �����(������ ���������)
	int sizeAb = 0;//���������� ���������

public:
	//PhoneBook();
	void addPhoneBook();
	void addAbonent(Abonent*& p, int& size, Abonent abon);
	void print();
	~PhoneBook();



};


void PhoneBook::addAbonent(Abonent*& p, int& size, Abonent abon)
{
	Abonent* t = new Abonent[size + 1];
	memcpy(t, p, size * sizeof(int));
	t[size] = abon;
	delete[]p;
	p = t;
	size++;
}


void PhoneBook::addPhoneBook()
{
	Abonent abon;
	cout << "�������� �������� � ���������� �����: " << endl;
	char buff[80];
	cout << "������� ���: ";
	cin.getline(buff, 80);
	int lenFIO = strlen(buff);
	char *f = new char[lenFIO + 1];
	f[lenFIO - 1] = '\0';
	strcpy(f, buff);
	abon.setFIO(f);
	int pH, pW, pM;
	cout << "������� �������� �����: ";
	cin >> pH;
	abon.setpH(pH);
	cout << "������� ������� �����: ";
	cin >> pW;
	abon.setpW(pW);
	cout << "������� ��������� �����: ";
	cin >> pM;
	abon.setpM(pM);
	addAbonent(phBook, sizeAb, abon);
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
	delete[]phBook;
}

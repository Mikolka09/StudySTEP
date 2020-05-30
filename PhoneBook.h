#pragma once

#include<iostream>
#include<iomanip>
#include<string.h>

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

		Abonent(char* f, int pH, int pW, int pM)
		{
			FIO = f;
			phoneH = pH;
			phoneW = pW;
			phoneM = pM;
		}

		char* getFIO() { return FIO; };

		void setFIO(char* fio) { FIO = fio; };
		void setpH(int pH) { phoneH = pH; };
		void setpW(int pW) { phoneW = pW; };
		void setpM(int pM) { phoneM = pM; };

		void print()
		{
			cout << setw(12) << FIO << setw(12) << phoneH << setw(12) << phoneW
				<< setw(12) << phoneM << endl;
		}

		~Abonent()
		{

		}
	};

	Abonent* phBook;//телефонная книга(массив абонентов)
	int sizeAb = 0;//количесвто абонентов

public:

	void menuPhBook();
	void shapkaBook();
	void addPhoneBook();
	void addAbonent(Abonent*& p, int& size, Abonent abon);
	void searchFIO();
	void print();

	~PhoneBook();
};


void PhoneBook::addAbonent(Abonent*& p, int& size, Abonent abon)
{
	Abonent* t = new Abonent[size + 1];
	for (size_t i = 0; i < size; i++)
	{
		t[i] = p[i];
	}
	t[size] = abon;
	delete[]p;
	p = t;
	size++;
}

inline void PhoneBook::searchFIO()
{
	system("cls");
	cout << endl;
	cout << "\tПоиск абонента по ФИО: " << endl;
	cout << "\t----------------------" << endl;
	cout << endl;
	cin.ignore();
	char buff[80];
	cout << "\tВведите ФИО для поиска: ";
	cin.getline(buff, 80);
	if (islower(buff[0]))
		buff[0] = char(buff[0]) - 32;
	int lenFIO = strlen(buff);
	char* src = new char[lenFIO + 1];
	src[lenFIO - 1] = '\0';
	strcpy(src, buff);
	string S(52, '-');
	bool flag = true;
	shapkaBook();
	for (size_t i = 0; i < sizeAb; i++)
	{
		if (strcmp(phBook[i].getFIO(), src) == 0)
		{
			cout << setw(4) << i + 1;
			phBook[i].print();
			flag = false;
		}
	}
	cout << S << endl;
	if (flag)
	{
		system("cls");
		cout << "\n\n\n" << endl;
		cout << "\tТакого абонента нет. Попробуйте еще раз!" << endl;
	}
	cout << endl;
	system("pause");
}


inline void PhoneBook::menuPhBook()
{
	do
	{
		system("cls");
		cout << endl;
		cout << "\t\tМЕНЮ ТЕЛЕФОННОЙ КНИГИ:" << endl;
		cout << "\t\t----------------------\n" << endl;
		cout << "\t1.Добавить нового абонента\n"
			<< "\t2.Удаление абонента\n"
			<< "\t3.Искать абонента по ФИО\n"
			<< "\t4.Показать всех абонентов\n"
			<< "\t5.Сохранить телефонную книгу в файл\n"
			<< "\t6.Выход\n" << endl;
		cout << "   Выберите вариант: ";
		int var;
		cin >> var;
		if (var < 1 || var > 6)
		{
			system("cls");
			cout << "\n\n\n" << endl;
			cout << "\tОШИБКА! Такого варианта нет. Поробуйте еще раз!" << endl;
			cout << endl;
			system("pause");
		}
		switch (var)
		{
		case 1:
			addPhoneBook();
			break;
		case 2:

			break;
		case 3:
			searchFIO();
			break;
		case 4:
			print();
			break;
		case 5:

			break;
		case 6:
			exit(0);
			break;
		}
	} while (true);

}

inline void PhoneBook::shapkaBook()
{
	string S(52, '-');
	cout << endl << endl;
	cout << "\t\tТЕЛЕФОННАЯ КНИГА" << endl << endl;
	cout << S << endl;
	cout << setw(4) << " Номер" << setw(10) << "ФИО" << setw(12) << "Домашний" << setw(12) << "Рабочий"
		<< setw(12) << "Мобильный" << endl;
	cout << S;
	cout << endl;
}

void PhoneBook::addPhoneBook()
{
	system("cls");
	cout << endl;
	cout << "\tДобавление нового абонента: " << endl;
	cout << "\t---------------------------" << endl;
	cout << endl;
	Abonent abon;
	cin.ignore();
	char buff[80];
	cout << "\tВведите ФИО: ";
	cin.getline(buff, 80);
	int lenFIO = strlen(buff);
	char* f = new char[lenFIO + 1];
	f[lenFIO - 1] = '\0';
	strcpy(f, buff);
	abon.setFIO(f);
	int pH, pW, pM;
	cout << "\tВведите домашний номер: ";
	cin >> pH;
	abon.setpH(pH);
	cout << "\tВведите рабочий номер: ";
	cin >> pW;
	abon.setpW(pW);
	cout << "\tВведите мобильный номер: ";
	cin >> pM;
	abon.setpM(pM);
	addAbonent(phBook, sizeAb, abon);
	cout << endl;
	cout << "\t-----------------" << endl;
	cout << "\tАбонент добавлен!" << endl;
	cout << endl;
	system("pause");
}

inline void PhoneBook::print()
{
	system("cls");
	string S(52, '-');
	shapkaBook();
	for (size_t i = 0; i < sizeAb; i++)
	{
		cout << setw(4) << i + 1;
		phBook[i].print();
	}
	cout << S;
	cout << endl << endl;
	system("pause");
}


PhoneBook::~PhoneBook()
{
	delete[]phBook;
}

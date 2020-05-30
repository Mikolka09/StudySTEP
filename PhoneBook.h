#pragma once

#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
#include<Windows.h>

using namespace std;

class PhoneBook
{
private:
	class Abonent
	{
	private:

		int phoneH;//домашний телефон
		int phoneW;//рабочий телефон
		int phoneM;//мобильный телефон
	public:

		char* FIO;//ФИО

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

		template<class T>
		void print(T&stream)
		{
			stream << setw(12) << FIO << " |" << setw(12) << phoneH << " |" << setw(12) << phoneW << " |"
				<< setw(12) << phoneM << " |" << endl;
		}

		~Abonent()
		{
			
		}
	};

	
	int sizeAb = 0;//количесвто абонентов

public:

	Abonent* phBook;//телефонная книга(массив абонентов)
	
	void menuPhBook();

	template<class T>
	void shapkaBook(T& stream);

	void loadPhBook();
	void sortPhBook(Abonent *&phB, int size);
	int findFIO(Abonent* phB, int size, char* fio);
	void addAbonetBook();
	void dellAbonetBook();
	void addAbonent(Abonent*& p, int& size, Abonent abon);
	void dellAbonent(Abonent*& p, int& size, int pos);
	void searchFIO();
	void savePhBook();
	void savePhBookFile();

	template<class T>
	void print(T& stream);

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

inline void PhoneBook::dellAbonent(Abonent*& p, int& size, int pos)
{
	Abonent* t = new Abonent[size - 1];
	for (size_t i = 0; i < pos; i++)
	{
		t[i] = p[i];
	}
	for (size_t i = pos + 1 ; i < size; i++)
	{
		t[i - 1] = p[i];
	}
	delete[]p;
	p = t;
	size--;
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
	strcpy(src, buff);
	string S(64, '-');
	bool flag = true;
	shapkaBook(cout);
	if (findFIO(phBook, sizeAb, src) != -1)
	{
		cout << setw(4) << findFIO(phBook, sizeAb, src) + 1;
		phBook[findFIO(phBook, sizeAb, src)].print(cout);
		cout << S << endl;
	}
	if (findFIO(phBook, sizeAb, src) == -1)
	{
		system("cls");
		cout << "\n\n\n" << endl;
		cout << "\tТакого абонента нет. Попробуйте еще раз!" << endl;
	}
	cout << endl;
	system("pause");
}

inline void PhoneBook::savePhBook()
{
	ofstream fout("PhBook.bin", ios::binary | ios::out);
	if (fout.is_open())
	{
		fout.write((char*)&sizeAb, sizeof(sizeAb));
		for (size_t i = 0; i < sizeAb; i++)
		{
			fout.write((char*)&phBook[i], sizeof(Abonent));
			int lenFIO = strlen(phBook[i].FIO) + 1;
			fout.write((char*)&lenFIO, sizeof(int));
			fout.write((char*)phBook[i].FIO, lenFIO);
		}
	}
	fout.close();
}


inline void PhoneBook::menuPhBook()
{
	loadPhBook();
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
			addAbonetBook();
			break;
		case 2:
			dellAbonetBook();
			break;
		case 3:
			searchFIO();
			break;
		case 4:
			print(cout);
			system("pause");
			break;
		case 5:
			savePhBookFile();
			break;
		case 6:
			exit(0);
			break;
		}
	} while (true);

}

template<class T>
inline void PhoneBook::shapkaBook(T&stream)
{
	string S(64, '-');
	stream << endl << endl;
	stream << "\t\t\tТЕЛЕФОННАЯ КНИГА" << endl << endl;
	stream << S << endl;
	stream << setw(4) << " Номер" <<" |" << setw(12) << "ФИО" << " |" << setw(12) << "Домашний" << " |"
		<< setw(12) << "Рабочий" << " |" << setw(12) << "Мобильный" << " |" << endl;
	stream << S;
	stream << endl;
}

inline void PhoneBook::loadPhBook()
{
	ifstream fin("PhBook.bin", ios::binary | ios::in);
	if (fin.is_open())
	{
		fin.read((char*)&sizeAb, sizeof(sizeAb));
		phBook = new Abonent[sizeAb];
		PhoneBook b;
		for (size_t i = 0; i < sizeAb; i++)
		{
			fin.read((char*)&phBook[i], sizeof(Abonent));
			int lenFIO;
			fin.read((char*)&lenFIO, sizeof(int));
			phBook[i].FIO = new char[lenFIO + 1];
			fin.read((char*)phBook[i].FIO, lenFIO);
		}
		
		
	}
	fin.close();
}

inline void PhoneBook::sortPhBook(Abonent *&phB, int size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		int max = i;
		for (size_t j = i + 1; j < size; j++)
		{
			if (strcmp(phB[j].FIO, phB[max].FIO) == -1)
				max = j;
				
		}
		swap(phB[i], phB[max]);
	}
}

inline int PhoneBook::findFIO(Abonent* phB, int size, char* fio)
{
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(phBook[i].getFIO(), fio) == 0)
			return i;
	}
	return -1;
}

void PhoneBook::addAbonetBook()
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
	savePhBook();
}

inline void PhoneBook::dellAbonetBook()
{
	system("cls");
	cout << endl;
	cout << "\tУдаление абонента: " << endl;
	cout << "\t------------------" << endl;
	cout << endl;
	cin.ignore();
	char buff[80];
	cout << "\tВведите ФИО абонента: ";
	cin.getline(buff, 80);
	if (islower(buff[0]))
		buff[0] = char(buff[0]) - 32;
	int lenFIO = strlen(buff);
	char* src = new char[lenFIO + 1];
	src[lenFIO - 1] = '\0';
	strcpy(src, buff);
	int pos = findFIO(phBook, sizeAb, src);
	dellAbonent(phBook, sizeAb, pos);
	cout << endl;
	cout << "\t---------------" << endl;
	cout << "\tАбонент удален!" << endl;
	cout << endl;
	system("pause");
	savePhBook();
}

inline void PhoneBook::savePhBookFile()
{
	ofstream fout("PhoneBook.txt", ios::out);
	if (fout.is_open())
	{
		print(fout);
	}
	fout.close();
	system("cls");
	cout << "\n\n\n\n";
	cout << setw(40) << "ТЕЛЕФОННАЯ КНИГА СОХРАНЕНА В ФАЙЛ!" << endl;
	Sleep(2000);
}

template<class T>
inline void PhoneBook::print(T&stream)
{
	system("cls");
	sortPhBook(phBook, sizeAb);
	string S(64, '-');
	shapkaBook(stream);
	for (size_t i = 0; i < sizeAb; i++)
	{
		stream << setw(4) << i + 1 <<"   |";
		phBook[i].print(stream);
	}
	stream << S;
	stream << endl << endl;
}


PhoneBook::~PhoneBook()
{
	delete[]phBook;
}

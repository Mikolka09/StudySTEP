#pragma once

#include<iostream>
#include<iomanip>
#include<string.h>
#include<fstream>
#include<Windows.h>

using namespace std;

class Abonent
{
private:

	char* firma = nullptr;       //название фирмы
	char* FIO = nullptr;         //ФИО
	char* phone = nullptr;       //мобильный телефон
	char* address = nullptr;     //адрес
	char* occupation = nullptr;  //род деятельности
public:

	Abonent() {}

	Abonent(char* f, char* fio, char* p, char* a, char* o)
	{
		firma = f;
		FIO = fio;
		phone = p;
		address = a;
		occupation = o;
	}

	Abonent(const Abonent& obj)
	{
		int lenFIO = strlen(obj.FIO);
		FIO = new char[lenFIO + 1];
		strcpy(FIO, obj.FIO);
		int lenF = strlen(obj.firma);
		firma = new char[lenF + 1];
		strcpy(firma, obj.firma);
		int lenP = strlen(obj.phone);
		phone = new char[lenP + 1];
		strcpy(phone, obj.phone);
		int lenA = strlen(obj.address);
		address = new char[lenA + 1];
		strcpy(address, obj.address);
		int lenO = strlen(obj.occupation);
		occupation = new char[lenO + 1];
		strcpy(occupation, obj.occupation);
	}

	Abonent& operator=(const Abonent& obj)
	{
		int lenFIO = strlen(obj.FIO);
		FIO = new char[lenFIO + 1];
		strcpy(FIO, obj.FIO);
		int lenF = strlen(obj.firma);
		firma = new char[lenF + 1];
		strcpy(firma, obj.firma);
		int lenP = strlen(obj.phone);
		phone = new char[lenP + 1];
		strcpy(phone, obj.phone);
		int lenA = strlen(obj.address);
		address = new char[lenA + 1];
		strcpy(address, obj.address);
		int lenO = strlen(obj.occupation);
		occupation = new char[lenO + 1];
		strcpy(occupation, obj.occupation);
		return *this;
	}

	char* getFIO() { return FIO; };
	char* getFirma() { return firma; };
	char* getPhone() { return phone; };
	char* getAddress() { return address; };
	char* getOccupation() { return occupation; };

	void setFIO(char* fio) { FIO = fio; };
	void setFirma(char* f) { firma = f; };
	void setPhone(char* p) { phone = p; };
	void setAddress(char* a) { address = a; };
	void setOccupation(char* o) { occupation = o; };

	template<class T>
	void print(T& stream)
	{
		stream << setw(12) << FIO << " |" << setw(12) << phone << " |" << setw(12) << firma << " |"
			<< setw(12) << address << " |" << setw(16) << occupation << " |" << endl;
	}

	~Abonent()
	{
		delete[]FIO;
		delete[]firma;
		delete[]phone;
		delete[]address;
		delete[]occupation;
	}
};

class PhoneBook
{
private:

	Abonent* phBook;    //телефонная книга(массив абонентов)
	int sizeAb = 0;     //количесвто абонентов

public:

	PhoneBook() :PhoneBook(0) {};
	PhoneBook(int size)
	{
		phBook = new Abonent[size];
		this->sizeAb = size;
	}

	PhoneBook(const PhoneBook& b)
	{
		this->sizeAb = b.sizeAb;
		this->phBook = new Abonent[b.sizeAb];
		memcpy(this->phBook, b.phBook, b.sizeAb * sizeof(Abonent));
	}

	void menuPhBook();

	template<class T>
	void shapkaBook(T& stream);

	void loadPhBook();
	void sortPhBook(Abonent*& phB, int size);
	int findFIO(Abonent* phB, int size, char* fio);
	int findOccupation(Abonent* phB, int size, char* o);
	int findFirma(Abonent* phB, int size, char* f);
	int findPhone(Abonent* phB, int size, char* p);
	void addAbonetBook();
	void dellAbonetBook();
	void addAbonent(Abonent*& p, int& size, Abonent abon);
	void dellAbonent(Abonent*& p, int& size, int pos);
	void search();
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
	for (size_t i = pos + 1; i < size; i++)
	{
		t[i - 1] = p[i];
	}
	delete[]p;
	p = t;
	size--;
}

inline void PhoneBook::search()
{
	system("cls");
	cout << endl;
	cout << "\tПоиск абонента: " << endl;
	cout << "\t---------------" << endl << endl;
	cout << "1. Поиск по ФИО\n" << "2. Поиск по Фирме\n" << "3. Поиск по Номеру\n" << "4. Поиск по Деятельности\n" << "5. Возврат в Меню\n" << endl;
	cout << "   Выберите вариант: ";
	int var1;
	string S(82, '-');
	cin >> var1;
	switch (var1)
	{
	case 1:
	{
		system("cls");
		cout << endl;
		cout << "\tПоиск абонента по ФИО: " << endl;
		cout << "\t----------------------" << endl << endl;
		cin.ignore();
		cout << "\tВведите ФИО для поиска: ";
		char buff[80];
		cin.getline(buff, 80);
		if (islower(buff[0]))
			buff[0] = char(buff[0]) - 32;
		int len = strlen(buff);
		char* src = new char[len + 1];
		strcpy(src, buff);
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
		break;
	}
	case 2:
	{
		system("cls");
		cout << endl;
		cout << "\tПоиск абонента по Фирме: " << endl;
		cout << "\t----------------------" << endl << endl;
		cin.ignore();
		cout << "\tВведите название Фирмы для поиска: ";
		char buff[80];
		cin.getline(buff, 80);
		if (islower(buff[0]))
			buff[0] = char(buff[0]) - 32;
		int len = strlen(buff);
		char* src = new char[len + 1];
		strcpy(src, buff);
		shapkaBook(cout);
		if (findFirma(phBook, sizeAb, src) != -1)
		{
			cout << setw(4) << findFirma(phBook, sizeAb, src) + 1;
			phBook[findFirma(phBook, sizeAb, src)].print(cout);
			cout << S << endl;
		}
		if (findFirma(phBook, sizeAb, src) == -1)
		{
			system("cls");
			cout << "\n\n\n" << endl;
			cout << "\tТакого абонента нет. Попробуйте еще раз!" << endl;
		}
		cout << endl;
		system("pause");
		break;
	}
	case 3:
	{
		system("cls");
		cout << endl;
		cout << "\tПоиск абонента по Номеру: " << endl;
		cout << "\t----------------------" << endl << endl;
		cin.ignore();
		cout << "\tВведите Номер для поиска: ";
		char buff[80];
		cin.getline(buff, 80);
		if (islower(buff[0]))
			buff[0] = char(buff[0]) - 32;
		int len = strlen(buff);
		char* src = new char[len + 1];
		strcpy(src, buff);
		shapkaBook(cout);
		if (findPhone(phBook, sizeAb, src) != -1)
		{
			cout << setw(4) << findPhone(phBook, sizeAb, src) + 1;
			phBook[findPhone(phBook, sizeAb, src)].print(cout);
			cout << S << endl;
		}
		if (findPhone(phBook, sizeAb, src) == -1)
		{
			system("cls");
			cout << "\n\n\n" << endl;
			cout << "\tТакого абонента нет. Попробуйте еще раз!" << endl;
		}
		cout << endl;
		system("pause");
		break;
	}
	case 4:
	{
		system("cls");
		cout << endl;
		cout << "\tПоиск абонента по Деятельности: " << endl;
		cout << "\t----------------------" << endl << endl;
		cin.ignore();
		cout << "\tВведите род Деятельности для поиска: ";
		char buff[80];
		cin.getline(buff, 80);
		if (islower(buff[0]))
			buff[0] = char(buff[0]) - 32;
		int len = strlen(buff);
		char* src = new char[len + 1];
		strcpy(src, buff);
		shapkaBook(cout);
		if (findOccupation(phBook, sizeAb, src) != -1)
		{
			cout << setw(4) << findOccupation(phBook, sizeAb, src) + 1;
			phBook[findOccupation(phBook, sizeAb, src)].print(cout);
			cout << S << endl;
		}
		if (findOccupation(phBook, sizeAb, src) == -1)
		{
			system("cls");
			cout << "\n\n\n" << endl;
			cout << "\tТакого абонента нет. Попробуйте еще раз!" << endl;
		}
		cout << endl;
		system("pause");
		break;
	}
	case 5:
		menuPhBook();
		break;
	default:
		break;
	}

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
			int lenFIO = strlen(phBook[i].getFIO()) + 1;
			fout.write((char*)&lenFIO, sizeof(int));
			fout.write((char*)phBook[i].getFIO(), lenFIO);
			int lenF = strlen(phBook[i].getFirma()) + 1;
			fout.write((char*)&lenF, sizeof(int));
			fout.write((char*)phBook[i].getFirma(), lenF);
			int lenA = strlen(phBook[i].getAddress()) + 1;
			fout.write((char*)&lenA, sizeof(int));
			fout.write((char*)phBook[i].getAddress(), lenA);
			int lenP = strlen(phBook[i].getPhone()) + 1;
			fout.write((char*)&lenP, sizeof(int));
			fout.write((char*)phBook[i].getPhone(), lenP);
			int lenO = strlen(phBook[i].getOccupation()) + 1;
			fout.write((char*)&lenO, sizeof(int));
			fout.write((char*)phBook[i].getOccupation(), lenO);
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
			<< "\t3.Искать абонента\n"
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
			search();
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
inline void PhoneBook::shapkaBook(T& stream)
{
	string S(82, '-');
	stream << endl << endl;
	stream << "\t\t\tТЕЛЕФОННАЯ КНИГА" << endl << endl;
	stream << S << endl;
	stream << setw(4) << " Номер" << " |" << setw(12) << " ФИО" << " |" << setw(12) << "Телефон" << " |" << setw(12) << "Фирма" << " |"
		<< setw(12) << "Адрес" << " |" << setw(16) << "Деятельность" << " |" << endl;
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
		for (size_t i = 0; i < sizeAb; i++)
		{
			fin.read((char*)&phBook[i], sizeof(Abonent));
			int lenFIO;
			fin.read((char*)&lenFIO, sizeof(int));
			char* buff = new char[lenFIO + 1];
			fin.read((char*)buff, lenFIO);
			phBook[i].setFIO(buff);
			int lenF;
			fin.read((char*)&lenF, sizeof(int));
			char* buff2 = new char[lenF + 1];
			fin.read((char*)buff2, lenF);
			phBook[i].setFirma(buff2);
			int lenA;
			fin.read((char*)&lenA, sizeof(int));
			char* buff3 = new char[lenA + 1];
			fin.read((char*)buff3, lenA);
			phBook[i].setAddress(buff3);
			int lenP;
			fin.read((char*)&lenP, sizeof(int));
			char* buff4 = new char[lenP + 1];
			fin.read((char*)buff4, lenP);
			phBook[i].setPhone(buff4);
			int lenO;
			fin.read((char*)&lenO, sizeof(int));
			char* buff5 = new char[lenO + 1];
			fin.read((char*)buff5, lenO);
			phBook[i].setOccupation(buff5);
		}
	}
	fin.close();
}

inline void PhoneBook::sortPhBook(Abonent*& phB, int size)
{
	for (size_t i = 0; i < size - 1; i++)
	{
		int max = i;
		for (size_t j = i + 1; j < size; j++)
		{
			if (strcmp(phB[j].getFIO(), phB[max].getFIO()) == -1)
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

inline int PhoneBook::findPhone(Abonent* phB, int size, char* p)
{
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(phBook[i].getPhone(), p) == 0)
			return i;
	}
	return -1;
}

inline int PhoneBook::findOccupation(Abonent* phB, int size, char* o)
{
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(phBook[i].getOccupation(), o) == 0)
			return i;
	}
	return -1;
}

inline int PhoneBook::findFirma(Abonent* phB, int size, char* f)
{
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(phBook[i].getFirma(), f) == 0)
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
	char buff1[80], buff2[80], buff3[80], buff4[80], buff5[80];
	cout << "\tВведите ФИО: ";
	cin.getline(buff1, 80);
	int lenFIO = strlen(buff1);
	char* f = new char[lenFIO + 1];
	f[lenFIO - 1] = '\0';
	strcpy(f, buff1);
	abon.setFIO(f);
	cout << "\tВведите название Фирмы: ";
	cin.getline(buff2, 80);
	int lenF = strlen(buff2);
	char* fr = new char[lenF + 1];
	fr[lenF - 1] = '\0';
	strcpy(fr, buff2);
	abon.setFirma(fr);
	cout << "\tВведите Адрес: ";
	cin.getline(buff3, 80);
	int lenA = strlen(buff3);
	char* a = new char[lenA + 1];
	a[lenA - 1] = '\0';
	strcpy(a, buff3);
	abon.setAddress(a);
	cout << "\tВведите мобильный номер: ";
	cin.getline(buff4, 80);
	int lenP = strlen(buff4);
	char* p = new char[lenP + 1];
	p[lenP - 1] = '\0';
	strcpy(p, buff4);
	abon.setPhone(p);
	cout << "\tВведите род Деятельности: ";
	cin.getline(buff5, 80);
	int lenO = strlen(buff5);
	char* o = new char[lenO + 1];
	o[lenO - 1] = '\0';
	strcpy(o, buff5);
	abon.setOccupation(o);
	addAbonent(phBook, sizeAb, abon);
	cout << endl;
	cout << "\t-----------------" << endl;
	cout << "\tАбонент добавлен!" << endl;
	cout << endl;
	Sleep(3000);
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
inline void PhoneBook::print(T& stream)
{
	system("cls");
	sortPhBook(phBook, sizeAb);
	string S(82, '-');
	shapkaBook(stream);
	for (size_t i = 0; i < sizeAb; i++)
	{
		stream << setw(4) << i + 1 << "   |";
		phBook[i].print(stream);
	}
	stream << S;
	stream << endl << endl;
}


PhoneBook::~PhoneBook()
{
	delete[]phBook;
}

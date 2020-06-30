#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Drob.h"
#include"PhoneBook.h"
#include"MyString.h"
#include"Time.h"
#include"Point3D.h"
#include"Vector3D.h"
//#include"Array2D.h"
#include"MyData.h"
#include"Queue.h"
#include"Stack.h"
#include <string>



using namespace std;



int main()
{
	setlocale(0, "");
	srand(time(NULL));

	//МОДЕЛЬ "ОСТАНОВКА МАРШРУТНЫХ ТАКСИ"

	//Ввод данных
	Queue<int, 20> och_people;//простая очередь людей на остановке
	RingQueue<int, 20> marsh_bus;//циклическая очередь маршруток
	int max_mest(30);//максимальное кол-во мест в маршрутке
	int time_people;
	cout << "Введите среднее время между появлениями пассажиров на остановке в мин.: ";
	cin >> time_people;
	int time_bus;
	cout << "Введите среднее время между появлениями маршруток на остановке в мин.: ";
	cin >> time_bus;
	int type_ost;
	cout << "Введите тип остановки (конечная - 0 или нет - 1): ";
	cin >> type_ost;
	int n_people;
	cout << "Введите требуемое количество одновременно находящихся людей на остановке: ";
	cin >> n_people;
	int n_mest;//количесвто свободных мест в маршрутке
	n_mest = rand() % 9 + 1;

	//Нужно определить
	int tSr_people = 0;//среднее время пребывания человека на остановке

	//Решение поставленной модели
	int i = 60 * 24;//кол-во минут в сутках
	while (i)
	{
		if (i % time_people == 0)
		{
			och_people.push(1);
		}
		if (i % time_bus == 0 && type_ost == 1)
		{
			while (n_mest)
			{
				och_people.pop();
				if (och_people.ifEmpty())
					break;
			}
		}
		if (i % time_bus == 0 && type_ost == 0)
		{
			while (max_mest)
			{
				och_people.pop();
				if (och_people.ifEmpty())
					break;
			}
		}
		if (och_people.getSize() > n_people)
		{
			marsh_bus.push(1);
			time_bus--;
		}
		i--;
	}
	cout << endl;
	cout <<"Среднее время пребывания человека на остановке: ";
	cout << och_people.getSize();
	cout << " мин." << endl;


























}
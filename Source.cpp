#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Drob.h"
#include"PhoneBook.h"
//#include"MyString.h"
#include"Time.h"
#include"Point3D.h"
#include"Vector3D.h"
//#include"Array2D.h"
#include"MyData.h"
#include"Queue.h"
#include"Stack.h"
#include <string>
#include"HomeAnimal.h"
#include <vector>
#include <algorithm>
#include <list>
#include <map>
#include <string>


using namespace std;



int main()
{
	setlocale(0, "");
	srand(time(0));

#pragma region Marshrut

	//МОДЕЛЬ "ОСТАНОВКА МАРШРУТНЫХ ТАКСИ"

	////Ввод данных
	//Queue<int, 100> och_people;//простая очередь людей на остановке
	//RingQueue<int, 100> marsh_bus;//циклическая очередь маршруток
	//int max_mest(30);//максимальное кол-во мест в маршрутке
	//int time_people;
	//cout << "\t\tМОДЕЛЬ 'ОСТАНОВКА МАРШРУТНЫХ ТАКСИ'" << endl;
	//cout << "\t\t-----------------------------------" << endl << endl;
	//cout << "  Введите среднее время между появлениями пассажиров на остановке в мин.: ";
	//cin >> time_people;
	//int time_bus;
	//cout << endl;
	//cout << "  Введите среднее время между появлениями маршруток на остановке в мин.: ";
	//cin >> time_bus;
	//int type_ost;
	//cout << endl;
	//cout << "  Введите тип остановки (конечная - 0 или нет - 1): ";
	//cin >> type_ost;
	//int n_people;
	//cout << endl;
	//cout << "  Введите требуемое количество одновременно находящихся людей на остановке: ";
	//cin >> n_people;
	//cout << endl;
	//int n_mest;//количесвто свободных мест в маршрутке

	////Нужно определить
	//int tSr_people = 0;//среднее время пребывания человека на остановке

	////Решение поставленной модели
	//int time_sut = 60 * 24;//кол-во минут в сутках
	//int count_p = 0;//кол-во перевезенных с одной остановки людей
	//while (time_sut)
	//{
	//	if (time_sut % time_people == 0)
	//	{
	//		och_people.push(1);
	//	}
	//	if (time_bus != 0 && time_sut % time_bus == 0 && type_ost == 1)
	//	{
	//		marsh_bus.push(1);
	//		n_mest = rand() % 9 + 1;
	//		while (n_mest != 0)
	//		{
	//			if (och_people.ifEmpty())
	//				break;
	//			else
	//			{
	//				och_people.pop();
	//				count_p++;
	//			}
	//			n_mest--;
	//		}
	//	}
	//	else if (time_bus != 0 && time_sut % time_bus == 0 && type_ost == 0)
	//	{
	//		while (max_mest != 0)
	//		{
	//			if (och_people.ifEmpty())
	//				break;
	//			else
	//			{
	//				och_people.pop();
	//				count_p++;
	//			}
	//			max_mest--;
	//		}
	//	}
	//	if (och_people.getSize() > n_people)
	//	{
	//		time_bus--;
	//	}
	//	time_sut--;
	//}
	//cout << endl;
	//cout << "\t\t\tРАСЧЕТНЫЕ ПОКАЗАТЕЛИ" << endl;
	//cout << "\t\t\t--------------------" << endl << endl;
	//cout << "  Количество автобусов забравших пассажиров за сутки с одной остановки: " << marsh_bus.getSize() << endl << endl;
	//cout << "  Количество перевезенных людей за сутки: " << count_p << endl << endl;
	//cout << "  Достаточеый интервал между приходами маршруток: " << time_bus << " мин." << endl;
	//time_sut = 60 * 24;
	//tSr_people = time_sut / count_p;
	//cout << endl;
	//cout << "  Среднее время пребывания человека на остановке: " << tSr_people << " мин." << endl << endl;

#pragma endregion

	






































}
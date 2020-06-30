#pragma once
#include<iostream>
#include"MyData.h"
#include"Queue.h"
#include"Stack.h"

using namespace std;


//GAME "BALLS"
	//1, 2, 3, 4, 5 - цвета шариков

DynamicStack<int, 100> game;
int nballs;   //количество шариков в игре, задается игроком
int color;    //цвет шарика
int ncolor;   //количество цветов
cout << endl;
cout << "\t\t\tGAME 'BALLS'" << endl;
cout << "\t\t\t------------\n" << endl;
cout << " Введите количество задействованных шариков в игре, но не более 100: ";
cin >> nballs;
cout << endl;
cout << " Введите количество цветов, но не более 5: ";
cin >> ncolor;
//заполняем рандомно все цвета шариков
for (size_t i = 0; i < nballs; i++)
{
	color = rand() % ncolor + 1;
	game.push(color);
}
cout << endl;
cout << " Рандомно сгенерированные шарики: ";
game.print();
DynamicStack<int, 100> temp;
do
{
	if (temp.getSize() == 0)
		temp.push(game.pop());
	if (game.getSize() != 0)
	{
		int tmp = temp.pop();
		int gmp = game.pop();
		if (gmp != tmp)
		{
			temp.push(tmp);
			temp.push(gmp);
		}
		else
		{
			temp.push(tmp);
			temp.push(gmp);

			if (game.getSize() != 0)
			{
				tmp = temp.pop();
				gmp = game.pop();
				if (gmp == tmp)
				{
					temp.pop();
				}
				else
				{
					temp.push(tmp);
					temp.push(gmp);
				}
			}
		}
	}
} while (game.getSize());
int delballs = nballs - temp.getSize();  //количесвто удаленных шариков
cout << endl << endl;;
cout << " Остаток шариков на печать: ";
temp.print();
cout << endl;
cout << " Количество удаленных шариков - " << delballs << endl;
#pragma once
#include<iostream>
#include"MyData.h"
#include"Queue.h"
#include"Stack.h"

using namespace std;


//GAME "BALLS"
	//1, 2, 3, 4, 5 - ����� �������

DynamicStack<int, 100> game;
int nballs;   //���������� ������� � ����, �������� �������
int color;    //���� ������
int ncolor;   //���������� ������
cout << endl;
cout << "\t\t\tGAME 'BALLS'" << endl;
cout << "\t\t\t------------\n" << endl;
cout << " ������� ���������� ��������������� ������� � ����, �� �� ����� 100: ";
cin >> nballs;
cout << endl;
cout << " ������� ���������� ������, �� �� ����� 5: ";
cin >> ncolor;
//��������� �������� ��� ����� �������
for (size_t i = 0; i < nballs; i++)
{
	color = rand() % ncolor + 1;
	game.push(color);
}
cout << endl;
cout << " �������� ��������������� ������: ";
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
int delballs = nballs - temp.getSize();  //���������� ��������� �������
cout << endl << endl;;
cout << " ������� ������� �� ������: ";
temp.print();
cout << endl;
cout << " ���������� ��������� ������� - " << delballs << endl;
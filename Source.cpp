#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Drob.h"
#include"PhoneBook.h"
#include"MyString.h"
#include"Time.h"


using namespace std;


int main()
{
	setlocale(0, "");

	//Time t1(20, 100, 200);
	//Time t2(10, 200, 500);
	Time t, t3;
	t3 = t(10, 15, 20, 15, 13, 25);
	//cout << (t1 != t2) << endl;
	t3.printTo12();
	t3.printTo24();








}
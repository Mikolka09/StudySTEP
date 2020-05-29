#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Drob.h"
#include"PhoneBook.h"

using namespace std;


int main()
{
	setlocale(0, "");

	PhoneBook PB;
	PB.addPhoneBook();
	PB.print();
	


}
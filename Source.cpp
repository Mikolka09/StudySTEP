#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Drob.h"
#include"PhoneBook.h"
#include"MyString.h"
#include"Time.h"
#include"Point3D.h"
#include"Vector3D.h"



using namespace std;



int main()
{
	setlocale(0, "");

	Drob a(1, 2, 3);
	Drob b(1, 2, 3);
	Drob c = a + b;
	c.print();









}
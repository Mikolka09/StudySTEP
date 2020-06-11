#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
//#include"Drob.h"
//#include"PhoneBook.h"
//#include"MyString.h"
//#include"Time.h"
#include"Point3D.h"
#include"Vector3D.h"


using namespace std;



int main()
{
	setlocale(0, "");

	Point3D p(1, 5, 3);
	Vector3D v(1, 3, 6);
	cout << p << endl;
	p.moveByVector(v);
	cout << p << endl;









}
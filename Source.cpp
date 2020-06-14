#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Drob.h"
#include"PhoneBook.h"
#include"MyString.h"
#include"Time.h"
#include"Point3D.h"
#include"Vector3D.h"
#include"Array2D.h"



using namespace std;



int main()
{
	setlocale(0, "");

	
	Array2D<int> arr1(2,2);
	arr1.setRandom();
	Array2D<int> arr2(2, 2);
	arr2.setRandom();
	Array2D<int> arr3(2, 2);
	arr3 = arr1 + arr2;
	arr3.print();










}
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
	srand(time(NULL));

	Array2D<int> arr1(2, 2);
	//arr1.setRandom();
	cin >> arr1;
	//arr1.print();
	cout << arr1 << endl;
	cout << endl;
	Sleep(500);
	Array2D<double> arr2(2, 2);
	arr2.setRandom();
	cout << arr2 << endl;
	cout << endl;
	/*Array2D<int> arr3(2, 2);
	arr3 = arr1 - arr2;
	arr3.print();*/
	cout << endl;
	/*Array2D<int> arr4(2, 2);
	arr4 = arr1/arr2;
	arr4.print();*/
	//double det = arr2.determinal(arr2);
	//cout << "Det = " << det << endl;
	//arr2.invers(arr2);
	//cout << endl;
	//arr2.print();
	//double det2= arr2.determinal(arr2);
	//cout << "Det2 = " << det2 << endl;
	//Array2D<double> arr4(2, 2);
	//arr4 = arr1/arr2;
	//arr4.print();
	cout <<" Max = "<< arr1.maxElem() << endl;
	cout << " Min = " << arr2.minElem() << endl;









}
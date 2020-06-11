#pragma once
#include<iostream>

using namespace std;

class Vector3D;

class Point3D
{
private:
	int x;
	int y;
	int z;
	
public:
	Point3D(int x, int y, int z) :x(x), y(y), z(z) {}

	friend ostream& operator<< (ostream& out, const Point3D& p);
	

	void moveByVector(const Vector3D& v);

};



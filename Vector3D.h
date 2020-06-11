#pragma once

class Vector3D
{
private:
	int x;
	int y;
	int z;
public:
	Vector3D(int x, int y, int z) :x(x), y(y), z(z) {}

	friend void  Point3D::moveByVector(const Vector3D& v);


};



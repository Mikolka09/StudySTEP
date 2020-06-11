#pragma once

class Vector3D;

class Point3D
{
private:
	int x;
	int y;
	int z;
public:
	Point3D(int x, int y, int z):x(x),y(y),z(z){}
	
	friend ostream& operator<< (ostream &out, const Point3D &p);

	
	void moveByVector(const Vector3D &v);

};

ostream& operator<< (ostream &out, const Point3D &p)
{
	out << "Point (" << p.x << ", " << p.y << ", " << p.z << ")" << endl;
	return out;
}


class Vector3D
{
private:
	int x;
	int y;
	int z;
public:
	Vector3D(int x, int y, int z) :x(x), y(y), z(z) {}
	
	friend void Point3D::moveByVector(const Vector3D &v);

	
};

void Point3D::moveByVector(const Vector3D &v)
{
	x += v.x;
	y += v.y;
	z += v.z;
}



#include"Point3D.h"
#include"Vector3D.h"



void Point3D::moveByVector(const Vector3D& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
}



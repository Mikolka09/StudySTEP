#include"Point3D.h"


ostream& operator<< (ostream& out, const Point3D& p)
{
	out << "Point (" << p.x << ", " << p.y << ", " << p.z << ")" << endl;
	return out;
}
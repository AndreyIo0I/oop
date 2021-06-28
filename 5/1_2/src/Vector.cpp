#include "Vector.h"
#include <cmath>
#include <iostream>

using namespace std;

CVector3D::CVector3D()
	: x(0)
	, y(0)
	, z(0)
{
}

CVector3D::CVector3D(double x0, double y0, double z0)
	: x(x0)
	, y(y0)
	, z(z0)
{
}

double CVector3D::GetLength() const
{
	return sqrt(x * x + y * y + z * z);
}

void CVector3D::Normalize()
{
	double length = this->GetLength();
	x /= length;
	y /= length;
	z /= length;
}

ostream& operator<<(ostream& os, const CVector3D& v)
{
	os << v.x << ", " << v.y << ", " << v.z << '\n';
	return os;
}
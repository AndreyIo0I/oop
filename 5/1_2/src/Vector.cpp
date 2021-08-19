#include "Vector.h"
#include <cmath>
#include <iostream>

using namespace std;

CVector3D::CVector3D(double x, double y, double z)
	: x(x)
	, y(y)
	, z(z)
{
}

CVector3D CVector3D::operator-() const
{
	return CVector3D(-x, -y, -z);
}

CVector3D CVector3D::operator+() const
{
	return CVector3D(x, y, z);
}

CVector3D CVector3D::operator*(double value) const
{
	return CVector3D(x * value, y * value, z * value);
}

CVector3D operator*(const double value, const CVector3D& v)
{
	return CVector3D(v.x * value, v.y * value, v.z * value);
}

CVector3D CVector3D::operator/(double value) const
{
	return CVector3D(x / value, y / value, z / value);
}

CVector3D CVector3D::operator-(const CVector3D& v) const
{
	return CVector3D(x - v.x, y - v.y, z - v.z);
}

CVector3D CVector3D::operator+(const CVector3D& v) const
{
	return CVector3D(x + v.x, y + v.y, z + v.z);
}

bool almostEqual(double a, double b)
{
	return abs(a - b) <= numeric_limits<double>::epsilon();
}

bool CVector3D::operator==(const CVector3D& v) const
{
	return (almostEqual(x, v.x) && almostEqual(y, v.y) && almostEqual(z, v.z));
}

bool CVector3D::operator!=(const CVector3D& v) const
{
	return !(*this == v);
}

void CVector3D::operator+=(const CVector3D& v)
{
	*this *= 1 + v.GetLength() / this->GetLength();
}

void CVector3D::operator-=(const CVector3D& v)
{
	*this *= 1 - v.GetLength() / this->GetLength();
}

void CVector3D::operator/=(double value)
{
	x /= value;
	y /= value;
	z /= value;
}

void CVector3D::operator*=(double value)
{
	x *= value;
	y *= value;
	z *= value;
}

ostream& operator<<(ostream& os, const CVector3D& v)
{
	os << v.x << ", " << v.y << ", " << v.z;
	return os;
}

istream& operator>>(istream& is, CVector3D& v)
{
	char ch;
	is >> v.x >> ch >> v.y >> ch >> v.z;
	return is;
}

double CVector3D::GetLength() const
{
	return sqrt(x * x + y * y + z * z);
}

CVector3D CVector3D::Normalize(const CVector3D& v)
{
	double length = v.GetLength();
	if (length > 0)
		return v / length;
	else
		return CVector3D();
}

double CVector3D::DotProduct(const CVector3D& a, const CVector3D& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

CVector3D CVector3D::CrossProduct(const CVector3D& a, const CVector3D& b)
{
	return CVector3D(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x);
}

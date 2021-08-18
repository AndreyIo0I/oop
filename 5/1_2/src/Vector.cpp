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

CVector3D CVector3D::operator-() const
{
	return { -x, -y, -z };
}

CVector3D CVector3D::operator+() const
{
	return { x, y, z };
}

CVector3D CVector3D::operator*(double value) const
{
	return { x * value, y * value, z * value };
}

CVector3D operator*(const double value, const CVector3D& v)
{
	return { v.x * value, v.y * value, v.z * value };
}

CVector3D CVector3D::operator/(double value) const
{
	return { x / value, y / value, z / value };
}

CVector3D CVector3D::operator-(const CVector3D& v) const
{
	return { x - v.x, y - v.y, z - v.z };
}

CVector3D CVector3D::operator+(const CVector3D& v) const
{
	return { x + v.x, y + v.y, z + v.z };
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
		return {};
}

double CVector3D::DotProduct(const CVector3D& a, const CVector3D& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

CVector3D CVector3D::CrossProduct(const CVector3D& a, const CVector3D& b)
{
	return {
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x,
	};
}

#pragma once
#include <iostream>

class CVector3D
{
public:
	explicit CVector3D(double x = 0, double y = 0, double z = 0);
	double GetLength() const;

	CVector3D operator+() const;
	CVector3D operator-(const CVector3D&) const;
	CVector3D operator+(const CVector3D&) const;
	CVector3D operator*(double) const;
	CVector3D operator/(double) const;
	bool operator==(const CVector3D&) const;
	bool operator!=(const CVector3D&) const;
	void operator+=(const CVector3D&);
	void operator-=(const CVector3D&);
	void operator/=(double value);
	void operator*=(double value);

	double x, y, z;
};

CVector3D Normalize(const CVector3D&);
double DotProduct(const CVector3D&, const CVector3D&);
CVector3D CrossProduct(const CVector3D&, const CVector3D&);

CVector3D operator-(const CVector3D&);
CVector3D operator*(double, const CVector3D&);
std::ostream& operator<<(std::ostream&, const CVector3D&);
std::istream& operator>>(std::istream&, CVector3D&);
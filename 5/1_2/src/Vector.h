#pragma once
#include <iostream>

class CVector3D
{
public:
	CVector3D();
	CVector3D(double, double, double);
	double GetLength() const;
	double x, y, z;

	static CVector3D Normalize(const CVector3D&);
	static double DotProduct(const CVector3D&, const CVector3D&);
	static CVector3D CrossProduct(const CVector3D&, const CVector3D&);

	CVector3D operator-() const;
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
	friend CVector3D operator*(double, const CVector3D&);
	friend std::ostream& operator<<(std::ostream&, const CVector3D&);
	friend std::istream& operator>>(std::istream&, CVector3D&);
};

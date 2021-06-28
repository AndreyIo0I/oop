#pragma once
#include <iostream>

class CVector3D
{
public:
	CVector3D();
	CVector3D(double x0, double y0, double z0);
	double GetLength() const;
	void Normalize();
	double x, y, z;

	friend std::ostream& operator<<(std::ostream& os, const CVector3D& v);
};

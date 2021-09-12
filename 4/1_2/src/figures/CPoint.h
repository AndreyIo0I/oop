#pragma once
#include <iostream>

class CPoint
{
public:
	CPoint(double, double);
	std::string ToString() const;
	double x, y;

	static double GetDistance(CPoint, CPoint);
};

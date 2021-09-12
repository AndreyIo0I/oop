#include "CPoint.h"
#include <string>

using namespace std;

CPoint::CPoint(double x, double y)
	: x(x)
	, y(y)
{
}

double CPoint::GetDistance(CPoint p1, CPoint p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

string CPoint::ToString() const
{
	return "(" + to_string(x) + ", " + to_string(y) + ')';
}

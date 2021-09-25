#include "CLineSegment.h"
#include <string>

using namespace std;

CLineSegment::CLineSegment(CPoint startPoint, CPoint endPoint, uint32_t outlineColor)
	: m_startPoint(startPoint)
	, m_endPoint(endPoint)
	, m_outlineColor(outlineColor)
{
}

CLineSegment::CLineSegment(double x1, double y1, double x2, double y2, uint32_t outlineColor)
	: CLineSegment(CPoint(x1, y1), CPoint(x2, y2), outlineColor)
{
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	return CPoint::GetDistance(m_startPoint, m_endPoint);
}

string CLineSegment::ToString() const
{
	return "line segment: " + m_startPoint.ToString() + ", " + m_endPoint.ToString() + ", " + to_string(m_outlineColor);
}

uint32_t CLineSegment::GetOutlineColor() const
{
	return m_outlineColor;
}

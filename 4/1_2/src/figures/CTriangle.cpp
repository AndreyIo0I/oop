#include "CTriangle.h"

CTriangle::CTriangle(CPoint vertex1, CPoint vertex2, CPoint vertex3, uint32_t outlineColor, uint32_t fillColor)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

CTriangle::CTriangle(double x1, double y1, double x2, double y2, double x3, double y3, uint32_t outlineColor, uint32_t fillColor)
	: CTriangle(CPoint(x1, y1), CPoint(x2, y2), CPoint(x3, y3), outlineColor, fillColor)
{
}

double CTriangle::GetPerimeter() const
{
	return CPoint::GetDistance(m_vertex1, m_vertex2) + CPoint::GetDistance(m_vertex3, m_vertex2) + CPoint::GetDistance(m_vertex1, m_vertex3);
}

double CTriangle::GetArea() const
{
	double a = CPoint::GetDistance(m_vertex1, m_vertex2);
	double b = CPoint::GetDistance(m_vertex3, m_vertex2);
	double c = CPoint::GetDistance(m_vertex1, m_vertex3);
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

std::string CTriangle::ToString() const
{
	return "triangle: " + m_vertex1.ToString() + ' ' + m_vertex2.ToString() + ' ' + m_vertex3.ToString();
}

uint32_t CTriangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CTriangle::GetFillColor() const
{
	return m_fillColor;
}

CPoint CTriangle::GetVertex1()
{
	return m_vertex1;
}

CPoint CTriangle::GetVertex2()
{
	return m_vertex2;
}

CPoint CTriangle::GetVertex3()
{
	return m_vertex3;
}
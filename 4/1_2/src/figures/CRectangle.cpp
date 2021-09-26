#include "CRectangle.h"
#include <sstream>

using namespace std;

CRectangle::CRectangle(CPoint vertex1, CPoint vertex2, uint32_t outlineColor, uint32_t fillColor)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

CRectangle::CRectangle(double x1, double y1, double x2, double y2, uint32_t outlineColor, uint32_t fillColor)
	: CRectangle(CPoint(x1, y1), CPoint(x2, y2), outlineColor, fillColor)
{
}

CPoint CRectangle::GetLeftTop()
{
	return m_vertex1;
}

CPoint CRectangle::GetRightBottom()
{
	return m_vertex2;
}

double CRectangle::GetWidth() const
{
	return abs(m_vertex1.x - m_vertex2.x);
}

double CRectangle::GetHeight() const
{
	return abs(m_vertex1.y - m_vertex2.y);
}

uint32_t CRectangle::GetOutlineColor() const
{
	return m_outlineColor;
}

uint32_t CRectangle::GetFillColor() const
{
	return m_fillColor;
}

std::string CRectangle::ToString() const
{
	stringstream colors;
	colors << hex <<  m_outlineColor << ' ' << m_fillColor;
	return "rectangle: " + m_vertex1.ToString() + ' ' + m_vertex2.ToString() + ' ' + colors.str();
}

double CRectangle::GetPerimeter() const
{
	return 2 * (this->GetWidth() + this->GetHeight());
}

double CRectangle::GetArea() const
{
	return this->GetWidth() * this->GetHeight();
}

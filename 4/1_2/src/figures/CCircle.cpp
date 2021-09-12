#define _USE_MATH_DEFINES
#include "CCircle.h"
#include <cmath>

CCircle::CCircle(CPoint center, double radius, uint32_t outlineColor, uint32_t fillColor)
	: m_center(center)
	, m_radius(radius)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

CPoint CCircle::GetCenter()
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

uint32_t CCircle::GetFillColor() const
{
	return m_fillColor;
}

uint32_t CCircle::GetOutlineColor() const
{
	return m_outlineColor;
}

std::string CCircle::ToString() const
{
	return "circle";
}

double CCircle::GetPerimeter() const
{
	return 2 * M_PI * m_radius;
}

double CCircle::GetArea() const
{
	return M_PI * m_radius * m_radius;
}

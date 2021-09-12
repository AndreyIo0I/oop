#include "CRectangle.h"

CRectangle::CRectangle(CPoint vertex1, CPoint vertex2, uint32_t outlineColor, uint32_t fillColor)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
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
	return "rectangle";
}

double CRectangle::GetPerimeter() const
{
	return 2 * (this->GetWidth() + this->GetHeight());
}

double CRectangle::GetArea() const
{
	return this->GetWidth() * this->GetHeight();
}

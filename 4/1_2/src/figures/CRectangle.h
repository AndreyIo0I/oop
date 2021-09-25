#pragma once
#include "CPoint.h"
#include "ISolidShape.h"

class CRectangle : public ISolidShape
{
public:
	CRectangle(CPoint, CPoint, uint32_t = 0, uint32_t = 0);
	CRectangle(double, double, double, double, uint32_t = 0, uint32_t = 0);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;

	CPoint GetLeftTop();
	CPoint GetRightBottom();
	double GetWidth() const;
	double GetHeight() const;

private:
	CPoint m_vertex1, m_vertex2;
	uint32_t m_outlineColor, m_fillColor;
};

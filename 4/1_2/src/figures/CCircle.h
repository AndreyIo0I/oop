#pragma once
#include "CPoint.h"
#include "ISolidShape.h"

class CCircle : public ISolidShape
{
public:
	CCircle(CPoint, double, uint32_t = 0, uint32_t = 0);
	CCircle(double, double, double, uint32_t = 0, uint32_t = 0);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;

	CPoint GetCenter();
	double GetRadius() const;

private:
	CPoint m_center;
	double m_radius;
	uint32_t m_outlineColor, m_fillColor;
};

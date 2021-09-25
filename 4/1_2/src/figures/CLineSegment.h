#pragma once
#include "CPoint.h"
#include "IShape.h"
#include <iostream>

class CLineSegment : public IShape
{
public:
	CLineSegment(CPoint, CPoint, uint32_t = 0);
	CLineSegment(double, double, double, double, uint32_t = 0);
	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	uint32_t GetOutlineColor() const override;

private:
	CPoint m_startPoint, m_endPoint;
	uint32_t m_outlineColor;
};

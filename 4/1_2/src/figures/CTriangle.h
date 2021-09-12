#pragma once
#include "CPoint.h"
#include "ISolidShape.h"
#include <iostream>

class CTriangle : public ISolidShape
{
public:
	CTriangle(CPoint, CPoint, CPoint, uint32_t = 0, uint32_t = 0);
	double GetArea() const override;
	double GetPerimeter() const override;
	std::string ToString() const override;
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;

	CPoint GetVertex1();
	CPoint GetVertex2();
	CPoint GetVertex3();

private:
	CPoint m_vertex1, m_vertex2, m_vertex3;
	uint32_t m_outlineColor, m_fillColor;
};

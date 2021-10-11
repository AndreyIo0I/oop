#pragma once
#include "CPoint.h"
#include "ISolidShape.h"

class CSolidShape : public ISolidShape
{
public:
	uint32_t GetOutlineColor() const override;
	uint32_t GetFillColor() const override;

protected:
	uint32_t m_outlineColor, m_fillColor;
};

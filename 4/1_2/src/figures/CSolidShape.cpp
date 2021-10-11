#include "CSolidShape.h"
#include <string>

using namespace std;

uint32_t CSolidShape::GetFillColor() const
{
	return m_fillColor;
}

uint32_t CSolidShape::GetOutlineColor() const
{
	return m_outlineColor;
}

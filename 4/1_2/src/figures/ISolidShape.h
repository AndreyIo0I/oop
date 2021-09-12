#pragma once
#include "IShape.h"
#include <iostream>

class ISolidShape : public IShape
{
public:
	virtual uint32_t GetFillColor() const = 0;
};

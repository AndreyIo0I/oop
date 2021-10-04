#pragma once
#include "figures/IShape.h"
#include <vector>

using namespace std;

void PrintShapes(ostream& output, const vector<unique_ptr<IShape>>& shapes)
{
	for (auto& shape : shapes)
	{
		output << shape->ToString() << '\n';
	}
}
#pragma once
#include <algorithm>
#include <figures/IShape.h>
#include <vector>

using namespace std;

IShape* GetMaxAreaShape(const vector<unique_ptr<IShape>>& shapes)
{
	if (shapes.empty())
		return nullptr;
	return max_element(
		shapes.begin(),
		shapes.end(),
		[](const unique_ptr<IShape>& s1, const unique_ptr<IShape>& s2) {
			return s1->GetArea() < s2->GetArea();
		})
		->get();
}

IShape* GetMinPerimeterShape(const vector<unique_ptr<IShape>>& shapes)
{
	if (shapes.empty())
		return nullptr;
	return min_element(
		shapes.begin(),
		shapes.end(),
		[](const unique_ptr<IShape>& s1, const unique_ptr<IShape>& s2) {
			return s1->GetPerimeter() < s2->GetPerimeter();
		})
		->get();
}
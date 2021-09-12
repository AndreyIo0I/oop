#include <algorithm>
#include <figures/CCircle.h>
#include <figures/CLineSegment.h>
#include <figures/CRectangle.h>
#include <figures/CTriangle.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<shared_ptr<IShape>> ReadShapes(istream& input)
{
	vector<shared_ptr<IShape>> shapes;
	string shapeType;

	while (!input.eof() && !input.fail())
	{
		input >> shapeType;

		if (shapeType == "line")
		{
			double startPointX, startPointY, endPointX, endPointY;
			input >> startPointX >> startPointY >> endPointX >> endPointY;
			shapes.push_back(make_shared<CLineSegment>(CLineSegment(
				CPoint(startPointX, startPointY),
				CPoint(endPointX, endPointY))));
		}
		else if (shapeType == "circle")
		{
			double pointX, pointY, radius;
			input >> pointX >> pointY >> radius;
			shapes.push_back(make_shared<CCircle>(CPoint(pointX, pointY), radius));
		}
		else if (shapeType == "rectangle")
		{
			double pointX, pointY, point2X, point2Y;
			input >> pointX >> pointY >> point2X >> point2Y;
			shapes.push_back(make_shared<CRectangle>(CPoint(pointX, pointY), CPoint(point2X, point2Y)));
		}
		else if (shapeType == "triangle")
		{

			double pointX, pointY, point2X, point2Y, point3X, point3Y;
			input >> pointX >> pointY >> point2X >> point2Y >> point3X >> point3Y;
			shapes.push_back(make_shared<CTriangle>(CPoint(pointX, pointY), CPoint(point2X, point2Y), CPoint(point3X, point3Y)));
		}
	}
	return shapes;
}

void PrintShapes(ostream& output, const vector<shared_ptr<IShape>>& shapes)
{
	for (auto& shape : shapes)
	{
		output << shape->ToString() << '\n';
	}
}

shared_ptr<IShape> GetMaxAreaShape(const vector<shared_ptr<IShape>>& shapes)
{
	return *max_element(
		shapes.begin(),
		shapes.end(),
		[](const shared_ptr<IShape>& s1, const shared_ptr<IShape>& s2) {
			return s1->GetArea() < s2->GetArea();
		});
}

shared_ptr<IShape> GetMinPerimeterShape(const vector<shared_ptr<IShape>>& shapes)
{
	return *min_element(
		shapes.begin(),
		shapes.end(),
		[](const shared_ptr<IShape>& s1, const shared_ptr<IShape>& s2) {
			return s1->GetPerimeter() < s2->GetPerimeter();
		});
}

int main()
{
	vector<shared_ptr<IShape>> shapes = ReadShapes(cin);
	cout << "max area - " << GetMaxAreaShape(shapes)->ToString() << '\n';
	cout << "min perimeter - " << GetMinPerimeterShape(shapes)->ToString() << '\n';
	PrintShapes(cout, shapes);
	cout << shapes[3]->GetArea();
	return 0;
}
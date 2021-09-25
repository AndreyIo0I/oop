#include "figures/CCircle.h"
#include "figures/CLineSegment.h"
#include "figures/CRectangle.h"
#include "figures/CTriangle.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
vector<T> getParameters(istream& input, int count = INT_MAX)
{
	T parameter;
	vector<T> parameters;

	for (; input >> parameter && count; --count)
		parameters.push_back(parameter);

	return parameters;
}

vector<shared_ptr<IShape>> ReadShapes(istream& input)
{
	vector<shared_ptr<IShape>> shapes;
	string shapeParametersString;

	while (input)
	{
		getline(input, shapeParametersString);
		stringstream shapeParameters = stringstream(shapeParametersString);
		string shapeType;
		shapeParameters >> shapeType;
		vector<double> pointParameters;
		vector<uint32_t> colorParameters;

		if (shapeType == "line")
		{
			pointParameters = getParameters<double>(shapeParameters, 4);
			colorParameters = getParameters<uint32_t>(shapeParameters);
			if (pointParameters.size() != 4 || colorParameters.size() > 2)
				continue;
			switch (colorParameters.size())
			{
			case 0:
				shapes.push_back(make_shared<CLineSegment>(pointParameters[0], pointParameters[1], pointParameters[2], pointParameters[3]));
				break;
			case 1:
				shapes.push_back(make_shared<CLineSegment>(pointParameters[0], pointParameters[1], pointParameters[2], pointParameters[3], colorParameters[0]));
				break;
			}
		}
		else if (shapeType == "circle")
		{
			pointParameters = getParameters<double>(shapeParameters, 3);
			colorParameters = getParameters<uint32_t>(shapeParameters >> hex);
			if (pointParameters.size() != 3 || colorParameters.size() > 2)
				continue;
			switch (colorParameters.size())
			{
			case 0:
				shapes.push_back(make_shared<CCircle>(pointParameters[0], pointParameters[1], pointParameters[2]));
				break;
			case 1:
				shapes.push_back(make_shared<CCircle>(pointParameters[0], pointParameters[1], pointParameters[2], colorParameters[0]));
				break;
			case 2:
				shapes.push_back(make_shared<CCircle>(pointParameters[0], pointParameters[1], pointParameters[2], colorParameters[0], colorParameters[1]));
				break;
			}
		}
		else if (shapeType == "rectangle")
		{
			pointParameters = getParameters<double>(shapeParameters, 4);
			colorParameters = getParameters<uint32_t>(shapeParameters >> hex);
			if (pointParameters.size() != 4 || colorParameters.size() > 2)
				continue;
			switch (colorParameters.size())
			{
			case 0:
				shapes.push_back(make_shared<CRectangle>(pointParameters[0], pointParameters[1], pointParameters[2], pointParameters[3]));
				break;
			case 1:
				shapes.push_back(make_shared<CRectangle>(pointParameters[0], pointParameters[1], pointParameters[2], pointParameters[3], colorParameters[0]));
				break;
			case 2:
				shapes.push_back(make_shared<CRectangle>(pointParameters[0], pointParameters[1], pointParameters[2], pointParameters[3], colorParameters[0], colorParameters[1]));
				break;
			}
		}
		else if (shapeType == "triangle")
		{
			pointParameters = getParameters<double>(shapeParameters, 6);
			colorParameters = getParameters<uint32_t>(shapeParameters >> hex);
			if (pointParameters.size() != 6 || colorParameters.size() > 2)
				continue;
			switch (colorParameters.size())
			{
			case 0:
				shapes.push_back(make_shared<CTriangle>(pointParameters[0], pointParameters[1], pointParameters[2], pointParameters[3], pointParameters[4], pointParameters[5]));
				break;
			case 1:
				shapes.push_back(make_shared<CTriangle>(pointParameters[0], pointParameters[1], pointParameters[2], pointParameters[3], pointParameters[4], pointParameters[5], colorParameters[0]));
				break;
			case 2:
				shapes.push_back(make_shared<CTriangle>(pointParameters[0], pointParameters[1], pointParameters[2], pointParameters[3], pointParameters[4], pointParameters[5], colorParameters[0], colorParameters[1]));
				break;
			}
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
	PrintShapes(cout, shapes);
	//	cout << "max area: " << GetMaxAreaShape(shapes)->ToString() << '\n';
	//	cout << "min perimeter: " << GetMinPerimeterShape(shapes)->ToString() << '\n';

	return 0;
}
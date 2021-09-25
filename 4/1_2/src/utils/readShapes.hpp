#pragma once
#include <figures/CCircle.h>
#include <figures/CLineSegment.h>
#include <figures/CRectangle.h>
#include <figures/CTriangle.h>
#include <sstream>

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
		vector<double> sizeParameters;
		vector<uint32_t> colorParameters;

		if (shapeType == "line")
		{
			sizeParameters = getParameters<double>(shapeParameters, 4);
			colorParameters = getParameters<uint32_t>(shapeParameters);
			if (sizeParameters.size() != 4 || colorParameters.size() > 2)
				continue;
			switch (colorParameters.size())
			{
			case 0:
				shapes.push_back(make_shared<CLineSegment>(sizeParameters[0], sizeParameters[1], sizeParameters[2], sizeParameters[3]));
				break;
			case 1:
				shapes.push_back(make_shared<CLineSegment>(sizeParameters[0], sizeParameters[1], sizeParameters[2], sizeParameters[3], colorParameters[0]));
				break;
			}
		}
		else if (shapeType == "circle")
		{
			sizeParameters = getParameters<double>(shapeParameters, 3);
			colorParameters = getParameters<uint32_t>(shapeParameters >> hex);
			if (sizeParameters.size() != 3 || colorParameters.size() > 2)
				continue;
			switch (colorParameters.size())
			{
			case 0:
				shapes.push_back(make_shared<CCircle>(sizeParameters[0], sizeParameters[1], sizeParameters[2]));
				break;
			case 1:
				shapes.push_back(make_shared<CCircle>(sizeParameters[0], sizeParameters[1], sizeParameters[2], colorParameters[0]));
				break;
			case 2:
				shapes.push_back(make_shared<CCircle>(sizeParameters[0], sizeParameters[1], sizeParameters[2], colorParameters[0], colorParameters[1]));
				break;
			}
		}
		else if (shapeType == "rectangle")
		{
			sizeParameters = getParameters<double>(shapeParameters, 4);
			colorParameters = getParameters<uint32_t>(shapeParameters >> hex);
			if (sizeParameters.size() != 4 || colorParameters.size() > 2)
				continue;
			switch (colorParameters.size())
			{
			case 0:
				shapes.push_back(make_shared<CRectangle>(sizeParameters[0], sizeParameters[1], sizeParameters[2], sizeParameters[3]));
				break;
			case 1:
				shapes.push_back(make_shared<CRectangle>(sizeParameters[0], sizeParameters[1], sizeParameters[2], sizeParameters[3], colorParameters[0]));
				break;
			case 2:
				shapes.push_back(make_shared<CRectangle>(sizeParameters[0], sizeParameters[1], sizeParameters[2], sizeParameters[3], colorParameters[0], colorParameters[1]));
				break;
			}
		}
		else if (shapeType == "triangle")
		{
			sizeParameters = getParameters<double>(shapeParameters, 6);
			colorParameters = getParameters<uint32_t>(shapeParameters >> hex);
			if (sizeParameters.size() != 6 || colorParameters.size() > 2)
				continue;
			switch (colorParameters.size())
			{
			case 0:
				shapes.push_back(make_shared<CTriangle>(sizeParameters[0], sizeParameters[1], sizeParameters[2], sizeParameters[3], sizeParameters[4], sizeParameters[5]));
				break;
			case 1:
				shapes.push_back(make_shared<CTriangle>(sizeParameters[0], sizeParameters[1], sizeParameters[2], sizeParameters[3], sizeParameters[4], sizeParameters[5], colorParameters[0]));
				break;
			case 2:
				shapes.push_back(make_shared<CTriangle>(sizeParameters[0], sizeParameters[1], sizeParameters[2], sizeParameters[3], sizeParameters[4], sizeParameters[5], colorParameters[0], colorParameters[1]));
				break;
			}
		}
	}
	return shapes;
}

#pragma once
#include <figures/CCircle.h>
#include <figures/CLineSegment.h>
#include <figures/CRectangle.h>
#include <figures/CTriangle.h>
#include <sstream>

using namespace std;

void getParameters(istringstream& parametersInput, vector<double>& sizeParameters, vector<uint32_t>& colorParameters, int count)
{
	string parameter;
	double sizeParameter;
	uint32_t colorParameter;
	while (parametersInput >> parameter)
	{
		if (istringstream(parameter) >> sizeParameter && count) {
			sizeParameters.push_back(sizeParameter);
			--count;
		}
		else if (istringstream(parameter) >> hex >> colorParameter) {
			colorParameters.push_back(colorParameter);
		}
	}
}

vector<shared_ptr<IShape>> ReadShapes(istream& input)
{
	vector<shared_ptr<IShape>> shapes;
	string shapeParametersString;

	while (input && !input.eof())
	{
		getline(input, shapeParametersString);
		auto parametersInput = istringstream(shapeParametersString);
		string shapeType;
		parametersInput >> shapeType;
		vector<double> sizeParameters;
		vector<uint32_t> colorParameters;

		if (shapeType == "line")
		{
			const int REQUIRED_PARAMETERS = 4;
			getParameters(parametersInput, sizeParameters, colorParameters, REQUIRED_PARAMETERS);
			if (sizeParameters.size() != REQUIRED_PARAMETERS || colorParameters.size() > 2)
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
			const int REQUIRED_PARAMETERS = 3;
			getParameters(parametersInput, sizeParameters, colorParameters, REQUIRED_PARAMETERS);
			if (sizeParameters.size() != REQUIRED_PARAMETERS || colorParameters.size() > 2)
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
			const int REQUIRED_PARAMETERS = 4;
			getParameters(parametersInput, sizeParameters, colorParameters, REQUIRED_PARAMETERS);
			if (sizeParameters.size() != REQUIRED_PARAMETERS || colorParameters.size() > 2)
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
			const int REQUIRED_PARAMETERS = 6;
			getParameters(parametersInput, sizeParameters, colorParameters, REQUIRED_PARAMETERS);
			if (sizeParameters.size() != REQUIRED_PARAMETERS || colorParameters.size() > 2)
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

#pragma once
#include "Car.h"
#include <functional>
#include <iosfwd>
#include <map>
#include <string>

class CConsoleControl
{
public:
	CConsoleControl(CCar& car, std::istream& input, std::ostream& output);
	bool HandleCommand();

private:
	void Info(std::istream& args);
	void EngineOn(std::istream& args);
	void EngineOff(std::istream& args);
	void SetGear(std::istream& args);
	void SetSpeed(std::istream& args);

	using Handler = std::function<void(std::istream& args)>;
	using ActionMap = std::map<std::string, Handler>;

	CCar& m_car;
	std::istream& m_input;
	std::ostream& m_output;

	const ActionMap m_actionMap;
};

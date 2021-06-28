#include "ConsoleControl.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

CConsoleControl::CConsoleControl(CCar& car, std::istream& input, std::ostream& output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		  { "EngineOn", [this](istream& strm) {
			   EngineOn(strm);
		   } },
		  { "EngineOff", [this](istream& strm) {
			   EngineOff(strm);
		   } },
		  { "Info", [this](istream& strm) {
			   Info(strm);
		   } },
		  { "SetGear", [this](istream& strm) {
			   SetGear(strm);
		   } },
		  { "SetSpeed", [this](istream& strm) {
			   SetSpeed(strm);
		   } },
	  })
{
}

bool CConsoleControl::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strm(commandLine);

	string action;
	strm >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		it->second(strm);
		return true;
	}

	return false;
}

void CConsoleControl::EngineOn(std::istream& /*args*/)
{
	m_car.TurnOnEngine();
	m_output << "Engine is turned on"
			 << "\n";
}

void CConsoleControl::EngineOff(std::istream& /*args*/)
{
	if (m_car.TurnOffEngine())
	{
		m_output << "Engine is turned off\n";
	}
	else
	{
		m_output << "Car mast be at speed and gear 0\n";
	}
}

void CConsoleControl::Info(std::istream& args /*args*/)
{
	if (m_car.IsTurnedOn())
	{
		m_output << "Engine is turned on\n";
		m_output << "Movement direction: ";
		switch (m_car.GetDirection())
		{
		case CDirection::forward:
			m_output << "forward\n";
			break;
		case CDirection::backward:
			m_output << "backward\n";
			break;
		case CDirection::standing:
			m_output << "standing\n";
			break;
		}
		m_output << "Speed: " << m_car.GetSpeed() << "\n";
		m_output << "Gear: " << m_car.GetGear() << "\n";
	}
	else
	{
		m_output << "Engine is turned off\n";
	}
}

void CConsoleControl::SetGear(std::istream& input)
{
	string inputString;
	input >> inputString;

	try
	{
		int gear = stoi(inputString);
		if (m_car.SetGear(gear))
		{
			m_output << "Selected gear: " << to_string(m_car.GetGear()) << "\n";
		}
		else
		{
			if (m_car.IsTurnedOn())
			{
				m_output << "Selected gear is out of speed range!\n";
			}
			else
			{
				m_output << "Engine is turned off!\n";
			}
		}
	}
	catch (...)
	{
		m_output << "Input must be a decimal number\n";
	}
}

void CConsoleControl::SetSpeed(std::istream& input)
{
	string inputString;
	input >> inputString;

	try
	{
		int speed = stoi(inputString);
		if (m_car.SetSpeed(speed))
		{
			m_output << "Selected speed: " << to_string(m_car.GetSpeed()) << "\n";
		}
		else
		{
			if (m_car.IsTurnedOn())
			{
				m_output << "Selected speed is out of gear speed range!\n";
			}
			else
			{
				m_output << "Engine is turned off!\n";
			}
		}
	}
	catch (...)
	{
		m_output << "Input must be a decimal number\n";
	}
}
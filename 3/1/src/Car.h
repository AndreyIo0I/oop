#pragma once
#include <map>
#include <string>

enum class CDirection
{
	forward,
	backward,
	standing,
};

class CCar
{
public:
	bool IsTurnedOn() const;
	CDirection GetDirection() const;
	int GetSpeed() const;
	int GetGear() const;
	bool TurnOnEngine();
	bool TurnOffEngine();
	bool SetGear(int gear);
	bool SetSpeed(int speed);

private:
	bool m_isEngineOn = false;
	int m_gear = 0;
	int m_speed = 0;
};

#pragma once
#include <string>
#include <map>

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
	bool m_isOn = false;
	int m_gear = 0;
	int m_speed = 0;
	CDirection m_direction = CDirection::standing;
};

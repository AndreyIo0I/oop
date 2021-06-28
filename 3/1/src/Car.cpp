#include "Car.h"

bool CCar::IsTurnedOn() const
{
	return m_isEngineOn;
}

CDirection CCar::GetDirection() const
{
	if (m_speed > 0)
	{
		return CDirection::forward;
	}
	else if (m_speed < 0)
	{
		return CDirection::backward;
	}
	return CDirection::standing;
}

int CCar::GetSpeed() const
{
	return abs(m_speed);
}

int CCar::GetGear() const
{
	return m_gear;
}

bool CCar::TurnOnEngine()
{
	m_isEngineOn = true;
	return true;
}

bool CCar::TurnOffEngine()
{
	if (m_speed == 0 && m_gear == 0)
	{
		m_isEngineOn = false;
		return true;
	}
	return false;
}

bool gearInSpeedRange(int gear, int speed)
{
	switch (gear)
	{
	case -1:
		return speed <= 0 && speed >= -20;
	case 0:
		return true;
	case 1:
		return speed >= 0 && speed <= 30;
	case 2:
		return speed >= 20 && speed <= 50;
	case 3:
		return speed >= 30 && speed <= 60;
	case 4:
		return speed >= 40 && speed <= 90;
	case 5:
		return speed >= 50 && speed <= 150;
	default:
		return false;
	}
}

bool CCar::SetGear(int gear)
{
	if (m_isEngineOn)
	{
		if (gear != m_gear && !gearInSpeedRange(gear, m_speed) || gear == -1 && m_speed != 0)
			return false;
		m_gear = gear;
		return true;
	}
	else
	{
		return gear == 0;
	}
}

bool CCar::SetSpeed(int speed)
{
	if (m_isEngineOn && speed >= 0)
	{
		if (m_gear == 0 && speed > abs(m_speed))
			return false;
		if (m_gear < 0)
			speed *= -1;
		if (!gearInSpeedRange(m_gear, speed))
			return false;
		m_speed = speed;
		return true;
	}
	return false;
}

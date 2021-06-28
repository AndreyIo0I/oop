#include "catch.hpp"
#include <Car.h>
#include <ConsoleControl.h>

using namespace std;

SCENARIO("Using RemoteControl")
{
	CCar car;

	GIVEN("remoteControl with a new tv")
	{
		WHEN("we handle Info")
		{
			istringstream input("Info\n");
			ostringstream output("");
			CConsoleControl remoteControl(car, input, output);
			remoteControl.HandleCommand();
			THEN("car is turned off")
			{
				REQUIRE(output.str() == "Engine is turned off\n");
			}
		}

		WHEN("we handle EngineOn")
		{
			istringstream input("EngineOn\n");
			ostringstream output("");
			CConsoleControl remoteControl(car, input, output);
			remoteControl.HandleCommand();
			THEN("car is turned on")
			{
				REQUIRE(output.str() == "Engine is turned on\n");
			}
		}

		car.TurnOnEngine();
		car.SetGear(1);
		WHEN("we handle SetSpeed")
		{
			istringstream input("SetSpeed 20\n");
			ostringstream output("");
			CConsoleControl remoteControl(car, input, output);
			remoteControl.HandleCommand();
			THEN("speed is 20")
			{
				REQUIRE(output.str() == "Selected speed: 20\n");
			}
		}

		WHEN("we handle SetGear")
		{
			istringstream input("SetGear 0\n");
			ostringstream output("");
			CConsoleControl remoteControl(car, input, output);
			remoteControl.HandleCommand();
			THEN("gear is 0")
			{
				REQUIRE(output.str() == "Selected gear: 0\n");
			}
		}

		WHEN("we handle Info again")
		{
			istringstream input("Info\n");
			ostringstream output("");
			CConsoleControl remoteControl(car, input, output);
			remoteControl.HandleCommand();
			THEN("we get Info")
			{
				REQUIRE(output.str() == "Engine is turned on\nMovement direction: standing\nSpeed: 0\nGear: 1\n");
			}
		}
	}
}
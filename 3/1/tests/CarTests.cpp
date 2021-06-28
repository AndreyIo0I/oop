#define CATCH_CONFIG_MAIN

#include <Car.h>
#include "catch.hpp"

SCENARIO("Using Car")
{
	CCar car;

    GIVEN("new car")
    {
        WHEN("we call IsTurnedOn()")
        {
            THEN("car is turned off")
            {
                REQUIRE(!car.IsTurnedOn());
            }
        }

		WHEN("we call GetSpeed()")
		{
			THEN("we get speed 0")
			{
				REQUIRE(car.GetSpeed() == 0);
			}
		}

		WHEN("we call SetSpeed(5)")
		{
			THEN("we get false")
			{
				REQUIRE(!car.SetSpeed(5));
			}
		}

		WHEN("we call TurnOnEngine()")
		{
			car.TurnOnEngine();
			THEN("car is turned on")
			{
				REQUIRE(car.IsTurnedOn());
			}
		}
	}

	car.TurnOnEngine();
	GIVEN("turned on car")
	{
		WHEN("we call TurnOn again")
		{
			car.TurnOnEngine();
			THEN("car is still turned on")
			{
				REQUIRE(car.IsTurnedOn());
			}
		}

		WHEN("we call GetGear() in first time")
		{
			THEN("we get gear 0")
			{
				REQUIRE(car.GetGear() == 0);
			}
		}

		WHEN("we call GetSpeed() in first time")
		{
			THEN("we get speed 0")
			{
				REQUIRE(car.GetSpeed() == 0);
			}
		}

		WHEN("we call SetGear(1)")
		{
			car.SetGear(1);
			THEN("we get gear 1")
			{
				REQUIRE(car.GetGear() == 1);
			}
		}
	}

	car.SetGear(1);
	car.SetSpeed(30);
	car.SetGear(2);
	GIVEN("turned on car on gear 2 with speed 30")
	{
		WHEN("we call set speed 15")
		{
			THEN("returned false and speed didn't change")
			{
				REQUIRE(!car.SetSpeed(15));
				REQUIRE(car.GetSpeed() == 30);
			}
		}

		WHEN("we call TurnOffEngine()")
		{
			car.TurnOffEngine();
			THEN("car is turned on")
			{
				REQUIRE(car.IsTurnedOn());
			}
		}

		WHEN("we set speed and gear 0, call TurnOffEngine()")
		{
			THEN("car is turned off")
			{
				REQUIRE(car.SetSpeed(20));
				REQUIRE(car.SetGear(0));
				REQUIRE(car.SetSpeed(0));
				REQUIRE(car.TurnOffEngine());
				REQUIRE(!car.IsTurnedOn());
			}
		}

		WHEN("we call TurnOff() again")
		{
			car.TurnOffEngine();
			THEN("car is still turned off")
			{
				REQUIRE(car.IsTurnedOn());
			}
		}
	}

	car.SetSpeed(20);
	car.SetGear(0);
	car.SetSpeed(0);
	car.TurnOffEngine();
	GIVEN("turned off car")
	{
		WHEN("we call GetSpeed()")
		{
			THEN("we get speed and gear 0")
			{
				REQUIRE(!car.IsTurnedOn());
				REQUIRE(car.GetSpeed() == 0);
				REQUIRE(car.GetGear() == 0);
			}
		}

		WHEN("we call TurnOnEngine")
		{
			car.TurnOnEngine();
			THEN("car is turned on")
			{
				REQUIRE(car.IsTurnedOn());
			}
		}
	}
}
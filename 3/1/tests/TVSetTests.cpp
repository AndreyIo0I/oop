#define CATCH_CONFIG_MAIN

#include <TVSet.h>
#include "catch.hpp"

SCENARIO("Using TVSet")
{
	CTVSet tv;

    GIVEN("new tv")
    {
        WHEN("we call IsTurnedOn()")
        {
            THEN("tv is turned off")
            {
                REQUIRE(!tv.IsTurnedOn());
            }
        }

		WHEN("we call GetChannel()")
		{
			THEN("we get channel 0")
			{
				REQUIRE(tv.GetChannel() == 0);
			}
		}

		WHEN("we call SelectChannel(5)")
		{
			THEN("we get false")
			{
				REQUIRE(!tv.SelectChannel(5));
			}
		}

		WHEN("we call TurnOn")
		{
			tv.TurnOn();
			THEN("tv is turned on")
			{
				REQUIRE(tv.IsTurnedOn());
			}
		}
	}

	tv.TurnOn();
	GIVEN("turned on tv")
	{
		WHEN("we call TurnOn again")
		{
			tv.TurnOn();
			THEN("tv is still turned on")
			{
				REQUIRE(tv.IsTurnedOn());
			}
		}

		WHEN("we call GetChannel() in first time")
		{
			THEN("we get channel 1")
			{
				REQUIRE(tv.GetChannel() == 1);
			}
		}

		WHEN("we call SelectChannel(42)")
		{
			tv.SelectChannel(42);
			THEN("we get channel 42")
			{
				REQUIRE(tv.GetChannel() == 42);
			}
		}
	}

	tv.SelectChannel(42);
	GIVEN("turned on tv on channel 42")
	{
		WHEN("we call select channels 0, 100 and 3000")
		{
			tv.SelectChannel(0);
			tv.SelectChannel(100);
			tv.SelectChannel(3000);
			THEN("we get channel 42")
			{
				REQUIRE(tv.GetChannel() == 42);
			}
		}

		WHEN("we call TurnOff()")
		{
			tv.TurnOff();
			THEN("tv is turned off")
			{
				REQUIRE(!tv.IsTurnedOn());
			}
		}

		WHEN("we call TurnOff() again")
		{
			tv.TurnOff();
			THEN("tv is still turned off")
			{
				REQUIRE(!tv.IsTurnedOn());
			}
		}
	}

	tv.TurnOff();
	GIVEN("turned off tv on channel 42")
	{
		WHEN("we call GetChannel()")
		{
			THEN("we get channel 0")
			{
				REQUIRE(tv.GetChannel() == 0);
			}
		}

		WHEN("we call TurnOn")
		{
			tv.TurnOn();
			THEN("tv is turned on")
			{
				REQUIRE(tv.IsTurnedOn());
			}
		}
	}

	tv.TurnOn();
	GIVEN("turned on again tv on channel 42")
	{
		WHEN("we call GetChannel()")
		{
			THEN("we get channel 42")
			{
				REQUIRE(tv.GetChannel() == 42);
			}
		}
	}
}
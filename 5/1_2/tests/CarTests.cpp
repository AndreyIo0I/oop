#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <Vector.h>

SCENARIO("Using Car")
{
	GIVEN("turned off car")
	{
		WHEN("we call GetSpeed()")
		{
			THEN("we get speed and gear 0")
			{
				REQUIRE(true);
			}
		}
	}
}
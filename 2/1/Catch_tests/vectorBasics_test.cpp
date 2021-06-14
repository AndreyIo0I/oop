#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/vectorBasics.h"

SCENARIO("Basics of work with vector")
{
	std::ostringstream output;

	GIVEN("an empty vector")
	{
		std::istringstream input;
		WHEN("GetSortedModifiedVector is called")
		{
			GetSortedModifiedVector(input, output);

			THEN("output is empty")
			{
				CHECK(output.str().empty());
			}
		}
	}

    GIVEN("a vector with some items")
    {
		std::istringstream input("1.2 3.2 2.2 -7");
        WHEN("GetSortedModifiedVector is called")
        {
			GetSortedModifiedVector(input, output);

            THEN("items increased on the mean of the positive elements")
            {
                CHECK(output.str() == "-4.8 3.4 4.4 5.4\n");
            }
        }
    }
}
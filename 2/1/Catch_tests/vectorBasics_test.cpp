#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/vectorBasics.h"

SCENARIO("Basics of work with vector")
{
    GIVEN("a vector with some items")
    {
        std::vector<float> v = { 1.00, 3.00, 2.00 };
		std::vector<float> v2 = { 3.00, 5.00, 4.00 };
        WHEN("addMeanOfPositiveElements(vector) is called")
        {
            addMeanOfPositiveElements(v);

            THEN("the v items increase on the mean of the positive elements")
            {
                REQUIRE(v == v2);
            }
        }
    }

    GIVEN("an empty vector")
    {
        std::vector<float> v = {};
        std::vector<float> v2 = {};
        WHEN("addMeanOfPositiveElements(vector) is called")
        {
            addMeanOfPositiveElements(v);

            THEN("vector is still empty")
            {
                REQUIRE(v == v2);
            }
        }
    }
}
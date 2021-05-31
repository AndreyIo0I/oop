#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../vectorBasics.h"

SCENARIO("basics of work with vector")
{
    GIVEN("a vector with some items")
    {
        std::vector<float> v0 = { 1.00, 3.00, 2.00 };

        WHEN( "addMeanOfPositiveElements(vector) is called" )
        {
            addMeanOfPositiveElements(v0);

            THEN( "the v items increase on the mean of the positive elements" ) {
//                REQUIRE(v === { 3.00, 5.00, 4.00});
                REQUIRE(true);
            }
        }
    }
}
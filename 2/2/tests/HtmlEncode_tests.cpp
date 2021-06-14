#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/HtmlEncode.h"

SCENARIO("HtmlEncode")
{
    GIVEN("an empty string")
    {
        std::string emptyString;
        WHEN("given \"\"")
        {
			std::string result = HtmlEncode(emptyString);

            THEN("result is empty too")
            {
                REQUIRE(emptyString == result);
            }
        }
    }

    GIVEN("string with special symbols")
    {
        std::string inputString = "\" a ` b < c >d&` e";
        WHEN("HtmlEncode is called")
        {
			std::string resultString = HtmlEncode(inputString);

            THEN("encoded string returned")
            {
                REQUIRE(resultString == "&quot; a &apos; b &lt; c &gt;d&amp;&apos; e");
            }
        }
    }
}
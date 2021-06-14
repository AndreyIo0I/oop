#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/CountWordOccurrences.h"

SCENARIO("HtmlEncode")
{
	std::ostringstream output;
    GIVEN("an empty string")
    {
		std::istringstream input("");
        WHEN("given \"\"")
        {
        	THEN("result is empty too")
            {
				CountWordOccurrences(input, output);
                CHECK(output.str().empty());
				CHECK(output.eof());
            }
        }
    }

    GIVEN("string with some words")
    {
		std::istringstream input("1 line\n2 line");
        WHEN("CountWordOccurrences is called")
        {
            THEN("words are counted right")
            {
				CountWordOccurrences(input, output);
				CHECK(output.str() == "1 -> 1\n2 -> 1\nline -> 2\n");
				CHECK(output.eof());
            }
        }
    }
}
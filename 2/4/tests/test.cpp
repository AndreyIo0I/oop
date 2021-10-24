#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/PrimeNumbers.h"

TEST_CASE("getPrimeNumbers")
{
	SECTION("get one prime number")
	{
		std::set<int> set1 = {2};
		CHECK(getPrimeNumbers(2) == set1);
	}

	SECTION("get some prime numbers")
	{
		std::set<int> set2 = {2, 3, 5, 7};
		CHECK(getPrimeNumbers(9) == set2);
	}

	SECTION("get a lot of prime numbers")
	{
		CHECK(getPrimeNumbers(100000000).size() == 5761455);
	}
}

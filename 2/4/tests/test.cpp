#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/PrimeNumbers.h"

TEST_CASE("getPrimeNumbers")
{
	std::set<int> set1 = {2};
	CHECK(getPrimeNumbers(2) == set1);
	std::set<int> set2 = {2, 3, 5, 7};
	CHECK(getPrimeNumbers(9) == set2);
	CHECK(getPrimeNumbers(100000000).size() == 5761455);
}

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <FindMax.h>

using namespace std;

struct Sportsman
{
	string name;
	float height;
	float weight;
};

TEST_CASE("FindMax usage")
{
	SECTION("empty vector")
	{
		vector<Sportsman> v;
		Sportsman sportsman {"Name 1", 1, 2};
		CHECK(!FindMax(v, sportsman, [](const Sportsman& a, const Sportsman& b){return a.height < b.height;}));
	}

	SECTION("find max height sportsman")
	{
		vector<Sportsman> v = {
			{"Name 2", 2, 4},
			{"Name 3", 3, 6},
			{"Name 4", 4, 8},
		};
		Sportsman sportsman {"Name 1", 1, 2};
		v.push_back(sportsman);
		CHECK(FindMax(v, sportsman, [](const Sportsman& a, const Sportsman& b){return a.height < b.height;}));
		CHECK(sportsman.height == 4);
	}

	SECTION("find max weight sportsman")
	{
		vector<Sportsman> v = {
			{"Name 2", 2, 8},
			{"Name 3", 3, 6},
			{"Name 4", 4, 4},
		};
		Sportsman sportsman {"Name 1", 1, 2};
		CHECK(FindMax(v, sportsman, [](const Sportsman& a, const Sportsman& b){return a.weight < b.weight;}));
		CHECK(sportsman.weight == 8);
	}
}

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <FindMax.h>

using namespace std;

struct Sportsman
{
	string name = "Name 0";
	float height = 0;
	float weight = 0;
	bool operator==(const Sportsman& a) const {
		return name == a.name && height == a.height && weight == a.weight;
	}
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
		Sportsman sportsman;
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
		Sportsman sportsman;
		CHECK(FindMax(v, sportsman, [](const Sportsman& a, const Sportsman& b){return a.weight < b.weight;}));
		CHECK(sportsman.weight == 8);
	}

	SECTION("test exception safety")
	{
		vector<Sportsman> v = {
			{"Name 2", 2, 8},
			{"Name 3", 3, 6},
			{"Name 4", 4, 4},
		};
		vector<Sportsman> vCopy;
		copy(v.begin(), v.end(), back_inserter(vCopy));
		Sportsman sportsman;
		bool throwError = false;
		try
		{
			FindMax(v, sportsman, [&throwError](const Sportsman& a, const Sportsman& b){
				if (throwError)
					throw logic_error("expected error");
				throwError = true;
				return a.weight < b.weight;
			});
		}
		catch (...)
		{
			CHECK(equal(v.begin(), v.end(), vCopy.begin()));
		}
	}
}

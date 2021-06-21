#include <TVSet.h>
#include <RemoteControl.h>
#include "catch.hpp"

using namespace std;

SCENARIO("Using RemoteControl")
{
	CTVSet tv;
	istringstream input("Info");
	ostringstream output("");
	CRemoteControl remoteControl(tv, input, output);

	GIVEN("remoteControl with a new tv")
	{
		WHEN("we type Info")
		{
			THEN("tv is turned off")
			{
				REQUIRE(output.str() == "TV is turned off\n");
			}
		}
	}
}
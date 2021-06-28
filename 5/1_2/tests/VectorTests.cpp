#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <Vector.h>

SCENARIO("Using CVector3D")
{
	GIVEN("new vector()")
	{
		CVector3D v;
		WHEN("we check vector")
		{
			THEN("we 0 vector")
			{
				CHECK(v.GetLength() == 0);
				CHECK((v.x == 0 && v.y == 0 && v.z == 0));
			}
		}
	}

	GIVEN("new vector(11, 5, 1)")
	{
		CVector3D v(11, 5, 1);
		WHEN("we check vector")
		{
			THEN("we get vector(11, 5, 1)")
			{
				CHECK(v.GetLength() == 12.1244);
				CHECK((v.x == 11 && v.y == 5 && v.z == 1));
			}
		}
	}
}
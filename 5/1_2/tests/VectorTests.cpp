#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <Vector.h>

SCENARIO("Using CVector3D")
{
	GIVEN("new vector")
	{
		CVector3D v;
		WHEN("we check vector")
		{
			THEN("we have 0 vector")
			{
				CHECK(v.GetLength() == 0);
				CHECK((v.x == 0 && v.y == 0 && v.z == 0));
			}
		}
	}

	GIVEN("two vectors(11, 5, 1) v and v2")
	{
		CVector3D v(11, 5, 1);
		WHEN("we check vector")
		{
			THEN("we get vector(11, 5, 1)")
			{
				CHECK((v.x == 11 && v.y == 5 && v.z == 1));
			}

			THEN("we get Length == 12.124355653")
			{
				CHECK(v.GetLength() == 12.124355653);
			}
		}
	}

	GIVEN("CVector3D operators")
	{
		WHEN("we check operator==")
		{
			THEN("(11, 5, 1) == (11, 5, 1)")
			{
				CHECK(CVector3D(11, 5, 1) == CVector3D(11, 5, 1));
			}

			THEN("(11, 5, 1) != (11, 5, 2)")
			{
				CHECK(CVector3D(11, 5, 1) != CVector3D(11, 5, 2));
			}
		}
	}
}
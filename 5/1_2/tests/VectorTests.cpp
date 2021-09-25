#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <iostream>
#include <Vector.h>

SCENARIO("Using CVector3D") // todo убрать названия переменных и значения из описаний
{
	WHEN("we create empty vector")
	{
		CVector3D v;
		THEN("vector length = 0")
		{
			CHECK(v.GetLength() == 0);
			CHECK((v.x == 0 && v.y == 0 && v.z == 0));
		}
	}

	GIVEN("v1 and v2")
	{
		CVector3D v1(28, 41, 64);
		CVector3D v2(1, 2, 2);

		WHEN("we get vector length")
		{
			THEN("length is correct")
			{
				CHECK(v1.GetLength() == 81);
			}
		}

		WHEN("we get +vector")
		{
			THEN("vector didn't change")
			{
				CVector3D v3 = +v1;
				CHECK((v1.x == v3.x && v1.y == v3.y && v1.z == v3.z));
			}
		}

		WHEN("we get -vector")
		{
			THEN("new vector is negative")
			{
				CVector3D v3 = -v1;
				CHECK((v1.x == -v3.x && v1.y == -v3.y && v1.z == -v3.z));
			}
		}

		WHEN("we check equality")
		{
			THEN("same vectors are equals")
			{
				CHECK(CVector3D(28, 41, 64) == CVector3D(28, 41, 64));
			}

			THEN("different vectors aren't equals")
			{
				CHECK(!(CVector3D(28, 41, 64) == CVector3D(11, 5, 2)));
			}
		}

		WHEN("we check inequality")
		{
			THEN("different vectors aren't equals")
			{
				CHECK(CVector3D(28, 41, 64) != CVector3D(11, 5, 2));
			}

			THEN("same vectors are equals")
			{
				CHECK(!(CVector3D(28, 41, 64) != CVector3D(28, 41, 64)));
			}
		}

		WHEN("we check +=")
		{
			THEN("left vector is large")
			{
				v2 += v1;
				CHECK(v2.GetLength() == 84);
			}
		}

		WHEN("we check -=")
		{
			THEN("left vector is smaller")
			{
				v2 -= v1;
				CHECK(v2.GetLength() == 78);
			}
		}

		WHEN("we check *")
		{
			THEN("vector * int == ") {
				CHECK(CVector3D(1, 2, 2) * 2 == CVector3D(2, 4, 4));
			}

			THEN("2 * (1, 2, 2) == (2, 4, 4)") {
				CHECK(2 * CVector3D(1, 2, 2) == CVector3D(2, 4, 4));
			}
		}

		WHEN("we check /")
		{
			THEN("(2, 4, 4) / 2 == (1, 2, 2)") {
				CHECK(CVector3D(2, 4, 4) / 2 == CVector3D(1, 2, 2));
			}
		}

		WHEN("we check *=")
		{
			THEN ("(1, 2, 3) *= 3 -> (3, 6, 9)") {
				CVector3D v3(1, 2, 3);
				v3 *= 3;
				CHECK(v3 == CVector3D(3, 6, 9));
			}
		}

		WHEN("we check /=")
		{
			THEN ("(3, 6, 9) /= 3 -> (1, 2, 3)") {
				CVector3D v3(3, 6, 9);
				v3 /= 3;
				CHECK(v3 == CVector3D(1, 2, 3));
			}
		}

		WHEN("we check <<")
		{
			std::ostringstream output;
			output << CVector3D(1, 2, 5);
			THEN ("") {
				CHECK(output.str() == "1, 2, 5");
			}
		}

		WHEN("we check >>")
		{
			CVector3D v3;
			std::istringstream input("1, 2, 5");
			input >> v3;
			THEN ("") {
				CHECK(v3 == CVector3D(1, 2, 5));
			}
		}

		WHEN("we check Normalize()")
		{
			THEN ("Normalize(1, 2, 3).length == 1")
			{
				CHECK(Normalize(CVector3D(1, 2, 3)).GetLength() == 1);
			}
		}

		WHEN("we check Normalize()")
		{
			THEN ("Normalize(1, 2, 3).length == 1")
			{
				CHECK(Normalize(CVector3D(1, 2, 3)).GetLength() == 1);
			}
		}

		WHEN("we check DotProduct()")
		{
			THEN ("DotProduct((1, 2, 3), (0, 4, -5)) == -7")
			{
				CHECK(DotProduct(CVector3D(1, 2, 3), CVector3D(0, 4, -5)) == -7);
			}
		}

		WHEN("we check CrossProduct()")
		{
			THEN ("CrossProduct((1, 2, 3), (4, 5, 6)) == (-3, 6, -3)")
			{
				CHECK(CrossProduct(CVector3D(1, 2, 3), CVector3D(4, 5, 6)) == CVector3D(-3, 6, -3));
			}
		}
	}
}

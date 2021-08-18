#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <Vector.h>
#include <iostream>

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

	GIVEN("v1(28, 41, 64) and v2(1, 2, 2)")
	{
		CVector3D v1(28, 41, 64);
		CVector3D v2(1, 2, 2);

		WHEN("we check vector length")
		{
			THEN("v1(28, 41, 64).GetLength() = 81")
			{
				CHECK(v1.GetLength() == 81);
			}
		}

		WHEN("we check +v")
		{
			THEN("+(28, 41, 64) == (28, 41, 64)")
			{
				CVector3D v3 = +v1;
				CHECK((v1.x == v3.x && v1.y == v3.y && v1.z == v3.z));
			}
		}

		WHEN("we check -v")
		{
			THEN("-(28, 41, 64) == (-28, -41, -64)")
			{
				CVector3D v3 = -v1;
				CHECK((v1.x == -v3.x && v1.y == -v3.y && v1.z == -v3.z));
			}
		}

		WHEN("we check operator==")
		{
			THEN("(28, 41, 64) == (28, 41, 64) -> true")
			{
				CHECK(CVector3D(28, 41, 64) == CVector3D(28, 41, 64));
			}

			THEN("(28, 41, 64) == (11, 5, 2) -> false")
			{
				CHECK(!(CVector3D(28, 41, 64) == CVector3D(11, 5, 2)));
			}
		}

		WHEN("we check !=")
		{
			THEN("(28, 41, 64) != (11, 5, 2) -> true")
			{
				CHECK(CVector3D(28, 41, 64) != CVector3D(11, 5, 2));
			}

			THEN("(28, 41, 64) != (28, 41, 64) -> false")
			{
				CHECK(!(CVector3D(28, 41, 64) != CVector3D(28, 41, 64)));
			}
		}

		WHEN("we check +=")
		{
			THEN("(v2 + v1).GetLength() == 84")
			{
				v2 += v1;
				CHECK(v2.GetLength() == 84);
			}
		}

		WHEN("we check -=")
		{
			THEN("(v2 - v1).GetLength() == 78")
			{
				v2 -= v1;
				CHECK(v2.GetLength() == 78);
			}
		}

		WHEN("we check *")
		{
			THEN("(1, 2, 2) * 2 == (2, 4, 4)") {
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
			THEN ("Normalize(1, 2, 3).length == 1") {
				CHECK(CVector3D::Normalize({1, 2, 3}).GetLength() == 1);
			}
		}

		WHEN("we check Normalize()")
		{
			THEN ("Normalize(1, 2, 3).length == 1") {
				CHECK(CVector3D::Normalize({1, 2, 3}).GetLength() == 1);
			}
		}

		WHEN("we check DotProduct()")
		{
			THEN ("DotProduct((1, 2, 3), (0, 4, -5)) == -7") {
				CHECK(CVector3D::DotProduct({1, 2, 3}, {0, 4, -5}) == -7);
			}
		}

		WHEN("we check CrossProduct()")
		{
			THEN ("CrossProduct((1, 2, 3), (4, 5, 6)) == (-3, 6, -3)") {
				CHECK(CVector3D::CrossProduct({1, 2, 3}, {4, 5, 6}) == CVector3D(-3, 6, -3));
			}
		}
	}
}

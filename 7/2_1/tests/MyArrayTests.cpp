#define CATCH_CONFIG_MAIN

#include "CMyArray.h"
#include "catch.hpp"

using namespace std;

TEST_CASE("Using MyArray")
{
	SECTION("empty array")
	{
		CMyArray<string> arr;
		CHECK(arr.GetSize() == 0);
		CHECK(arr.GetCapacity() == 0);
	}

	SECTION("array append")
	{
		CMyArray<double> arr;
		arr.Append(3.1);
		CHECK(arr.GetSize() == 1);
		CHECK(arr[0] == 3.1);
		CHECK_THROWS_AS(arr[1], std::out_of_range);
		CHECK_THROWS_AS(arr[-1], std::out_of_range);
	}

	SECTION("array resize")
	{
		CMyArray<double> arr;
		arr.Resize(20);
		arr[1] = 4;
		CHECK(arr.GetSize() == 20);
		CHECK(arr[10] == 0);
		arr.Resize(2);
		CHECK(arr[1] == 4);
		CHECK(arr.GetSize() == 2);

		CHECK_THROWS_AS(arr[10], std::out_of_range);
	}

	SECTION("array copy")
	{
		CMyArray<double> arr;
		arr.Append(1);
		arr.Append(2);
		CMyArray<double> arr2(arr);
		CHECK(arr2.GetSize() == 2);
		CHECK((arr2[0] == 1 && arr2[1] == 2));
	}

	SECTION("array assignment operator")
	{
		CMyArray<double> arr;
		arr.Append(1);
		arr.Append(2);
		CMyArray<double> arr2;
		arr2 = arr;
		CHECK(arr2.GetSize() == 2);
		CHECK((arr2[0] == 1 && arr2[1] == 2));
	}

	SECTION("array clear")
	{
		CMyArray<double> arr;
		arr.Append(1);
		arr.Append(2);
		CHECK(arr.GetSize() == 2);
		arr.Clear();
		CHECK(arr.GetSize() == 0);
	}

	SECTION("array iterators")
	{
		CMyArray<string> arr;
		arr.Append("123");
		arr.Append("45");
		arr.Append("f");
		CHECK(*arr.begin() == "123");
		CHECK(*--arr.end() == "f");
		CHECK(*(1 + arr.begin()) == "45");
	}
}

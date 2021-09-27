#pragma once
#include <vector>

using namespace std;

template <typename T, typename Less>
bool FindMax(const vector<T>& arr, T& maxValue, const Less& less)
{
	if (arr.empty())
		return false;

	auto maxPtr = arr.begin();
	for (auto i = arr.begin(); i != arr.end(); ++i)
		if(less(*maxPtr, *i))
			maxPtr = i;

	maxValue = *maxPtr;
	return true;
}

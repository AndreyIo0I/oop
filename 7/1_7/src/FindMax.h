#pragma once
#include <vector>

using namespace std;

template <typename T, typename Less>
bool FindMax(const vector<T>& arr, T& maxValue, const Less& less)
{
	if (arr.empty())
		return false;

	auto maxIter = arr.begin();
	for (auto i = arr.begin(); i != arr.end(); ++i)
		if(less(*maxIter, *i))
			maxIter = i;

	maxValue = *maxIter;
	return true;
}

#include "CMyArray.h"
#include <iostream>

int main()
{
	CMyArray<int> arr;
	arr.Append(3);
	arr.Append(1);
	arr.Append(2);
	for (int val : arr)
	{
		std::cout << val << '\n';
	}
	return 0;
}
#include "CMyArray.h"
#include <iostream>

using namespace std;

int main()
{
	CMyArray<int> arr;
	arr.Append(1);
	cout << arr[1] << '\n';
	return 0;
}
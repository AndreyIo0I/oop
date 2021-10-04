#include "CMyArray.h"
#include <iostream>

using namespace std;

int main()
{
	CMyArray<int> arr;
	arr.Append(1);
	try
	{
		cout << arr[0] << '\n';
		cout << arr[1] << '\n';
	}
	catch (exception& e)
	{
		cout << e.what();
	}
	return 0;
}
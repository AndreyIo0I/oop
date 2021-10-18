#include "CMyArray.h"
#include <iostream>

using namespace std;

int main()
{
	CMyArray<double> arr;
	arr.Resize(2);
	cout << arr[0] << endl;
	return 0;
}
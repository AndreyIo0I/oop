#include <iostream>
#include "src/HtmlEncode.h"

using namespace std;

int main()
{
	string line;

	while (getline(cin, line))
		cout << HtmlEncode(line) << '\n';

    return 0;
}
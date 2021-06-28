#include <Car.h>
#include <ConsoleControl.h>
#include <iostream>

using namespace std;

int main()
{
	CCar car;
	CConsoleControl consoleControl(car, cin, cout);

	while (!cin.eof() && !cin.fail())
	{
		cout << "> ";
		if (!consoleControl.HandleCommand())
		{
			cout << "Unknown command!" << endl;
		}
	}

	return 0;
}
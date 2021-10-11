#include <iostream>
#include <windows.h>
#include "src/Dictionary.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "Передайте только название файла\n";
		return 0;
	}
	string filename = argv[1];
	Dictionary dictionary(filename);
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	dictionary.Run(cin, cout);
    return 0;
}
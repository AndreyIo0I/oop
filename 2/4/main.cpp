#include <iostream>
#include "src/PrimeNumbers.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << "specify upper bound\n";
		return 0;
	}
	auto upperBound = GetUpperBound(argv[1]);

	if (upperBound)
	{
		set<int> primes = GetPrimeNumbers(*upperBound);
		cout << primes.size() << endl;
	}
    return 0;
}
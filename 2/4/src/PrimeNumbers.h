#pragma once

#include <optional>
#include <string>
#include <set>
#include <vector>

std::optional<int> GetUpperBound(const std::string& str)
{
	int upperBound = 0;
	try
	{
		upperBound = stoi(str);
	}
	catch (...)
	{
		std::cout << "parameter must be a number\n";
		return std::nullopt;
	}
	if (upperBound < 2 || upperBound > 10e8)
	{
		std::cout << "parameter must be between 1 and 10e8\n";
		return std::nullopt;
	}
	return upperBound;
}

std::set<int> GetPrimeNumbers(int upperBound)
{
	std::set<int> primeNumbers;

	if (upperBound > 1) {
		std::vector<bool> sieve(upperBound + 1, true);

		for (int i = 2; i <= upperBound; ++i)
		{
			if (sieve[i])
				for (int j = i + i; j <= upperBound; j += i)
					sieve[j] = false;
		}

		for (int i = 2; i <= upperBound; ++i)
			if (sieve[i])
				primeNumbers.insert(i);
	}

	return primeNumbers;
}

#pragma once
#include <stdexcept>

using namespace std;

class CUrlParsingError: public invalid_argument
{
public:
	explicit CUrlParsingError(const string&);
};

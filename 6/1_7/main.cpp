#include <CHttpUrl.h>
#include <CUrlParsingError.h>
#include <iostream>

using namespace std;

int main()
{
	string url;
	while (cin >> url)
	{
		cout << GetUrlInfo(url);
	}
	return 0;
}
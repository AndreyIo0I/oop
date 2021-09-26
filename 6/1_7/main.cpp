#include <CHttpUrl.h>
#include <CUrlParsingError.h>
#include <iostream>

using namespace std;

string GetUrlInfo(const string& urlStr) {
	string info = "protocol: ";
	try
	{
		auto url = CHttpUrl(urlStr);
		url.GetProtocol() == Protocol::HTTP
		? info += "http://\n"
		: info += "https://\n";
		info += "domain: " + url.GetDomain() + "\n";
		info += "port: " + to_string(url.GetPort()) + "\n";
		info += "document: " + url.GetDocument() + "\n";
	}
	catch (const CUrlParsingError& error)
	{
		info = error.what();
	}
	return info;
}

int main()
{
	string url;
	while (cin >> url)
	{
		cout << GetUrlInfo(url);
	}
	return 0;
}
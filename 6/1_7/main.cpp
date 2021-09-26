#include <CHttpUrl.h>
#include <CUrlParsingError.h>
#include <iostream>

using namespace std;

string GetUrlInfo(const CHttpUrl& url) {
	string info = "protocol: ";
	url.GetProtocol() == Protocol::HTTP
		? info += "http://\n"
		: info += "https://\n";
	info += "domain: " + url.GetDomain() + "\n";
	info += "port: " + to_string(url.GetPort()) + "\n";
	info += "document: " + url.GetDocument() + "\n";
	return info;
}

int main()
{
	string url;
	while (cin >> url)
	{
		try
		{
			cout << GetUrlInfo(CHttpUrl(url));
		}
		catch (const CUrlParsingError& error){
			cout << error.what();
			continue;
		}
	}
	return 0;
}
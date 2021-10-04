#include "CHttpUrl.h"
#include "CUrlParsingError.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;
CHttpUrl::CHttpUrl(const string& url)
{
	string lowerUrl;
	transform(url.begin(), url.end(), back_inserter(lowerUrl), [](unsigned char c){ return tolower(c); });
	size_t pos = 0;
	pos = ParseProtocol(lowerUrl);
	pos = ParseDomain(lowerUrl, pos);

	if (pos < lowerUrl.size())
	{
		if (lowerUrl[pos] == ':')
		{
			++pos;
			pos = ParsePort(lowerUrl, pos);
		}

		if (pos < lowerUrl.size())
		{
			ParseDocument(lowerUrl, pos);
		}
	}
	ConstructUrl(m_protocol, m_domain, m_port, m_document);
}

CHttpUrl::CHttpUrl(const string& domain, const string& document, Protocol protocol)
{
	string url = protocol == Protocol::HTTP
		? "http://"
		: "https://";
	url += domain;
	if (document[0] != '/')
		url += '/';
	url += document;
	*this = CHttpUrl(url);
}

CHttpUrl::CHttpUrl(const string& domain, const string& document, Protocol protocol, unsigned short port)
: CHttpUrl(domain + ":" + to_string(port), document, protocol)
{
}

string CHttpUrl::GetURL() const {
    return m_url;
}

Protocol CHttpUrl::GetProtocol() const {
	return m_protocol;
}

string CHttpUrl::GetDomain() const {
    return m_domain;
}

unsigned short CHttpUrl::GetPort() const {
	return m_port;
}

string CHttpUrl::GetDocument() const {
    return m_document;
}

size_t CHttpUrl::ParseProtocol(const string& url)
{
	string httpString = "http://";
	if (url.find(httpString) == 0)
	{
		m_protocol = Protocol::HTTP;
		return httpString.size();
	}
	string httpsString = "https://";
	if (url.find(httpsString) == 0)
	{
		m_protocol = Protocol::HTTPS;
		return 8;
	}
	throw CUrlParsingError("Invalid protocol, use 'http://' or 'https://'\n");
}

size_t CHttpUrl::ParseDomain(const string& url, size_t pos)
{
	int domainEndPos = url.find_first_of(":/", pos);
	m_domain = domainEndPos > 0 ? url.substr(pos, domainEndPos - pos) : url.substr(pos);
	if (m_domain.empty())
	{
		throw CUrlParsingError("Domain can't be empty\n");
	}
	pos += m_domain.size();

	return pos;
}

size_t CHttpUrl::ParsePort(const string& url, size_t pos)
{
	int portEndPos = url.find_first_of('/', pos);
	string portStr = portEndPos > 0 ? url.substr(pos, portEndPos - pos) : url.substr(pos);
	int newPort;
	try
	{
		newPort = stoi(portStr);
	}
	catch (...)
	{
		throw CUrlParsingError("Invalid port\n");
	}
	if (newPort < 0)
		throw CUrlParsingError("Port mustn't be negative\n");
	if (newPort > USHRT_MAX)
		throw CUrlParsingError("Port mustn't be bigger then " + to_string(USHRT_MAX) + '\n');
	m_port = newPort;
	pos += portStr.size();

	return pos;
}

void CHttpUrl::ParseDocument(const string& url, size_t pos)
{
	m_document = url.substr(pos);
	if (m_document.empty())
		m_document = "/";
}

void CHttpUrl::ConstructUrl(Protocol protocol, const string& domain, size_t port, string& document)
{
	m_url = protocol == Protocol::HTTP
		? "http://"
		: "https://";
	m_url += domain;
	if (!((port == 80 && protocol == Protocol::HTTP) || (port == 443 && protocol == Protocol::HTTPS)))
	{
		m_url += ":" + to_string(port);
	}
	m_url += document;
}

string GetUrlInfo(const string& urlStr)
{
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
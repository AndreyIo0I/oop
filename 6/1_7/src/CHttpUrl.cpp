#include "CHttpUrl.h"
#include "CUrlParsingError.h"
#include <iostream>
#include <string>

using namespace std;

CHttpUrl::CHttpUrl(const string& url)
{
	size_t pos = 0;
	ParseProtocol(url, pos);
	ParseDomain(url, pos);

	if (pos < url.size())
	{
		if (url[pos] == ':')
		{
			++pos;
			ParsePort(url, pos);
		}

		if (pos < url.size())
		{
			ParseDocument(url, pos);
		}
	}
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

void CHttpUrl::ParseProtocol(const string& url, size_t& pos)
{
	if (url.find("http://") == 0)
	{
		pos = 7;
		m_port = 80;
		m_protocol = Protocol::HTTP;
		m_url = "http://";
	}
	else if (url.find("https://") == 0)
	{
		pos = 8;
		m_port = 443;
		m_protocol = Protocol::HTTPS;
		m_url = "https://";
	}
	else
	{
		throw CUrlParsingError("Invalid protocol, use 'http://' or 'https://'\n");
	}
}

void CHttpUrl::ParseDomain(const string& url, size_t& pos)
{
	size_t domainEndPos = url.find_first_of(":/", pos);
	m_domain = domainEndPos > 0 ? url.substr(pos, domainEndPos - pos) : url.substr(pos);
	if (m_domain.empty())
	{
		throw CUrlParsingError("Domain can't be empty\n");
	}
	m_url += m_domain;
	pos += m_domain.size();

	m_document = "/";
}

void CHttpUrl::ParsePort(const string& url, size_t& pos)
{
	size_t portEndPos = url.find_first_of('/', pos);
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

	if (!((m_port == 80 && m_protocol == Protocol::HTTP) || (m_port == 443 && m_protocol == Protocol::HTTPS)))
	{
		m_url += ":" + portStr;
	}
}

void CHttpUrl::ParseDocument(const string& url, size_t& pos)
{
	m_document = url.substr(pos);
	m_url += m_document;
}

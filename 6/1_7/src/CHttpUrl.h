#pragma once
#include <string>

using namespace std;

enum class Protocol
{
    HTTP,
    HTTPS
};

class CHttpUrl
{
public:
    explicit CHttpUrl(string const&);
    CHttpUrl(string const& domain, string const& document, Protocol protocol = Protocol::HTTP);
    CHttpUrl(string const& domain, string const& document, Protocol protocol, unsigned short port);

	Protocol GetProtocol() const;
	string GetDomain() const;
	unsigned short GetPort() const;
	string GetDocument() const;
	string GetURL() const;

private:
	void ParseProtocol(string const&, size_t&);
	void ParseDomain(string const&, size_t&);
	void ParsePort(string const&, size_t&);
	void ParseDocument(string const&, size_t&);

    string m_url, m_domain, m_document;
    Protocol m_protocol;
    unsigned short m_port;
};

string GetUrlInfo(const string&);
#pragma once
#include <string>

enum class Protocol
{
    HTTP,
    HTTPS
};

class CHttpUrl
{
public:
    CHttpUrl(std::string const&);
    CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol = Protocol::HTTP);
    CHttpUrl(std::string const& domain, std::string const& document, Protocol protocol, unsigned short port);

	Protocol GetProtocol() const;
	std::string GetDomain() const;
	unsigned short GetPort() const;
	std::string GetDocument() const;
	std::string GetURL() const;

private:
	size_t ParseProtocol(std::string const& url);
	size_t ParseDomain(std::string const& url, size_t pos);
	size_t ParsePort(std::string const& url, size_t pos);
	void ParseDocument(std::string const& url, size_t pos);
	void ConstructUrl(Protocol protocol, const std::string& domain, size_t port, std::string& document);

	std::string m_url, m_domain, m_document;
    Protocol m_protocol = Protocol::HTTP;
    unsigned short m_port = 0;
};

std::string GetUrlInfo(const std::string&);
#include <string>
#include "CHttpUrl.h"

CHttpUrl::CHttpUrl(const string &url)
{
}

CHttpUrl::CHttpUrl(const string &domain, const string &document, Protocol protocol)
{
}

CHttpUrl::CHttpUrl(const string &domain, const string &document, Protocol protocol, unsigned short port)
{
}

string CHttpUrl::GetURL() const {
    return m_url;
}

string CHttpUrl::GetDomain() const {
    return m_domain;
}

string CHttpUrl::GetDocument() const {
    return m_document;
}

Protocol CHttpUrl::GetProtocol() const {
    return m_protocol;
}

unsigned short CHttpUrl::GetPort() const {
    return m_port;
}

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/ParseURL.h"

TEST_CASE("parse url")
{
	int port;
	std::string host;
	std::string document;
	Protocol protocol;

	SECTION("invalid urls")
	{
		CHECK(!ParseURL("132", protocol, port, host, document));
		CHECK(!ParseURL("http:/github.com", protocol, port, host, document));
		CHECK(!ParseURL("https://", protocol, port, host, document));
		CHECK(!ParseURL("https://github.com:65536", protocol, port, host, document));
		CHECK(!ParseURL("https://github.com:0", protocol, port, host, document));
	}

	SECTION("valid urls")
	{
		CHECK((ParseURL("https://github.com:65535", protocol, port, host, document)
			&& protocol == Protocol::HTTPS
			&& port == 65535
			&& host == "github.com"
			&& document.empty()));

		CHECK((ParseURL("ftp://123/321", protocol, port, host, document)
			   && protocol == Protocol::FTP
			   && port == 21
			   && host == "123"
			   && document == "321"));

		CHECK((ParseURL("http://123", protocol, port, host, document)
			   && protocol == Protocol::HTTP
			   && port == 80
			   && host == "123"
			   && document.empty()));

		CHECK((ParseURL("hTtP://123", protocol, port, host, document)
			   && protocol == Protocol::HTTP
			   && port == 80
			   && host == "123"
			   && document.empty()));

		CHECK((ParseURL("https://123", protocol, port, host, document)
			   && protocol == Protocol::HTTPS
			   && port == 443
			   && host == "123"
			   && document.empty()));
	}
}

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include <CHttpUrl.h>

SCENARIO("Parsing urls")
{
	WHEN("url is empty")
	{
		THEN("protocol not detected")
		{
			CHECK(GetUrlInfo("") == "Invalid protocol, use 'http://' or 'https://'\n");
		}
	}
	WHEN("protocol isn't http or https")
	{
		THEN("protocol not detected")
		{
			CHECK(GetUrlInfo("ftp://") == "Invalid protocol, use 'http://' or 'https://'\n");
		}
	}
	WHEN("protocol is incorrect")
	{
		THEN("protocol not detected")
		{
			CHECK(GetUrlInfo("(^&@9g21") == "Invalid protocol, use 'http://' or 'https://'\n");
		}
	}
	WHEN("domain is empty")
	{
		THEN("domain is empty error appear")
		{
			CHECK(GetUrlInfo("https:///123") == "Domain can't be empty\n");
			CHECK(GetUrlInfo("http://") == "Domain can't be empty\n");
		}
	}
	WHEN("port incorrect")
	{
		THEN("correct error appear")
		{
			CHECK(GetUrlInfo("https://habr.com:qwerty/ru/post/437836/") == "Invalid port\n");
			CHECK(GetUrlInfo("https://habr.com:-2/ru/post/437836/") == "Port mustn't be negative\n");
			CHECK(GetUrlInfo("https://habr.com:65536/ru/post/437836/") == "Port mustn't be bigger then 65535\n");
		}
	}
	WHEN("url is correct")
	{
		THEN("info is correct")
		{
			CHECK(GetUrlInfo("HTTPS://habr.com:3000/ru/post/437836/") == "protocol: https://\n"
																	"domain: habr.com\n"
																	"port: 3000\n"
																	"document: /ru/post/437836/\n");
		}
	}
	WHEN("url is correct and specified port is default")
	{
		THEN("specified port invisible")
		{
			CHECK(CHttpUrl("https://habr.com:443/ru/post/437836/").GetURL() == "https://habr.com/ru/post/437836/");
			CHECK(CHttpUrl("http://habr.com:80/ru/post/437836/").GetURL() == "http://habr.com/ru/post/437836/");
		}
	}
}

#pragma once

#include <optional>
#include <string>
#include <regex>

enum class Protocol
{
	HTTP,
	HTTPS,
	FTP
};

Protocol DefineProtocol(const std::string& protocol)
{
	if (protocol == "http")
		return Protocol::HTTP;
	else if (protocol == "https")
		return Protocol::HTTPS;
	else
		return Protocol::FTP;
}

int DefinePort(const std::string& port, const Protocol protocol)
{
	if (port.empty())
	{
		if (protocol == Protocol::HTTP)
			return 80;
		else if (protocol == Protocol::HTTPS)
			return 443;
		else
			return 21;
	}

	try
	{
		return std::stoi(port);
	}
	catch (...)
	{
		return -1;
	}
}

//  протокол://хост[:порт][/документ]
bool ParseURL(const std::string& url, Protocol&  protocol, int& port, std::string& host, std::string& document)
{
	std::string lowerUrl;
	std::transform(url.begin(), url.end(), std::back_inserter(lowerUrl), tolower);

	std::regex reg(R"(^(http|https|ftp):\/\/([^\:\/]+)(?::(\d+))?(?:\/(\S*))?$)");
	std::smatch result;
	if (!regex_search(lowerUrl, result, reg))
		return false;

	protocol = DefineProtocol(result[1].str());
	host = result[2].str();
	port = DefinePort(result[3].str(), protocol);

	if (port < 1 || port > 65535)
		return false;

	document = result[4].str();

	return true;
}

void PrintUrls(std::istream& input, std::ostream& output)
{
	std::string url;
	while (getline(input, url))
	{
		int port;
		std::string host;
		std::string document;
		Protocol protocol;

		if (!ParseURL(url, protocol, port, host, document))
			output << "!invalid url!\n";
		else
			output << url << '\n'
				<< "HOST: " << host << '\n'
				<< "PORT: " << port << '\n'
				<< "DOC: " << document << '\n';
	}
}
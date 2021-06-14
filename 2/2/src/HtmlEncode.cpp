#include <iostream>
#include <string>

using namespace std;

string HtmlEncode(const std::string & text)
{
	string encodedText;
	encodedText.reserve(text.length() * 2);

	for (auto ch : text)
	{
		switch (ch) {
			case '"':
				encodedText.append("&quot;");
				break;
			case '`':
				encodedText.append("&apos;");
				break;
			case '<':
				encodedText.append("&lt;");
				break;
			case '>':
				encodedText.append("&gt;");
				break;
			case '&':
				encodedText.append("&amp;");
				break;
			default:
				encodedText.append(1, ch);
		}
	}

	return encodedText;
}

void HtmlEncodeMultiLines(std::istream& input, std::ostream& output)
{
	string line;

	while (getline(input, line))
		output << HtmlEncode(line) << '\n';
}
#include <string>
#include <map>
#include <iostream>

class Dictionary
{
public:
	Dictionary(const std::string& filename);
	void Run(std::istream&, std::ostream&);
private:
	std::map<std::string, std::string> m_translations;
	std::string m_filename;
};

#include <string>
#include <map>
#include <sstream>

class Dictionary
{
public:
	Dictionary(const std::string& filename);
	void Run(std::istringstream&, std::ostringstream&);
	std::map<std::string, std::string> m_translations;
	std::string m_filename;
};

#include <map>
#include <functional>
#include <iosfwd>
#include <string>

class CTVSet;

class CRemoteControl
{
public:
	CRemoteControl(CTVSet & tv, std::istream & input, std::ostream & output);
	bool HandleCommand();

private:
	bool TurnOn(std::istream & args);
	bool TurnOff(std::istream & args);
	bool Info(std::istream & args);
	bool SelectChannel(std::istream & args);
private:
	using Handler = std::function<bool(std::istream & args)>;

	using ActionMap = std::map<std::string, Handler>;

	CTVSet & m_tv;
	std::istream & m_input;
	std::ostream & m_output;

	const ActionMap m_actionMap;
};


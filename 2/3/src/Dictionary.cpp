#include <iostream>
#include <string>
#include <fstream>
#include "Dictionary.h"

using namespace std;

Dictionary::Dictionary(const string& filename)
	: m_filename(filename)
	, m_translations()
{
	ifstream file(filename);
	string translation;
	while (getline(file, translation))
	{
		auto pos = translation.find('@');
		m_translations.emplace(translation.substr(0, pos), translation.substr(pos + 1));
	}
}

void Dictionary::Run(std::istringstream& input, std::ostringstream& output)
{
	string inputStr;
	bool changed = false;
	while (getline(input, inputStr))
	{
		if (inputStr == "...")
		{
			if (changed)
			{
				output << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n";
				getline(input, inputStr);
				if (inputStr == "Y" || inputStr == "y")
				{
					ofstream storage(m_filename);
					for (const auto& val : m_translations)
					{
						storage << val.first << "@" << val.second << '\n';
					}
					output << "Изменения сохранены. ";
				}
			}
			output << "До свидания.\n";
			break;
		}
		if (m_translations.contains(inputStr))
		{
			output << m_translations[inputStr] << '\n';
		}
		else
		{
			output << "Неизвестное слово \"" << inputStr << "\". Введите перевод или пустую строку для отказа.\n";
			string translation;
			getline(input, translation);
			if (translation.empty())
			{
				output << "Слово \"" << inputStr << "\" проигнорировано.\n";
			}
			else
			{
				m_translations.emplace(inputStr, translation);
				changed = true;
				output << "Слово \"" << inputStr << "\" сохранено в словаре как \"" << translation << "\".\n";
			}
		}
	}
}

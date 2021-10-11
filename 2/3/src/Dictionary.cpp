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
				output << "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������.\n";
				getline(input, inputStr);
				if (inputStr == "Y" || inputStr == "y")
				{
					ofstream storage(m_filename);
					for (const auto& val : m_translations)
					{
						storage << val.first << "@" << val.second << '\n';
					}
					output << "��������� ���������. ";
				}
			}
			output << "�� ��������.\n";
			break;
		}
		if (m_translations.contains(inputStr))
		{
			output << m_translations[inputStr] << '\n';
		}
		else
		{
			output << "����������� ����� \"" << inputStr << "\". ������� ������� ��� ������ ������ ��� ������.\n";
			string translation;
			getline(input, translation);
			if (translation.empty())
			{
				output << "����� \"" << inputStr << "\" ���������������.\n";
			}
			else
			{
				m_translations.emplace(inputStr, translation);
				changed = true;
				output << "����� \"" << inputStr << "\" ��������� � ������� ��� \"" << translation << "\".\n";
			}
		}
	}
}

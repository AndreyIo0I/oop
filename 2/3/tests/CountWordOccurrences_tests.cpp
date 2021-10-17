#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/Dictionary.h"
#include <fstream>

TEST_CASE("Existing translation")
{
	const std::string FILENAME = std::string(TEST_RESOURCE_DIR) + "/testTranslations.txt";
	std::ofstream file(FILENAME);
	file << "123@321\n";
	file.close();
	Dictionary dictionary(FILENAME);
	std::ostringstream output;
	std::istringstream input("123\n...\n");

	dictionary.Run(input, output);

	CHECK(output.str() == "321\n�� ��������.\n");
}

TEST_CASE("New translation")
{
	const std::string FILENAME = std::string(TEST_RESOURCE_DIR) + "/testTranslations.txt";
	std::ofstream file(FILENAME);
	file << "ball@���\n";
	file.close();
	Dictionary dictionary(FILENAME);
	std::ostringstream output;
	std::istringstream input("321\n123\n...\ny\n");

	dictionary.Run(input, output);

	CHECK(output.str() == "����������� ����� \"321\". ������� ������� ��� ������ ������ ��� ������.\n"
						  "����� \"321\" ��������� � ������� ��� \"123\".\n"
						  "� ������� ���� ������� ���������. ������� Y ��� y ��� ���������� ����� �������.\n"
						  "��������� ���������. �� ��������.\n");
}
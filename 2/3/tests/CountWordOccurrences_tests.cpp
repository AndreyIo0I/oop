#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../src/Dictionary.h"
#include <fstream>

TEST_CASE("Given an existing translation")
{
	const std::string FILENAME = R"(C:\Users\andrb\CLionProjects\oop\2\3\tests\testTranslations.txt)";
	std::ofstream file(FILENAME);
	file << "123@321\n";
	file.close();
	Dictionary dictionary(FILENAME);
	std::ostringstream output;
	std::istringstream input("123\n...\n");

	dictionary.Run(input, output);

	CHECK(output.str() == "321\nДо свидания.\n");
}

TEST_CASE("Given an new translation")
{
	const std::string FILENAME = R"(C:\Users\andrb\CLionProjects\oop\2\3\tests\testTranslations.txt)";
	std::ofstream file(FILENAME);
	file << "ball@мяч\n";
	file.close();
	Dictionary dictionary(FILENAME);
	std::ostringstream output;
	std::istringstream input("321\n123\n...\ny\n");

	dictionary.Run(input, output);

	CHECK(output.str() == "Неизвестное слово \"321\". Введите перевод или пустую строку для отказа.\n"
						  "Слово \"321\" сохранено в словаре как \"123\".\n"
						  "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n"
						  "Изменения сохранены. До свидания.\n");
}
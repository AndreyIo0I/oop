#include <iostream>
#include <optional>
#include <string>

std::optional<int> ParseArgs(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Invalid arguments count\n";
        std::cout << "Usage: flipbyte.exe <input byte>\n";
        return std::nullopt;
    }

    int number = std::stoi(argv[1]);

    if ((number < 0) || (number > 255))
    {
        std::cout << "Number must be between 0 and 255\n";
        return std::nullopt;
    }

    return number;
}

int main(int argc, char* argv[])
{
    auto optionalNumber = ParseArgs(argc, argv);
    int flippedNumber = 0;

    if (!optionalNumber)
    {
        return 1;
    }
    int number = optionalNumber.value();

    for (int i = 0; i < 8; i++)
    {
        flippedNumber += (number & ((int) pow(2, i)))
            ? (int) pow(2, 7 - i)
            : 0;
    }

    std::cout << flippedNumber << "\n";

    return 0;
}
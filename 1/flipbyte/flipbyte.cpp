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

    int number;
    try
    {
        number = std::stoi(argv[1]);
    }
    catch (std::exception& e) {
        std::cout << "Input must be a decimal number\n";
        return std::nullopt;
    }

    if ((number < 0) || (number > 255))
    {
        std::cout << "Number must be between 0 and 255\n";
        return std::nullopt;
    }

    return number;
}

int Flip(int number) {
    int flippedNumber = 0;
    for (int i = 0; i < 8; i++)
    {
        flippedNumber += (number & (1 << i))
                         ? (1 << (7 - i))
                         : 0;
    }

    return flippedNumber;
}

int main(int argc, char* argv[])
{
    auto optionalNumber = ParseArgs(argc, argv);

    if (!optionalNumber)
    {
        return 1;
    }

    int number = optionalNumber.value();
    int flippedNumber = 0;
    flippedNumber = Flip(number);

    std::cout << flippedNumber << "\n";

    return 0;
}
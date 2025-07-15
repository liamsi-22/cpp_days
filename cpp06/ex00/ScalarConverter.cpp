#include "ScalarConverter.hpp"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <sstream>

double ScalarConverter::toDouble(const std::string& str)
{
    double value;
    std::istringstream iss(str);

    iss >> value;
    if (iss.fail() || !iss.eof())
        throw std::runtime_error("Invalid double conversion");
    return value;
}

void ScalarConverter::convert(const std::string& str)
{
    double value = 0.0;
    bool isSpecial = false;
    std::string literal = ScalarConverter::trim(str);

    if (literal == "nan" || literal == "nanf")
    {
        value = std::numeric_limits<double>::quiet_NaN();
        isSpecial = true;
    }
    else if (literal == "inf" || literal == "+inf" || literal == "inff" || literal == "+inff")
    {
        value = std::numeric_limits<double>::infinity();
        isSpecial = true;
    }
    else if (literal == "-inf" || literal == "-inff")
    {
        value = -std::numeric_limits<double>::infinity();
        isSpecial = true;
    }
    else if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
    {
        value = static_cast<double>(literal[0]);
    }
    else{
        try {
            value = ScalarConverter::toDouble(literal);
        } catch (...){
            std::cout << "char: " << "impossible" << std::endl;
            std::cout << "int: " << "impossible" << std::endl;
            std::cout << "float: " << "impossible" << std::endl;
            std::cout << "double: " << "impossible" << std::endl;
            return;
        }
    }
    print(isSpecial, value);
    
}

void ScalarConverter::print(bool isSpecial, double value)
{
    std::cout << "char: ";
    if (isSpecial || value < 0 || value > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(static_cast<char>(value)))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << "'" << static_cast<char>(value) << "'" << std::endl;

    std::cout << "int: ";
    if (isSpecial || value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
        std::cout << "impossible" << std::endl;
    else
        std::cout << static_cast<int>(value) << std::endl;

    std::cout << "float: ";
    value = static_cast<float>(value);
    std::cout << std::fixed << std::setprecision(1) << value << "f" << std::endl;

    std::cout << "double: ";
    std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

std::string ScalarConverter::trim(const std::string& str)
{
    size_t start = 0;
    size_t end = str.length();

    while (start < end && std::isspace(str[start]))
        ++start;
    while (end > start && std::isspace(str[end - 1]))
        end--;
    return (str.substr(start, end- start));
}
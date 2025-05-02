#include <iostream>

class ScalarConverter{

    private:
        ScalarConverter();

    public:
        static void convert(std::string literal);
        static int detectType(const std::string& input);
};

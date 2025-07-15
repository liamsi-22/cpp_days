#include <iostream>

class ScalarConverter{

    private:
        ScalarConverter();
    public:
        static void convert(const std::string& str);
        static double toDouble(const std::string& str);
        static  std::string trim(const std::string& str);
        static void print(bool isSpecial, double value);
};

#include <iostream>

class ScalarConverter{

    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
        ~ScalarConverter();

    public:
        static void convert(const std::string& str);
        static double toDouble(const std::string& str);
        static  std::string trim(const std::string& str);
        static void print(bool x, double y);
};

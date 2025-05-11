#include "utilities.hpp"

int main(int ac, char **av){

    std::string fileName, line, s1, s2;
    if (ac != 4)
    {
        std::cout << "error : wrong number of arguments !" << std::endl;
        return 1;
    }
    fileName = av[1];
    s1 = av[2];
    s2 = av[3];
    return (fileManipulation(fileName, s1, s2));
}
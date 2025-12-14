#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
    try
    {
        if (ac != 2)
            throw std::runtime_error("ERROR !");
        int x = RPN::evalRPN(av[1]);
        std::cout << x  << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}
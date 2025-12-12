#include <iostream>
#include "PmergeMe.hpp"
#include <climits>
#include <sstream>

void parseArg(char* av, PmergeMe &obj)
{
	long int val;

	for (size_t i = 0; av[i] != '\0'; i++)
	{
        if (!isdigit(av[i]) && !isspace(av[i]))
            throw std::runtime_error("Error : Bad argument!");
	}
    std::stringstream ss(av);
	while (ss >> val)
	{
        if (val < 0 || val > INT_MAX)
            throw std::runtime_error("Error : Bad argument!");
        obj.ser_number(val);
	}
}

int main(int ac, char **av)
{

	if (ac < 2)
    {
        std::cout << "Bad argument!" << std::endl;
	    std::cout << "usage: ./PmergeMe [positive integer sequence...]" << std::endl;
	    return (1);
    }
	try
	{
        PmergeMe obj;
		for (int i = 1; i < ac; i++)
			parseArg(av[i], obj);
		
		obj.sort();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
}
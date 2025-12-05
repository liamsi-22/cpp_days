#include <iostream>
#include <vector>
#include <algorithm>
#include "easyfind.hpp"

int main()
{
    std::vector<int> numbers;

    numbers.push_back(10);
    numbers.push_back(30);
    numbers.push_back(80);
    numbers.push_back(50);

    std::vector<int>::iterator it;
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it)
        std::cout << *it << " " ;
    std::cout << std::endl;

    try{
        std::vector<int>::iterator it =  easyfind(numbers, 80);
        std::cout << *it << std::endl;
        
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return (0);
}
#include <iostream>
#include <vector>
#include <algorithm>
#include "easyfind.hpp"
// #include <list>

int main()
{
    std::vector<int> numbers = {10, 20, 30, 60, 90};

    // numbers.push_back(1);
    // numbers.push_back(2);
    // numbers.push_back(3);

    // std::vector<int>::iterator it;
    // for (auto it = numbers.begin(); it < numbers.end(); ++it)
    //     std::cout << *it << " " ;
    // std::cout << std::endl;

    try{

        auto it =  easyfind(numbers, 40);
        std::cout << *it << std::endl;
        
    } catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }


    // auto it = std::find(numbers.begin(), numbers.end(), 120);
    // if (it != numbers.end())
    //     std::cout << "found: " << *it << std::endl;
    // else
    //     std::cout << "not found !" << std::endl;
    return (0);
}
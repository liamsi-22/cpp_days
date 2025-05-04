#include <iostream>
#include "PhoneBook.hpp"
#include <string>
#include <limits>   // for std::numeric_limits
#include <iostream>

int main()
{
    PhoneBook obj;
    std::string arg;

    while (true)
    {
        std::cout << "please choose a number" << std::endl;
        std::cout << "ADD" << std::endl;
        std::cout << "SEARCH" << std::endl;
        std::cout << "EXIT" << std::endl;
        std::getline(std::cin, arg);
        if (!std::getline(std::cin, arg)){
            std::cout << "Input failed. Please try again." << std::endl;
            break;
        }
        else if (arg == "ADD")
            obj.addContact();
        else if (arg == "SEARCH")
            obj.searchContact();
        else if (arg == "EXIT")
            break;
        else
            std::cout << "please use ADD, SEARCH or EXIT." << std::endl;

    }
    std::cout << "Goodbye!\n";
    return 0;
}
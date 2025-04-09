#include <iostream>
#include "PhoneBook.hpp"
#include <string>
#include <limits>   // for std::numeric_limits
#include <iostream>

// int main() {
//     int y;
//     std::string x;

//     std::cin >> y;
//     // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//     std::cin.ignore();
//     std::getline(std::cin, x);

//     std::cout << "y = " << y << ", x = " << x << '\n';
// }

// int main()
// {
//     std::string x,y;
//     std::cin >> x;
//     std::cin.ignore();
//     std::getline(std::cin, y);


//     std::cout << x << std::endl;
//     std::cout << y << std::endl;
    
//     int age, num;
    
//     std::cin >> age;
//     // std::cin.clear();
//     std::cin >> num;

//     std::cout << "new line" << std::endl;
//     std::cout << age << std::endl;
//     if (std::cin.fail())
//         std::cout << "Input failed!\n";

//     std::cout << num << std::endl;
    
//     return 0;
// }


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
        
        if (arg == "ADD")
        {
            obj.addContact();
        }
        else if (arg == "SEARCH")
        {
            obj.searchContact();
        }
        else if (arg == "EXIT")
        {
            break;
        }
        else
            std::cout << "please use ADD, SEARCH or EXIT." << std::endl;

    }
    std::cout << "Goodbye!\n";
    return 0;
}
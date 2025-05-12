#include "PhoneBook.hpp"

PhoneBook::PhoneBook(): _index(0){}

void PhoneBook::addContact(){
    std::string fn, ln, nick, num, dsc;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, fn);
    std::cout << "Enter Last Name: ";
    std::getline(std::cin, ln);
    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nick);
    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, num);
    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, dsc);

    // It's better to check for whitespace to preserve the proper formatting. 
    if (fn.empty() || ln.empty() || nick.empty() || num.empty() || dsc.empty() )
    {
        std::cout << "************************************************" << std::endl;
        std::cout << "***** failed :all fields must be filled in *****" << std::endl;
        std::cout << "************************************************" << std::endl;
        return ;
    }

    _contacts[_index++ % 8].setContact(fn, ln, nick, num, dsc);
}

void PhoneBook::searchContact(){

    if (_contacts[0].CtcisEmpty())
    {
        std::cout << "********************************" << std::endl;
        std::cout << "***** PhoneBook is empty ! *****" << std::endl;
        std::cout << "********************************" << std::endl;
        return ;
    }

    std::cout << "chose the index of the contact" << std::endl;
    std::cout << "|" << std::setw(10) << "index" << "|"
            << std::setw(10)  << "first name" << "|"
            << std::setw(10) << "last name" << "|"
            << std::setw(10) << "nickname" << "|" << std::endl;

    // truncate the strings that exceed 10 characters
    int i = 0;
    while (i < 8 && !_contacts[i].CtcisEmpty())
    {
        _contacts[i].displayContact(i);
        i++;
    }

    int x = 0;
    std::cout << "enter the index : ";
    std::cin >> x;
    if (std::cin.fail() || x < 0 || x > 7 || _contacts[x].CtcisEmpty())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "***************************" << std::endl;
        std::cout << "***** invalid index ! *****" << std::endl;
        std::cout << "***************************" << std::endl;
        return ;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "************************" << std::endl;
        std::cout << "***** Contact info *****" << std::endl;
        std::cout << "************************" << std::endl;
    _contacts[x].displayContactInfo();
}

 
PhoneBook::~PhoneBook(){}
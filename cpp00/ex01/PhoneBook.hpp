#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>
#include <iostream>
#include <iomanip> // for setw()
#include <limits>   // for std::numeric_limits

class PhoneBook {

    private:
        Contact _contacts[8];
        int _index;

    public:
        PhoneBook();
        void addContact();
        void searchContact();
        ~PhoneBook();
};

#endif
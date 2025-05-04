#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact {
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _number;
        std::string _darkSecret;

    public:
        Contact();
        void setContact(std::string fn,std::string ln, std::string nick,std::string num,std::string dsk);
        void displayContact(int i);
        void displayContactInfo();
        std::string truncatedStr(std::string str);
        bool CtcisEmpty();
        ~Contact();
};

#endif
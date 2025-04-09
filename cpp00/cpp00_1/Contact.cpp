#include "Contact.hpp"
#include <iostream>
#include <iomanip>



void Contact::setContact(std::string fn,std::string ln,std::string nick
    ,std::string num,std::string dsk)
    {
        this->firstName = fn;
        this->lastName = ln;
        this->nickName = nick;
        this->number = num;
        this->darkSecret = dsk;
    }

void Contact::displayContact(int i){
    std::cout << "|" << std::setw(10) << i << "|"
    << std::setw(10)  << truncatedStr(this->firstName) << "|"
    << std::setw(10) << truncatedStr(this->lastName) << "|"
    << std::setw(10) << truncatedStr(this->nickName) << "|" << std::endl;
}

void Contact::displayContactInfo(){
    std::cout << "First Name: " << this->firstName << "\n"
            << "Last Name: " << this->lastName << "\n"
            << "Nickname: " << this->nickName << "\n"
            << "Phone Number: " << this->number << "\n"
            << "Darkest Secret: " << this->darkSecret << std::endl;
}

std::string Contact::truncatedStr(std::string str){
    if (str.length() > 10)
    {
       return (str.substr(0, 9) + ".");
    }
    return (str);
}

bool Contact::CtcisEmpty(){
    return (this->firstName.empty());
}
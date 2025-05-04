#include "Contact.hpp"

Contact::Contact(){}

void Contact::setContact(std::string fn,std::string ln,std::string nick
    ,std::string num,std::string dsk){
        _firstName = fn;
        _lastName = ln;
        _nickName = nick;
        _number = num;
        _darkSecret = dsk;
}

void Contact::displayContact(int i){
    std::cout << "|" << std::setw(10) << i << "|"
    << std::setw(10)  << truncatedStr(_firstName) << "|"
    << std::setw(10) << truncatedStr(_lastName) << "|"
    << std::setw(10) << truncatedStr(_nickName) << "|" << std::endl;
}

void Contact::displayContactInfo(){
    std::cout << "First Name: " << _firstName << "\n"
            << "Last Name: " << _lastName << "\n"
            << "Nickname: " << _nickName << "\n"
            << "Phone Number: " << _number << "\n"
            << "Darkest Secret: " << _darkSecret << std::endl;
}

std::string Contact::truncatedStr(std::string str){
    if (str.length() > 10)
       return (str.substr(0, 9) + ".");
    return (str);
}

bool Contact::CtcisEmpty(){
    return (_firstName.empty());
}

Contact::~Contact(){}
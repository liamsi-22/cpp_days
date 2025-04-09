#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "string"

class Contact {
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string number;
        std::string darkSecret;

    public:
        void setContact(std::string fn,std::string ln,
            std::string nick,std::string num,std::string dsk);
            
        void displayContact(int i);
        void displayContactInfo();
        std::string truncatedStr(std::string str);
        bool CtcisEmpty();
};

#endif
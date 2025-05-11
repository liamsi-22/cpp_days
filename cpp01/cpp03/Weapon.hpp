#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <string>

class Weapon
{
    private:
        std::string _type;

    public:
        Weapon(std::string wpn);

        void setType(std::string NewType);
        const std::string& getType();

        ~Weapon();
};

#endif
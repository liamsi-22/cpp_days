#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
    private:
        std::string type;
    public:
        Weapon();
        Weapon(std::string _wpn);

        void setType(std::string NewType);
        std::string& getType();

        ~Weapon();
};

#endif
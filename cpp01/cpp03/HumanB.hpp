#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon* weapon_2;
    public:
        HumanB(std::string name);

        void attack(void);
        void setWeapon(Weapon& _wpn);

        ~HumanB();
};

#endif
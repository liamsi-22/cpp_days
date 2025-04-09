#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA
{
    private:
        std::string name;
        Weapon& weapon_1;
    public:
        HumanA(std::string name, Weapon& _wpn);

        void attack(void);
        
        ~HumanA();
};

#endif
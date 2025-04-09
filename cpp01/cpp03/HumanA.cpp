#include <iostream>
#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA(std::string name, Weapon& _wpn): name(name),weapon_1(_wpn){}

void HumanA::attack(){
    std::cout << name << " attacks with their " << this->weapon_1.getType() << std::endl;
}

HumanA::~HumanA(){}
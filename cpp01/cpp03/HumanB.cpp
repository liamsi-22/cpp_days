#include <iostream>
#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB(std::string name){
    this->name = name;
}

void HumanB::attack(){
    std::cout << name << " attacks with their " << weapon_2->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& _wpn){
    this->weapon_2 = &_wpn;
}

HumanB::~HumanB(){
    if (this->weapon_2)
        delete weapon_2;
}
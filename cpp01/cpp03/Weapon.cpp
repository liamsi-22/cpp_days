#include "Weapon.hpp"

Weapon::Weapon(){}


Weapon::Weapon(std::string _wpn): type(_wpn){}

std::string& Weapon::getType() {
    return (type);
}

void Weapon::setType(std::string NewType){
    this->type = NewType;
}


Weapon::~Weapon(){}

#include "Weapon.hpp"


Weapon::Weapon(std::string wpn): _type(wpn){}

const std::string& Weapon::getType(){
    return (_type);
}

void Weapon::setType(std::string NewType){
    _type = NewType;
}

Weapon::~Weapon(){}

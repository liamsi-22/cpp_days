#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon& wpn): _name(name), _weapon(wpn){}

void HumanA::attack(){
    std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
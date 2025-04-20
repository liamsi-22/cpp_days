#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap Constructor " << this->name << " enters the arena!" << std::endl;

}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other){
    std::cout << "ScavTrap [" << this->name << "] copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "Assignment operator invoked: ScavTrap [" << this->name << "] data transferred" << std::endl;
    return(*this);
}

void ScavTrap::guardGate(){
    if (this->hitPoints)
        std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target){
    if (this->energyPoints && this->hitPoints)
    {
       std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing a savage " << this->attackDamage << " points of damage!" << std::endl;
       this->energyPoints--;
    }
    else
        std::cout << "ScavTrap " << this->name << " can't attack (no energy or hit points left)." << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap Destructor " << this->name << " is exiting the arena." << std::endl;
}

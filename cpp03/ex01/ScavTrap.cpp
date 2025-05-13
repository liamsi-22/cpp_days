#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
    std::cout << "ScavTrap Default constructor called" << std::endl;
    setName("ScavTrap"); 
    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
    setHitPoint(100);
    setEnergyPoint(50);
    setAttackDamage(20);
    std::cout << "ScavTrap [" << getName() << "] parameterized constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other){
    std::cout << "ScavTrap [" << getName() << "] copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
    std::cout << "ScavTrap [" << getName() << "] assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return(*this);
}

void ScavTrap::guardGate(){
    if (getHitPoint())
        std::cout << "ScavTrap [" << getName() << "] is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target){
    if (getEnergyPoint() && getHitPoint())
    {
       std::cout << "ScavTrap [" << getName() << "] attacks " << target << ", causing a savage " << getAttackDamage() << " points of damage!" << std::endl;
       setEnergyPoint(getEnergyPoint() - 1);
    }
    else
        std::cout << "ScavTrap [" << getName() << "] can't attack (no energy or hit points left)." << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << "ScavTrap [" << getName() << "] Destructor called" << std::endl;
}

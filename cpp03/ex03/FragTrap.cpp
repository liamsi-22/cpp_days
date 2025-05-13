#include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout << "FragTrap Default constructor called" << std::endl;
    setName("FragTrap"); 
    setHitPoint(100);
    setEnergyPoint(100);
    setAttackDamage(30);
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
    setHitPoint(100);
    setEnergyPoint(100);
    setAttackDamage(30);
    std::cout << "FragTrap [" << getName() << "] parameterized constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other){
    std::cout << "FragTrap [" << getName() << "] copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "FragTrap [" << getName() << "] assignment operator called" << std::endl;
    return(*this);
}

void FragTrap::highFivesGuys(void){
    if (getHitPoint())
        std::cout << "FragTrap [" << getName() << "] shouts: Who wants a high five?" << std::endl;
    else
        std::cout << "FragTrap [" << getName() << "] is too damaged to high five anyone" << std::endl;
}

void FragTrap::attack(const std::string& target){
    if (getEnergyPoint() && getHitPoint())
    {
       std::cout << "FragTrap [" << getName() << "] attacks " << target << ", causing a savage " << getAttackDamage() << " points of damage!" << std::endl;
       setEnergyPoint(getEnergyPoint() - 1);
    }
    else
        std::cout << "FragTrap [" << getName() << "] can't attack (no energy or hit points left)" << std::endl;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap [" << getName() << "] Destructor called" << std::endl;
}
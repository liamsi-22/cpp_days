#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name){
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
    std::cout << "FragTrap Constructor " << this->name << " enters the arena!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other){
    std::cout << "FragTrap [" << this->name << "] copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "Assignment operator invoked: FragTrap [" << this->name << "] data transferred" << std::endl;
    return(*this);
}

void FragTrap::highFivesGuys(void){
    if (this->hitPoints)
        std::cout << "FragTrap " << this->name << " shouts: Who wants a high five?" << std::endl;
    else
        std::cout << "FragTrap " << this->name << " is too damaged to high five anyone" << std::endl;
}

void FragTrap::attack(const std::string& target){
    if (this->energyPoints && this->hitPoints)
    {
       std::cout << "FragTrap " << this->name << " attacks " << target << ", causing a savage " << this->attackDamage << " points of damage!" << std::endl;
       this->energyPoints--;
    }
    else
        std::cout << "FragTrap " << this->name << " can't attack (no energy or hit points left)." << std::endl;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap Destructor " << this->name << " is exiting the arena." << std::endl;
}
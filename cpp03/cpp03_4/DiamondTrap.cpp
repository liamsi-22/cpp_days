#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name){
    this->hitPoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap Constructor " << this->name << " enters the arena!" << std::endl;
}

// know better the other.ClapTrap::name type
DiamondTrap::DiamondTrap(const DiamondTrap& other):ClapTrap(other.ClapTrap::name), FragTrap(other), ScavTrap(other) , name(other.name){
    this->hitPoints = other.hitPoints;
    this->energyPoints = other.energyPoints;
    this->attackDamage = other.attackDamage;
    std::cout << "DiamondTrap [" << this->name << "] copy constructor called" << std::endl;
}
// hsould i use virtual in the subobject classes ? or specifiying with base class operator to use to avoid the conflict ??
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other){
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
        std::cout << "Assignment operator invoked: DiamondTrap [" << this->name << "] data transferred" << std::endl;
    }
    return (*this);
}

void DiamondTrap::whoAmI(){
    std::cout << "My DiamondTrap name is: " << this->name << " | My ClapTrap name is: " << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string& target){
    ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap Destructor " << this->name << " is exiting the arena." << std::endl;
}
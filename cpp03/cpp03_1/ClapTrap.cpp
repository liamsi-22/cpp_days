#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name): name(name), hitPoints(10), energyPoints(10), attackDamage(0){
    std::cout << "ClapTrap Constructor " << this->name << " is initialized" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): name(other.name),hitPoints(other.hitPoints),energyPoints(other.energyPoints),attackDamage(other.attackDamage){
    std::cout << "ClapTrap [" << this->name << "] copy constructor called" << std::endl;
}


ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    if (this != &other)
    {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    std::cout << "Assignment operator invoked: ClapTrap [" << this->name << "] data transferred" << std::endl;
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (this->energyPoints && this->hitPoints)
    {
       std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << std::endl;
       this->energyPoints--;
    }
    else
        std::cout << "ClapTrap " << this->name << " can't attack (no energy or hit points left)." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hitPoints)
    {
        int tmp = this->hitPoints - amount;
        if (tmp < 0)
            this->hitPoints = 0;
        else
            this->hitPoints -= amount;
        std::cout << "Robot " << this->name << " takes " << amount << " points of damage" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->energyPoints && this->hitPoints)
    {
        this->hitPoints += amount;
        std::cout << "Robot " << this->name << " repairs itself for " << amount << " hit points!" << std::endl;
        this->energyPoints--;
    }
    else
        std::cout << "Robot " << this->name << " can't repaire (no energy or hit points left)." << std::endl;

}


ClapTrap::~ClapTrap(){
std::cout << "ClapTrap Destructor " << this->name << " is shutting down" << std::endl;
}

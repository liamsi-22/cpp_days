#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

DiamondTrap::DiamondTrap(std::string name): name(name)
{
    ClapTrap::name = name + "_clap_name";
    this->hitpoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap Constructor " << this->name << " enters the arena!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): name(other.name)
{
    ClapTrap::name = other::ClapTrap::name;
    this->hitpoints = FragTrap::hitPoints;
    this->energyPoints = ScavTrap::energyPoints;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap [" << this->name << "] copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        this->name = other.name
        ClapTrap::name = ClapTrap::name = other::ClapTrap::name;
        this->hitpoints = FragTrap::hitPoints;
        this->energyPoints = ScavTrap::energyPoints;
        this->attackDamage = FragTrap::attackDamage;
        std::cout << "Assignment operator invoked: DiamondTrap [" << this->name << "] data transferred" << std::endl;
    }
    return (*this);
}

void DiamondTrap::whoAmI()
{
    std::cout << "my name is :" << this->name << "and my ClapTrap name is :" << ClapTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor " << this->name << " is exiting the arena." << std::endl;
}
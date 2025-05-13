#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("ClapTrap"), _name("ClapTrap"){
    setHitPoint(FragTrap::getHitPoint());
    setEnergyPoint(ScavTrap::getEnergyPoint());
    setAttackDamage(FragTrap::getAttackDamage());
    std::cout << "DiamondTrap [" << getName() << "] constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), _name(name){
    setHitPoint(FragTrap::getHitPoint());
    setEnergyPoint(ScavTrap::getEnergyPoint());
    setAttackDamage(FragTrap::getAttackDamage());
    std::cout << "DiamondTrap [" << getName() << "] constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other):ClapTrap(other), _name(other._name){
    setHitPoint(other.getHitPoint());
    setEnergyPoint(other.getEnergyPoint());
    setAttackDamage(other.getAttackDamage());
    std::cout << "DiamondTrap [" << getName() << "] copy constructor called" << std::endl;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other){
    if (this != &other)
    {
        ClapTrap::operator=(other);
        setName(other.getName());
        setHitPoint(other.getHitPoint());
        setEnergyPoint(other.getHitPoint());
        setAttackDamage(other.getAttackDamage());
        std::cout << "Assignment operator invoked: DiamondTrap [" << getName() << "] data transferred" << std::endl;
    }
    return (*this);
}

void DiamondTrap::whoAmI(){
    std::cout << "My DiamondTrap name is: [" << getName() << "] | My ClapTrap name is: " << ClapTrap::getName() << std::endl;
}

void DiamondTrap::attack(const std::string& target){
    ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap [" << getName() << "] Destructor called" << std::endl;
}
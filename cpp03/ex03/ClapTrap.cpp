#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name): _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "ClapTrap [" << _name << "] parameterized constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other): _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage){
    std::cout << "ClapTrap [" << _name << "] copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    std::cout << "ClapTrap [" << _name << "] assignment operator called" << std::endl;
    if (this != &other)
    {
        _name = other._name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if (_energyPoints && _hitPoints)
    {
       std::cout << "ClapTrap [" << _name << "] attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
       _energyPoints--;
    }
}

void ClapTrap::setName(std::string name){
    _name = name;
}

void ClapTrap::setHitPoint(unsigned int x){
    _hitPoints = x;
}

void ClapTrap::setEnergyPoint(unsigned int y){
    _energyPoints = y;
}

void ClapTrap::setAttackDamage(unsigned int z){
    _attackDamage = z;
}


std::string ClapTrap::getName() const{
    return (_name);
}

unsigned int ClapTrap::getHitPoint() const{
    return (_hitPoints);
}

unsigned int ClapTrap::getEnergyPoint() const{
    return (_energyPoints);
}

unsigned int ClapTrap::getAttackDamage() const{
    return (_attackDamage);
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (_hitPoints)
    {
        int tmp = _hitPoints - amount;
        if (tmp < 0)
            _hitPoints = 0;
        else
            _hitPoints -= amount;
        std::cout << "ClapTrap [" << _name << "] takes " << amount << " points of damage" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (_energyPoints && _hitPoints)
    {
        _hitPoints += amount;
        std::cout << "ClapTrap [" << _name << "] repairs itself for " << amount << " hit points!" << std::endl;
        _energyPoints--;
    }
}


ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap [" << _name << "] Destructor called" << std::endl;
}

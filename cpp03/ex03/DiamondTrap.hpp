#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap , public ScavTrap
{
    private:
        std::string _name;
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& other);

        DiamondTrap& operator=(const DiamondTrap& other);
        
        void attack(const std::string& target) ;
        void whoAmI();

        ~DiamondTrap();
};

#endif
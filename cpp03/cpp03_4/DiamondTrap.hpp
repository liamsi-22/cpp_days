#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>
#include "ScaveTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap , public ScaveTrap
{
    private:
        std::string name;
    public:
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& other);

        DiamondTrap& operator=(const DiamondTrap& other);
        
        void attack(const std::string& target);
        void whoAmI();

        ~DiamondTrap();
};

#endif
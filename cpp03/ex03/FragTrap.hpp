#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);

        FragTrap& operator=(const FragTrap& other);

        void highFivesGuys(void);

        void attack(const std::string& target);

        ~FragTrap();
};

#endif
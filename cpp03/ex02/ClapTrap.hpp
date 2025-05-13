#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
    private:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

    public:
        ClapTrap();
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);

        void setName(std::string name);
        void setHitPoint(unsigned int);
        void setEnergyPoint(unsigned int);
        void setAttackDamage(unsigned int);

        std::string getName() const;
        unsigned int getHitPoint() const;
        unsigned int getEnergyPoint() const;
        unsigned int getAttackDamage() const;

        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        virtual ~ClapTrap();
};

#endif
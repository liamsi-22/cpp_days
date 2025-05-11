#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie;

Zombie* zombieHorde(int N, std::string name);

class Zombie
{
    private:
        std::string name;

    public:
        Zombie();
        Zombie(std::string zombieName);
        void setZombieName(std::string zombieName);
        void announce( void );
        ~Zombie();
};

#endif
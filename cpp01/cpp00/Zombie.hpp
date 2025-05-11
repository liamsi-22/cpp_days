#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

// forward declaration
class Zombie;

void randomChump(std::string name);
Zombie* newZombie(std::string name);

class Zombie
{
    private:
        std::string _name;
    
    public:
        Zombie();
        Zombie(std::string zombieName);
        void announce( void );
        ~Zombie();
};

#endif
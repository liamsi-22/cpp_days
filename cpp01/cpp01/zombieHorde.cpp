#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* horbe = new Zombie[N];
    for (int i = 0; i < N ; i++)
        horbe[i].setZombieName(name);
    return (horbe);
}
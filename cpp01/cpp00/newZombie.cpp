#include "Zombie.hpp"

Zombie* newZombie( std::string name ){
    Zombie* undead = new Zombie(name);
    return (undead);
}
#include <iostream>
#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main(){
    int i = 0;
    int N = 10;
    Zombie* undead = zombieHorde(N, "Zizo");
    while (i < N)
    {
        undead->announce();
        i++;
    }
    delete[] (undead);
}
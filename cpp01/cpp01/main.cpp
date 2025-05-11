#include "Zombie.hpp"

int main(){
    int N = 10;
    Zombie* undead = zombieHorde(N, "Zizo");
    while (N--)
        undead->announce();
    delete[] (undead);
}
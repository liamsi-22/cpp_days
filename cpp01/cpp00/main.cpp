#include <iostream>
#include "Zombie.hpp"


void randomChump(std::string name);
Zombie* newZombie( std::string name );

int main(){
    Zombie* undead_1 = newZombie("undead_1");
    undead_1->announce();
    randomChump("undead_2");
    delete undead_1;
}
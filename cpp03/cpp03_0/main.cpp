#include <iostream>
#include "ClapTrap.hpp"

int main(){
    ClapTrap clptrp("robot");
    clptrp.attack("NVedia");
    clptrp.takeDamage(5);
    clptrp.attack("NVedia");    
    clptrp.beRepaired(2);
}
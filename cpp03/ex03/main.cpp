#include <iostream>
// #include "ClapTrap.hpp"
// #include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(){
    DiamondTrap Robot_1("Liam");
    Robot_1.attack("Alien");
    Robot_1.highFivesGuys();
    Robot_1.guardGate();
    Robot_1.whoAmI();
    Robot_1.takeDamage(1000);
    Robot_1.attack("Alien");
    // FragTrap robot_1("robot_1");
    // robot_1.attack("Alien");
    // robot_1.highFivesGuys();
    // robot_1.takeDamage(120);
    // robot_1.highFivesGuys();
    // robot_1.attack("Alien");
}
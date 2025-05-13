#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(){
    FragTrap robot_1("robot_1");
    robot_1.attack("Alien");
    robot_1.highFivesGuys();
    robot_1.takeDamage(120);
    robot_1.highFivesGuys();
    robot_1.attack("Alien");
}
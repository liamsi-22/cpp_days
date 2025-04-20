#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){
    ScavTrap robot_1("robot_1");
    robot_1.attack("alien");
    robot_1.guardGate();
    robot_1.takeDamage(6);
    robot_1.beRepaired(8);
    ScavTrap robot_2("robot_2");
    robot_2.takeDamage(200);
    robot_2.attack("alien");
    robot_1.attack("alien");
    robot_2 = robot_1;
    robot_2.attack("alien");
}
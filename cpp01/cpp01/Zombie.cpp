#include "Zombie.hpp"

Zombie::Zombie(){}

Zombie::Zombie(std::string zombieName): name(zombieName){}

void Zombie::announce( void ){
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setZombieName(std::string zombieName){
    name = zombieName;
}

Zombie::~Zombie(){
    std::cout << name << " has been destroyed" << std::endl;
}
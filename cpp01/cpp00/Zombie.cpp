#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName): name(zombieName){}

void Zombie::announce( void ){
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(){
    std::cout << name << " has been destroyed" << std::endl;
}
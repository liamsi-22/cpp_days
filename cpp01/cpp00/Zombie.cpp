#include "Zombie.hpp"

Zombie::Zombie(): _name("zombie"){}

Zombie::Zombie(std::string zombieName): _name(zombieName){}

void Zombie::announce( void ){
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(){
    std::cout << _name << " has been destroyed" << std::endl;
}
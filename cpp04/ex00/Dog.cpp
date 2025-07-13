#include "Dog.hpp"

Dog::Dog(): Animal("Dog"){
    // this->type = "Dog";
    std::cout << "Derived class Constructor of type " << this->type << " is being called" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other){
}

Dog& Dog::operator=(const Dog& other){
    if (this != &other)
        Animal::operator=(other);
    return (*this);
}

void Dog::makeSound() const{
    std::cout << "Baark" << std::endl;
}

Dog::~Dog(){
    std::cout << "derived class Destructor of type " << this->type << " is being called" << std::endl;
}

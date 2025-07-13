#include "Cat.hpp"

Cat::Cat(): Animal("Cat"){
    std::cout << "derived class Constructor of type " << this->type << " is being called" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other){
}

Cat& Cat::operator=(const Cat& other){
    if (this != &other)
        Animal::operator=(other);
    return (*this);
}

void Cat::makeSound() const{
    std::cout << "Meoow" << std::endl;
}

Cat::~Cat(){
    std::cout << "derived class Destructor of type " << this->type << " is being called" << std::endl;
}
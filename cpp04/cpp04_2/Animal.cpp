#include "Animal.hpp"


Animal::Animal():type("Animal"){
    std::cout << "Base class Constructor of type " << this->type << " is being called" << std::endl;
}

Animal::Animal(std::string type): type(type){
    std::cout << "Base class Constructor of type " << this->type << " is being called" << std::endl;
}

Animal::Animal(const Animal& other): type(other.type){
}

Animal& Animal::operator=(const Animal& other){
    if (this != &other)
        this->type = other.type;
    return (*this);
}

std::string Animal::getType() const{
    return (this->type);
}

void Animal::makeSound() const{
    std::cout << "make a noice" << std::endl;
}

Animal::~Animal(){
    std::cout << "Base class Destructor of type " << this->type << " is being called" << std::endl;
}
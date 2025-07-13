#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("Animal"){
    std::cout << "Base class Constructor of type " << this->type << " is being called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type): type(type){
    std::cout << "Base class Constructor of type " << this->type << " is being called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other): type(other.type){
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other){
    if (this != &other)
        this->type = other.type;
    return (*this);
}

std::string WrongAnimal::getType() const{
    return (this->type);
}

void WrongAnimal::makeSound() const{
    std::cout << "make a noice" << std::endl;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "Base class Destructor of type " << this->type << " is being called" << std::endl;
}
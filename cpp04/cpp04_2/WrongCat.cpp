#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("Cat"){
    std::cout << "derived class Constructor of type " << this->type << " is being called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other){
}

WrongCat& WrongCat::operator=(const WrongCat& other){
    if (this != &other)
        WrongAnimal::operator=(other);
    return (*this);
}

void WrongCat::makeSound() const{
    std::cout << "Meoow" << std::endl;
}

WrongCat::~WrongCat(){
    std::cout << "derived class Destructor of type " << this->type << " is being called" << std::endl;
}
#include "Cat.hpp"

Cat::Cat(): Animal("Cat"){
    std::cout << "derived class Constructor of type " << this->type << " is being called" << std::endl;
    this->brain = new Brain();
}

Cat::Cat(const Cat& other): Animal(other){
    std::cout << "Copy constructor of Cat called" << std::endl;
    this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other){
    if (this != &other)
    {
        Animal::operator=(other);
        delete (this->brain);
        this->brain = new Brain(*other.brain);
    }
    return (*this);
}

void Cat::makeSound() const{
    std::cout << "Meoow" << std::endl;
}

Cat::~Cat(){
    std::cout << "derived class Destructor of type " << this->type << " is being called" << std::endl;
    delete (this->brain);
}
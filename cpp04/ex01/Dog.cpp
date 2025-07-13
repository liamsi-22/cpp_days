#include "Dog.hpp"

Dog::Dog(): Animal("Dog"){
    std::cout << "Derived class Constructor of type " << this->type << " is being called" << std::endl;
    this->brain = new Brain();
}

Dog::Dog(const Dog& other): Animal(other){
    std::cout << "Copy constructor of Dog called" << std::endl;
    this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other){
    if (this != &other)
    {
        Animal::operator=(other);
        delete (this->brain);
        this->brain = new Brain(*other.brain);
    }
    return (*this);
}

void Dog::makeSound() const{
    std::cout << "Baark" << std::endl;
}

Dog::~Dog(){
    std::cout << "derived class Destructor of type " << this->type << " is being called" << std::endl;
    delete (this->brain);
}

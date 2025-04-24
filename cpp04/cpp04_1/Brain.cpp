#include "Brain.hpp"

Brain::Brain(){
    for (int i = 0; i < BRAIN_SIZE; i++)
        this->ideas[i] = "Empty";
    std::cout << "Constructor of the Brain class is being called" << std::endl;
}

Brain::Brain(const Brain& other){
    for (int i = 0; i < BRAIN_SIZE; i++)
        this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other){
    if (this != &other)
    {
        for (int i = 0; i < BRAIN_SIZE; i++)
            this->ideas[i] = other.ideas[i];
    }
    return (*this);
}

Brain::~Brain(){
    std::cout << "Destructor of the Brain class is being called" << std::endl;
}
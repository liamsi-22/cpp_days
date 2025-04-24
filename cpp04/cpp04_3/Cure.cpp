#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure() : AMateria("cure") {
    std::cout << "Cure of type " << getType() << " created." << std::endl;
}

Cure::Cure(std::string const & type) :  AMateria(type) {
    std::cout << "Cure of type " << getType() << " created." << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other.getType()){
    std::cout << "Cure of type " << getType() << " copied." << std::endl;
}

Cure& Cure::operator=(const Cure& other) {
    if (this != &other) {
        AMateria::operator=(other);
        std::cout << "Cure of type " << other.getType() << " assigned." << std::endl;
    }
    return *this;
}

AMateria* Cure::clone() const{
    return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}

Cure::~Cure() {
    std::cout << "Cure of type " << getType() << " destroyed." << std::endl;
}
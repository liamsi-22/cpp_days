#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria() : _type("Default"){
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const & type) : _type(type) {
    std::cout << "AMateria of type " << _type << " created." << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other.getType()) {
    std::cout << "AMateria of type " << _type << " copied." << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other) {
    if (this != &other) {
        std::cout << "AMateria of type " << getType() << " assigned." << std::endl;
    }
    return *this;
}

std::string const& AMateria::getType() const {
    return _type;
}

void AMateria::use(ICharacter& target){
    std::cout << "nothing to display , none instantiated class" << std::endl;
}

AMateria::~AMateria() {
    std::cout << "AMateria of type " << getType() << " destroyed." << std::endl;
}
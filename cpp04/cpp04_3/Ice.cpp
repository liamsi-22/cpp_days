#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice() : AMateria("ice"){
    std::cout << "Ice of type " << getType() << " created." << std::endl;
}

Ice::Ice(std::string const & type) : AMateria(type) {
    std::cout << "Ice of type " << getType() << " created." << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other.getType()) {
    std::cout << "Ice of type " << getType() << " copied." << std::endl;
}

Ice& Ice::operator=(const Ice& other) {
    if (this != &other) {
        AMateria::operator=(other);
        std::cout << "Ice of type " << other.getType() << " assigned." << std::endl;
    }
    return *this;
}
AMateria* Ice::clone() const{
    return (new Ice(*this));
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

Ice::~Ice() {
    std::cout << "Ice of type " << getType() << " destroyed." << std::endl;
}
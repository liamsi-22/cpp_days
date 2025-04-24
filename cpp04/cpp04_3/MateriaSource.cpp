#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource(){
    for (int i = 0; i < 4; ++i)
        _templates[i] = NULL;
    std::cout << "MateriaSource constructed is being called" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& other){
    for (int i = 0; i < 4; ++i)
        _templates[i] = other._templates[i]->clone();
    std::cout << "MateriaSource copy constructed is being called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other){
    if (this != &other)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (_templates[i])
                delete _templates[i];

            if (other._templates[i])
                _templates[i] = other._templates[i]->clone();
        }
    }
    return (*this);
}

void MateriaSource::learnMateria(AMateria* materia){
    if (!materia)
        return;
    for (int i = 0; i < 4; ++i)
    {
        if (!_templates[i])
        {
            _templates[i] = materia->clone();
            break;
        }
    }    
}

AMateria* MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < 4; ++i)
    {
        if (_templates[i] && _templates[i]->getType() == type)
            return (_templates[i]->clone());
    }
    return (0);
}

MateriaSource::~MateriaSource(){
    for (int i = 0; i < 4; ++i)
    {
        if(_templates[i])
            delete _templates[i];
    }
    std::cout << "MateriaSource Destructor is being called" << std::endl;
}
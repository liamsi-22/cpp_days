#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():  AForm("default_shrubbery", 145, 137){
    std::cout << "PresidentialPardonForm default constructor is being called !" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):  AForm("PresidentialPardon", 145, 137), _target(target){}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): AForm(other), _target(other.getTarget()){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other.getTarget();
    }
    return (*this);
}

std::string PresidentialPardonForm::getTarget() const{
    return (_target);
}

void  PresidentialPardonForm::action() const {
    std::cout << _target << " you have been pardoned by Zaphod Beeblebrox !" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "PresidentialPardonForm Destrcutor being called !" << std::endl;
}

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():  Form("default_shrubbery", 145, 137){
    std::cout << "PresidentialPardonForm default constructor is being called !" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):  Form("PresidentialPardon", 145, 137), _target(target){
    std::cout << getName() <<" parameterized constructor called !" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other): _target(other.getTarget()){}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
    if (this != &other)
        _target = other.getTarget();
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

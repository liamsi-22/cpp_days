#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():  Form("default_shrubbery", 145, 137){
    std::cout << "RobotomyRequestForm default constructor is being called !" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):  Form("RobotomyRequest", 72, 45), _target(target){
    std::cout << getName() <<" parameterized constructor called !" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other): _target(other.getTarget()){}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
    if (this != &other)
        _target = other.getTarget();
    return (*this);
}

std::string RobotomyRequestForm::getTarget() const{
    return (_target);
}

void  RobotomyRequestForm::action() const {
    std::cout << "Wroaaaaar... !!!" << std::endl;
    if (rand() % 2)
        std::cout << _target << " has been robotomized successfully!" << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "." << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm Destrcutor being called !" << std::endl;
}

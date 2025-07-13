#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():  AForm("default_shrubbery", 145, 137){
    std::cout << "ShrubberyCreationForm default constructor is being called !" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):  AForm("ShrubberyCreation", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), _target(other.getTarget()){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other.getTarget();
    }
    return (*this);
}

std::string ShrubberyCreationForm::getTarget() const{
    return (_target);
}

void  ShrubberyCreationForm::action() const {
    std::ofstream file(_target + "_shrubbery");
    std::cout <<"      &&& &&  & &&" << std::endl;
    std::cout <<"   && &||&||& ()|/ @, &&" << std::endl;
    std::cout <<"   &||(/&/&||/& /_/)_&/_&" << std::endl;
    std::cout <<"&() &||&|()|/&|| '%' & ()" << std::endl;
    std::cout <<"&_||&_/&&& | & |&&/&__%_/_& &&" << std::endl;
    std::cout <<"&&   && & &| &| /& & % ()& /&&" << std::endl;
    std::cout <<" ()&_---()&|&||&&-&&--%---()~" << std::endl;
    std::cout <<"     &&     ||||" << std::endl;
    std::cout <<"              |||" << std::endl;
    std::cout <<"              |||" << std::endl;
    std::cout <<"              |||" << std::endl;
    std::cout <<"        , -=-~  .-^- _" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm Destrcutor being called !" << std::endl;
}

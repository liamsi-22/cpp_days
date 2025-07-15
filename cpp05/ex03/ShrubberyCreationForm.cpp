#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():  Form("default_shrubbery", 145, 137){
    std::cout << "ShrubberyCreationForm default constructor is being called !" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):  Form("ShrubberyCreation", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): Form(other), _target(other.getTarget()){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
    if (this != &other)
    {
        Form::operator=(other);
        _target = other.getTarget();
    }
    return (*this);
}

std::string ShrubberyCreationForm::getTarget() const{
    return (_target);
}

void  ShrubberyCreationForm::action() const {
    std::ofstream file((_target + "_shrubbery").c_str());
    if (!file){
        std::cerr << "Failed to open file.\n";
        return ;
    }
    file <<"      &&& &&  & &&" << std::endl;
    file <<"   && &||&||& ()|/ @, &&" << std::endl;
    file <<"   &||(/&/&||/& /_/)_&/_&" << std::endl;
    file <<"&() &||&|()|/&|| '%' & ()" << std::endl;
    file <<"&_||&_/&&& | & |&&/&__%_/_& &&" << std::endl;
    file <<"&&   && & &| &| /& & % ()& /&&" << std::endl;
    file <<" ()&_---()&|&||&&-&&--%---()~" << std::endl;
    file <<"     &&     ||||" << std::endl;
    file <<"              |||" << std::endl;
    file <<"              |||" << std::endl;
    file <<"              |||" << std::endl;
    file <<"        , -=-~  .-^- _" << std::endl;
    file.close();
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm Destrcutor being called !" << std::endl;
}

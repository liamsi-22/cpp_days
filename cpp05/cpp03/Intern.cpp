#include "Intern.hpp"

Intern::Intern(){
    std::cout << "Intern default constructor is being called !" << std::endl;
}

Intern::Intern(const Intern& other){}

Intern& Intern::operator=(const Intern& other){
    return (*this);
}

Form* Intern::createRobotomy(const std::string& target){
    return new RobotomyRequestForm(target);
}

Form* Intern::createShrubbery(const std::string& target){
    return new ShrubberyCreationForm(target);
}

Form* Intern::createPresidential(const std::string& target){
    return new PresidentialPardonForm(target);
}

Form* Intern::makeForm(const std::string& formName, const std::string& target){
    std::string forms[] = {"robotomy request", "shrubbery creation", "presidential pardon"};
    Form* (*ptr[])(const std::string& target) = {createRobotomy, createShrubbery, createPresidential};

    for (int i = 0; i < 3; ++i)
    {
        if (forms[i] == formName)
            return (ptr[i](target));
    }
    throw (NoFormWithThatName());
}

const char* Intern::NoFormWithThatName::what() const throw(){
    return ("No Form Exist With That Name !");
}

Intern::~Intern(){
    std::cout << "Intern default Destructor is being called !" << std::endl;
}

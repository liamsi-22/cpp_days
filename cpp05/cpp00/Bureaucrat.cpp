#include "Bureaucrat.hpp"

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b){
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return (os);
}

Bureaucrat::Bureaucrat(): _name("Bureaucrat"), _grade(75){
    std::cout << "Bureaucrat default constructor called !" << std::endl;
}

Bureaucrat::Bureaucrat(int grade, const std::string& name): _name(name), _grade(grade){
    if (grade < 1)
        throw (GradeTooHighException());
    else if (grade > 150)
        throw (GradeTooLowException());
    std::cout << "Bureaucrat parameterized constructor called !" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade){}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    if (this != &other)
        _grade = other._grade;
    return (*this);
}

std::string Bureaucrat::getName() const {
    return (_name);
}

int Bureaucrat::getGrade() const{
    return (_grade);
}

void Bureaucrat::promote(){
    if (_grade <= 1)
        throw(GradeTooHighException());
    _grade--;
}

void Bureaucrat::demote(){
    if (_grade >= 150)
        throw(GradeTooLowException());
    _grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return ("Grade Too High Exception !");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return ("Grade Too Low Exception !");
}

Bureaucrat::~Bureaucrat(){
        std::cout << _name  << "'s Destructor called !" << std::endl;
}
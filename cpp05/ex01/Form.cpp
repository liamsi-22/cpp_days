#include "Form.hpp"

std::ostream& operator<<(std::ostream& os, const Form& f){
   os << "Form Name: " << f.getName() << "\n"
       << "Signed: " << (f.getSigned() ? "Yes" : "No") << "\n"
       << "Grade required to sign: " << f.getGradeToSign() << "\n"
       << "Grade required to execute: " << f.getGradeToExec();
    return os;
}

Form::Form():_name("Form"), _signed(0), _gradeToSign(10), _gradeToexec(50){
    std::cout << "Form default constructor is called !" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToexec): _name(name), _signed(0), _gradeToSign(gradeToSign), _gradeToexec(gradeToexec){
    std::cout << "Form parameterized constructor called !" << std::endl;
    if (gradeToexec < 1 || gradeToSign < 1)
        throw (GradeTooHighException());
    else if (gradeToexec > 150 || gradeToSign > 150)
        throw (GradeTooLowException());
}

Form::Form(const Form& other): _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToexec(other._gradeToexec){}

Form& Form::operator=(const Form& other){
    if (this != &other)
        _signed = other._signed;
    return (*this);
}

std::string Form::getName() const{
    return (_name);
}

bool Form::getSigned() const{
    return (_signed);
}

int Form::getGradeToSign() const{
    return (_gradeToSign);
}

int Form::getGradeToExec() const{
    return (_gradeToexec);
}

void Form::beSigned(const Bureaucrat& b){
    if (b.getGrade() <= _gradeToSign)
    {
        if (!_signed)
            _signed = true;
    }
    else
        throw(SignedGradeTooLowException());
}

const char* Form::GradeTooHighException::what() const throw(){
    return ("Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw(){
    return ("Grade is too low!");
}

const char* Form::SignedGradeTooLowException::what() const throw(){
    return ("Grade is too low to signed the form!");
}

Form::~Form(){
    std::cout << _name << "'s destructor is being called !" << std::endl;
}

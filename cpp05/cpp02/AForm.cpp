#include "AForm.hpp"

std::ostream& operator<<(std::ostream& os, const AForm& f){
   os << "AForm Name: " << f.getName() << "\n"
       << "Signed: " << (f.getSigned() ? "Yes" : "No") << "\n"
       << "Grade required to sign: " << f.getGradeToSign() << "\n"
       << "Grade required to execute: " << f.getGradeToExec();
    return os;
}

AForm::AForm():_name("AForm"), _signed(false), _gradeToSign(10), _gradeToexec(50){
    std::cout << "AForm default constructor is called !" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToexec): _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToexec(gradeToexec){
    if (gradeToexec < 1 || gradeToSign < 1)
        throw (GradeTooHighException());
    else if (gradeToexec > 150 || gradeToSign > 150)
        throw (GradeTooLowException());
    std::cout << "AForm  parameterized constructor called !" << std::endl;
}

AForm::AForm(const AForm& other): _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToexec(other._gradeToexec){}

AForm& AForm::operator=(const AForm& other){
    if (this != &other)
        _signed = other._signed;
    return (*this);
}

std::string AForm::getName() const{
    return (_name);
}

bool AForm::getSigned() const{
    return (_signed);
}

int AForm::getGradeToSign() const{
    return (_gradeToSign);
}

int AForm::getGradeToExec() const{
    return (_gradeToexec);
}

void AForm::beSigned(const Bureaucrat& b){
    if (b.getGrade() <= _gradeToSign)
        _signed = true;
    else
        throw(GradeTooLowException());
}

void AForm::execute(Bureaucrat const & executor) const{
    if (executor.getGrade() > this->getGradeToExec())
        throw(ExecutionGradeTooLowException());
    if (!this->getSigned())
        throw(NotSignedFormException());
    return (this->action());
}

const char* AForm::GradeTooHighException::what() const throw(){
    return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw(){
    return ("Grade is too low!");
}

const char* AForm::NotSignedFormException::what() const throw(){
    return ("Form is not signed yet!");
}

const char* AForm::ExecutionGradeTooLowException::what() const throw(){
    return ("Grade is too low to execute the form!");
}

AForm::~AForm(){
    std::cout << "AForm destructor is being called !" << std::endl;
}

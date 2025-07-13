#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Form;

std::ostream& operator<<(std::ostream& os, const Form& f);

class Form
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToexec;

    public:
        Form();
        Form(const std::string& name, int gradeToSign, int gradeToexec);
        Form(const Form& other);
        Form& operator=(const Form& other);

        std::string getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExec() const;

        void beSigned(const Bureaucrat& b);

        class GradeTooHighException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class SignedGradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        ~Form();
};

#endif
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

    protected:
        virtual void  action() const;

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

        void execute(Bureaucrat const & executor) const;

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

        class NotSignedFormException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        class ExecutionGradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        virtual ~Form();
};

#endif
#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class AForm;

std::ostream& operator<<(std::ostream& os, const AForm& f);

class AForm
{
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToexec;

    protected:
        virtual void  action() const = 0;

    public:
        AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToexec);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);

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

        class SignedGradeTooLowException : public std::exception
        {
            public:
                const char* what() const throw();
        };

        virtual ~AForm();
};

#endif
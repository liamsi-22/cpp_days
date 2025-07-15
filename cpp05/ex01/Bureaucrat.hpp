#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

// #pragma => once work the same as header guards
#include <iostream>
#include <string>
#include <exception>

class Form;
class Bureaucrat;

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(int grade,const std::string& name);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);

        std::string getName() const;
        int getGrade() const;

        void promote();
        void demote();

        void signForm(Form& f);

        class GradeTooHighException : public std::exception{
            public :
                const char* what() const throw();
        };

        class GradeTooLowException : public std::exception{
            public :
                const char* what() const throw();
        };
        ~Bureaucrat();
};

#endif
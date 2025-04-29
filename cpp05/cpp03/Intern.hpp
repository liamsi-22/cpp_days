#ifndef INTERN_HPP
#define INTERN_HPP

#include <exception>
#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);

        static Form* createRobotomy(const std::string& target);
        static Form* createShrubbery(const std::string& target);
        static Form* createPresidential(const std::string& target);

        Form* makeForm(const std::string& formName, const std::string& target);

        class NoFormWithThatName : public std::exception
        {
            public:
                const char* what() const throw();
        };

        ~Intern();
};

#endif
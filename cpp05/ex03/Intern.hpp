#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Form.hpp"

#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

class Intern
{
    private:
        static Form* createRobotomy(const std::string& target);
        static Form* createShrubbery(const std::string& target);
        static Form* createPresidential(const std::string& target);

    public:
        Intern();
        Intern(const Intern& other);
        Intern& operator=(const Intern& other);


        Form* makeForm(const std::string& formName, const std::string& target);

        class NoFormWithThatName : public std::exception
        {
            public:
                const char* what() const throw();
        };

        ~Intern();
};

#endif
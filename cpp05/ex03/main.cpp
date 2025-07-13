#include <iostream>
#include "Form.hpp"
#include "Intern.hpp"


int main(){

    try{
        Intern someRandomIntern;
        Bureaucrat boss(10, "CEO");
        Form* ptr;
        ptr = someRandomIntern.makeForm("shrubbery creation", "Bender");
        boss.signForm(*ptr);
        boss.executeForm(*ptr);
        delete ptr;
    }catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
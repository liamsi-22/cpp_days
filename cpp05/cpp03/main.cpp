#include <iostream>
#include "Form.hpp"
#include "Intern.hpp"

int main(){
    try{
        Intern someRandomIntern;
        Form* ptr;
        ptr = someRandomIntern.makeForm("robotomy request", "Bender");
        delete ptr;
    }catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return (0);
}
#include <exception>
#include <iostream>
#include <ctime> 

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main(){
    // srand(time(NULL));
    Bureaucrat bureaucrat(10,"slave");
    Bureaucrat bureaucrat2(150,"slave2");
    AForm* form = new ShrubberyCreationForm("Home");
    try{
        form->beSigned(bureaucrat);
        form->execute(bureaucrat);
        // bureaucrat2.executeForm(*form);
    }catch (const std::exception& e){
        std::cout << e.what() << std::endl;
    }
    delete form;
    return (0);
}

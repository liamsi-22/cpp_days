#include "Bureaucrat.hpp"

int main(){
    try{
        Bureaucrat employee(2, "ismail");
        std::cout << employee << std::endl;
        employee.promote();
        std::cout << employee << std::endl;
        employee.promote();
    }catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    // catch (const Bureaucrat::GradeTooHighException& G_T_H)
    // // {
    //     std::cout << G_T_H.what() << std::endl;
    // }catch (const Bureaucrat::GradeTooLowException& G_T_L)
    // {
    //     std::cout << G_T_L.what() << std::endl;
    // }

}
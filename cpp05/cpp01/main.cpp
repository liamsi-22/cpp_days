#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
    try{
        Bureaucrat employee(10, "ismail");
        std::cout << employee << std::endl;
        Form form("normal_form", 20, 50);
        // employee.signForm(form);
        std::cout << form.getSigned() << std::endl;
        // form.beSigned(employee);
        employee.signForm(form);
        employee.signForm(form);
        employee.signForm(form);
        std::cout << form.getSigned() << std::endl;
        // Form form2(form);
        // std::cout << form << std::endl;
        // std::cout << form2 << std::endl;
        // form.beSigned(employee);
        // std::cout << form << std::endl;
        // std::cout << form2 << std::endl;
        // form2 = form;
        // std::cout << form << std::endl;
        // std::cout << form2 << std::endl;
    }catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
}
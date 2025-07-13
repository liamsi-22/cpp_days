#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    srand(time(NULL));
    Bureaucrat boss(1, "BigBoss");
    Bureaucrat intern(150, "Intern");

    ShrubberyCreationForm tree("Home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Marvin");

    try {
        boss.signForm(tree);
        boss.executeForm(tree);
    } catch (const std::exception& e) {
        std::cerr << "Tree Error: " << e.what() << std::endl;
    }

    try {
        boss.signForm(robot);
        boss.executeForm(robot);
    } catch (const std::exception& e) {
        std::cerr << "Robot Error: " << e.what() << std::endl;
    }

    try {
        intern.signForm(pardon);
        intern.executeForm(pardon);
    } catch (const std::exception& e) {
        std::cerr << "Pardon Error: " << e.what() << std::endl;
    }

    return 0;
}

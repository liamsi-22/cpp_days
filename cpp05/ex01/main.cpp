#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat alice(50,"Alice");
        Form contract("Secret Contract", 45, 20);

        std::cout << contract << std::endl;

        contract.beSigned(alice);

        std::cout << contract << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    try {
        Bureaucrat bob(10, "Bob");
        Form form("Top Secret", 15, 10);
        
        std::cout << bob << std::endl;

        bob.signForm(form);
        
        std::cout << bob << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat bob(1,"Bob");
        std::cout << bob << std::endl;

        bob.promote();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try {
        Bureaucrat joe(150,"Joe");
        std::cout << joe << std::endl;

        joe.demote();
    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

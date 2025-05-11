#include "Harl.hpp"

int main(int ac, char **av){
    std::string state;
    Harl hrl;

    if (ac == 2)
    {
        state = av[1];
        hrl.complain(state);
    }
    return (0);
}
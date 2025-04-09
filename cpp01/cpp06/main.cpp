#include "Harl.hpp"

int main(int ac, char **av){
    std::string arg;
    Harl hrl;
    if (ac == 2)
    {
        arg = av[1];
        hrl.complain(arg);
    }
    return (0);
}
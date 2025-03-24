#include <iostream>

void ToUpper(std::string &str)
{
    size_t i;

    for (i = 0; i < str.length(); i++)
    {
        str.at(i) = std::toupper(str.at(i));
    }
}

int main(int ac, char **av)
{
    int i;
    std::string arg;

    i = 1;
    if (ac == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    else
    {
        for (i = 1; i < ac; i++)
        {
            arg = av[i];
            ToUpper(arg);
            std::cout << arg;
            if (i != ac - 1) std::cout << " ";
        }
    }
    std::cout << std::endl;
    return (0);
}
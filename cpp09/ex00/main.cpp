#include "BitcoinExchange.hpp"

int main(int ac, char **av){
    if (ac != 2)
    {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    else{
        try
        {
            BitcoinExchange btc;
            btc.loadDatabase("data.csv");
            btc.processInput(av[1]);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
    }
    return (0);
}
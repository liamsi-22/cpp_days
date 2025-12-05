#ifndef BITCOINEXCHANGE_CPP
#define BITCOINEXCHANGE_CPP

#include <iostream>
#include <map>
#include <fstream>
#include <climits>
#include <algorithm>

class BitcoinExchange
{
private:
    std::map<std::string, double> _db;

public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    BitcoinExchange &operator=(const BitcoinExchange &other);
    ~BitcoinExchange();

    void loadDatabase(const std::string &csvFile);
    void processInput(const std::string &inputFile);
};

#endif
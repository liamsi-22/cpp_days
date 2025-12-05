#include "BitcoinExchange.hpp"
#include <cstdlib>
std::string trim(const std::string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (first == std::string::npos)
        return "";

    size_t last = str.find_last_not_of(' ');
    return str.substr(first, last - first + 1);
}
// ! remove the usless deli parameter
bool isValidDate(const std::string &date, char deli){
    int i = -1;
    while (date[++i])
    {
        if (!std::isdigit(date[i]) && date[i] != deli && date[i] != '-')
            return (false);
        if (date[i] == deli && date[i + 1] == deli)
            return (false);
    }
    if (date[0] == deli || date[date.length() - 1] == deli)
        return (false);
    if (std::count(date.begin(), date.end(), deli) != 2)
        return (false);
    size_t first_pos = date.find(deli);
    size_t second_pos = date.find(deli , first_pos + 1);

    std::string YEAR = date.substr(0, first_pos);
    std::string MONTH = date.substr(first_pos + 1, second_pos - (first_pos + 1));
    std::string DAY = date.substr(second_pos + 1);

    if (YEAR.length() != 4 || MONTH.length() != 2 || DAY.length() != 2)
        return (false);
    int y = atoi(YEAR.c_str());
    int m = atoi(MONTH.c_str());
    int d = atoi(DAY.c_str());

    if (y < 2009 || y > 2022)
        return false;
    if (m < 1 || m > 12)
        return false;
    if (d < 1 || d > 31)
        return false;
    return (true);
}
// ! this one for the DB 
bool isValidPrice(const std::string &pricestr){
    if (pricestr[0] == '-')
        return (false);
    int i = -1;
    int counter = 0;
    while (pricestr[++i])
    {
        if (!std::isdigit(pricestr[i]) && pricestr[i] != '.')
            return (false);
        if (pricestr[i] == '.')
            counter++;
    }
    if (counter > 1 || atof(pricestr.c_str()) > INT_MAX)
        return (false);
    return (true);
}

// put the prototype in header file 
// ! this one for input file 
bool isValidValue(const std::string &pricestr){
    int i = -1;
    int counter = 0;
    while (pricestr[++i])
    {
        if (!std::isdigit(pricestr[i]) && pricestr[i] != '.')
        {
            if (i == 0 && pricestr[i] != '-')
                return (false);
        }
        if (pricestr[i] == '.')
            counter++;
    }
    if (counter > 1)
        return (false);
    return (true);
}


BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other): _db(other._db){}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other){
    if (this != &other)
        _db = other._db;
    return (*this);
}

BitcoinExchange::~BitcoinExchange(){}

void BitcoinExchange::loadDatabase(const std::string &csvFile){
    std::ifstream file(csvFile.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(file, line);
    if (line.empty())
        throw std::runtime_error("Error: empty file.");
    while (std::getline(file, line))
    {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            throw std::runtime_error("Error: wrong file format.");

        std::string date = trim(line.substr(0, pos));
        std::string pricestr = trim(line.substr(pos + 1));

        if (date.empty() || pricestr.empty() || !isValidDate(date, '-') || !isValidPrice(pricestr))
            throw std::runtime_error("Error: wrong file format.");

        _db[date] = atof(pricestr.c_str());
    }
    file.close();
}

void BitcoinExchange::processInput(const std::string &inputFile){
    std::ifstream file2(inputFile.c_str());
    if (!file2.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(file2, line);
    if (line.empty())
        throw std::runtime_error("Error: empty file.");
    while(std::getline(file2, line))
    {
        size_t pos = line.find('|');
        if (pos == std::string::npos)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = trim(line.substr(0, pos));
        std::string value = trim(line.substr(pos + 1));

        if (date.empty() || value.empty() || !isValidDate(date, '-') || !isValidValue(value))
            std::cout << "Error: bad input => " << line << std::endl;
        else if (value[0] == '-')
            std::cout << "Error: not a positive number." << std::endl;
        else if (atof(value.c_str()) > INT_MAX)
            std::cout << "Error: too large a number." << std::endl;
        else
        {
            std::map<std::string, double>::iterator it = _db.lower_bound(date);
            if (it == _db.end())
                it--;
            else if (it->first != date)
            {
                if (it == _db.begin())
                    std::cout << "Error: bad input => " << line << std::endl;
                it--;
            }
            std::cout << date << " => " << value << " = " << ( atof(value.c_str()) * it->second) << std::endl;
        }

    }
    file2.close();
}

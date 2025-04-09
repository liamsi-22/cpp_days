#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <sstream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;



Account::Account(int initial_deposit)
:_accountIndex(_nbAccounts),
 _amount(initial_deposit),
 _nbDeposits(0),
 _nbWithdrawals(0) {

     Account::_nbAccounts++;
    Account::_totalAmount += initial_deposit;

    Account::_displayTimestamp();
    std::cout << " index:" << Account::_accountIndex 
            << ";amount:" << Account::_amount 
            << ";created" << std::endl;
}

int Account::getNbAccounts( void ){
    return (_nbAccounts);
}

int	Account::getTotalAmount( void ){
    return (_totalAmount);
}

int	Account::getNbDeposits( void ){
    return (_totalNbDeposits);
}


int	Account::getNbWithdrawals( void ){
    return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void ){
    Account::_displayTimestamp();
    std::cout << " accounts:" << _nbAccounts
                << ";total:" << _totalAmount
                << ";deposits:" << _totalNbDeposits 
                << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void ){
        std::time_t now = std::time(0);  // Get current time
        std::tm* timeinfo = std::localtime(&now);  // Convert it to local time
    
        // Manually format the timestamp using ternary operator for padding
        std::ostringstream oss;
        oss << "[" 
            << (1900 + timeinfo->tm_year)
            << (timeinfo->tm_mon + 1 < 10 ? "0" : "") << (timeinfo->tm_mon + 1)
            << (timeinfo->tm_mday < 10 ? "0" : "") << timeinfo->tm_mday
            << "_"
            << (timeinfo->tm_hour < 10 ? "0" : "") << timeinfo->tm_hour
            << (timeinfo->tm_min < 10 ? "0" : "") << timeinfo->tm_min
            << (timeinfo->tm_sec < 10 ? "0" : "") << timeinfo->tm_sec
            << "]";
    
        std::cout << oss.str();
    }



void	Account::makeDeposit( int deposit ){
    Account::_displayTimestamp();
    std::cout << " index:" << _accountIndex
                << ";p_amount:" << _amount
                << ";deposit:" << deposit;
    Account::_totalAmount += deposit;
    Account::_totalNbDeposits++;
    _nbDeposits++;
    _amount += deposit;
    std::cout << ";amount:" << _amount
                << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ){
    Account::_displayTimestamp();
    std::cout << " index:" << _accountIndex
                << ";p_amount:" << _amount;
    if (_amount < withdrawal)
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return (false);
    }
    Account::_totalAmount -= withdrawal;
    Account::_totalNbWithdrawals++;
    _nbWithdrawals++;
    _amount -= withdrawal;
    std::cout << ";withdrawal:" << withdrawal 
                << ";amount:" << _amount 
                << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return (true);
}

int		Account::checkAmount( void ) const {
    return (_amount);
}

void	Account::displayStatus( void ) const {
    Account::_displayTimestamp();
    std::cout << " index:" << _accountIndex 
            << ";amount:" << _amount 
            << ";deposits:" << _nbDeposits 
            << ";withdrawals:" << _nbWithdrawals << std::endl;
}


Account::~Account( void ){
    Account::_displayTimestamp();
    std::cout << " index:" << Account::_accountIndex 
            << ";amount:" << Account::_amount 
            << ";closed" << std::endl;
}
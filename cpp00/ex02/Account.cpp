#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

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
    std::cout << " index:" << _accountIndex 
            << ";amount:" << _amount 
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

void Account::_displayTimestamp(void) {
    std::time_t now = std::time(0);
    std::tm* t = std::localtime(&now);

    std::cout << '['
              << (1900 + t->tm_year)
              << std::setw(2) << std::setfill('0') << t->tm_mon + 1
              << std::setw(2) << t->tm_mday << '_'
              << std::setw(2) << t->tm_hour
              << std::setw(2) << t->tm_min
              << std::setw(2) << t->tm_sec
              << ']';
}

void	Account::makeDeposit( int deposit ){
    _displayTimestamp();
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
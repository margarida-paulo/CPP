#include "Account.hpp"
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts(void){
	return _nbAccounts;
}

int Account::getTotalAmount(void){
	return _totalAmount;
}

int Account::getNbDeposits(void){
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void){
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void){
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount <<";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initial_deposit){
	_displayTimestamp();
	std::cout << "index:" << _nbAccounts << ";amount:" << initial_deposit << ";created" << std::endl;
	this->_accountIndex = _nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account(void){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
	_nbAccounts--;
}

void Account::makeDeposit(int deposit){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount+=deposit;
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (this->_amount - withdrawal < 0){
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "amount:" << this->_amount << ";";
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "nb_withdrawals:" << this->_nbDeposits << std::endl;	
	return true;
}

void Account::displayStatus(void) const{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void){
    // Buffer to hold the formatted timestamp
    char buffer[19];

    // Get current time
    time_t currentTime = time(0); // Corrected

    // Convert to local time
    tm* localTime = localtime(&currentTime); // Corrected

    // Format the time into the buffer
    strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", localTime); // Corrected

    // Output the formatted timestamp
    std::cout << buffer;
}
#include "Account.hpp"
#include <iostream>
#include <ctime>

using std::cout;
using std::endl;

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int init) {
	_accountIndex = _nbAccounts++;
	_amount = init;
	_totalAmount += init;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";";
	cout << "amount:" << _amount << ";";
	cout << "created" << endl;
}

Account::~Account(void) {
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";";
	cout << "amount:" << _amount << ";";
	cout << "closed" << endl;
}

int	Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
	return _totalAmount;
}

int	Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

int		Account::checkAmount( void ) const {
	return _amount;
}

void	Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	cout << "accounts:" << _nbAccounts << ";";
	cout << "total:" << _totalAmount << ";";
	cout << "deposits:" << _totalNbWithdrawals << ";";
	cout << "withdrawals:" << _totalNbDeposits << endl;
}

void	Account::makeDeposit( int deposit ) {
	int	p_amount;

	p_amount = _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbWithdrawals++;
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";";
	cout << "p_amount:" << p_amount << ";";
	cout << "deposit:" << deposit << ";";
	cout << "amount:" << _amount << ";";
	cout << "nb_deposits:" << _nbDeposits << endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";";
	cout << "p_amount:" << _amount << ";";
	if (_amount - withdrawal < 0) {
		cout << "withdrawal:" << "refused" << endl;
		return false;
	}
	cout << "withdrawal:" << withdrawal << ";";
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbDeposits++;
	cout << "amount:" << _amount << ";";
	cout << "nb_withdrawals:" << _nbWithdrawals << endl;
	return true;
}

void	Account::displayStatus( void ) const {
	_displayTimestamp();
	cout << "index:" << _accountIndex << ";";
	cout << "amount:" << _amount << ";";
	cout << "deposits:" << _nbDeposits << ";";
	cout << "withdrawals:" << _nbWithdrawals << endl;
}

void	Account::_displayTimestamp( void ) {
	time_t	current_time;
	struct tm	*tm;

	time(&current_time);
	tm = localtime(&current_time);
	cout << "[" << tm->tm_year + 1900;
	if (tm->tm_mon + 1 < 10)
		cout << "0";
	cout << tm->tm_mon + 1;
	if (tm->tm_mday < 10)
		cout << "0";
	cout << tm->tm_mday << "_";
	if (tm->tm_hour < 10)
		cout << "0";
	cout << tm->tm_hour;
	if (tm->tm_min < 10)
		cout << "0";
	cout << tm->tm_min;
	if (tm->tm_sec < 10)
		cout << "0";
	cout << tm->tm_sec << "] ";
}


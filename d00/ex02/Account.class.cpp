#include <Account.class.hpp>
#include <iostream>
#include <ctime>

Account::Account(int dep) {
	_accountIndex = _nbAccounts++;
	_amount = dep;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_totalAmount += dep;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account() {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

int			Account::_nbAccounts = 0;
int			Account::_totalAmount = 0;
int			Account::_totalNbDeposits = 0;
int			Account::_totalNbWithdrawals = 0;

int			Account::getNbAccounts() {
	return _nbAccounts;
}

int			Account::getTotalAmount() {
	return _totalAmount;
}

int			Account::getNbDeposits() {
	return _totalNbDeposits;
}

int			Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void		Account::_displayTimestamp() {
  time_t		rawtime;
  struct tm		*ti;

  time(&rawtime);
  ti = localtime(&rawtime);
  std::cout << "[";
  std::cout << ti->tm_year << ti->tm_mon << ti->tm_mday;
  std::cout << "_";
  std::cout << ti->tm_hour << ti->tm_min << ti->tm_sec;
  std::cout << "]";
}

void		Account::displayAccountsInfos() {
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals;
	std::cout << std::endl;
}

void		Account::makeDeposit(int deposit) {
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount - deposit;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
}

bool		Account::makeWithdrawal(int withdrawal) {
	if (withdrawal > _amount) {
		_displayTimestamp();
		std::cout << " index:" << _accountIndex;
		std::cout << ";p_amount:" << _amount;
		std::cout << ";withdrawal:" << "refused";
		std::cout << std::endl;
		return false;
	} else {
		_amount -= withdrawal;
		_nbWithdrawals++;
		_totalAmount -= withdrawal;
		_totalNbWithdrawals++;
		
		_displayTimestamp();
		std::cout << " index:" << _accountIndex;
		std::cout << ";p_amount:" << _amount + withdrawal;
		std::cout << ";withdrawal:" << withdrawal;
		std::cout << ";amount:" << _amount;
		std::cout << ";nb_withdrawals:" << _nbWithdrawals;
		std::cout << std::endl;
		return true;
	}
}

int			Account::checkAmount() const {
	return _amount;
}

void		Account::displayStatus() const {
	_displayTimestamp();
	std::cout << " index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
}
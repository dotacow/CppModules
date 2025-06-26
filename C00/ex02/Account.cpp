/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 17:25:16 by yokitane          #+#    #+#             */
/*   Updated: 2025/06/26 19:01:56 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"


int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) :
	_accountIndex(_nbAccounts),_amount(initial_deposit),
	_nbDeposits(0),_nbWithdrawals(0)
{
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout<< "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";closed" << std::endl;
}

int		Account::getNbAccounts( void ) { return (_nbAccounts); }
int		Account::getTotalAmount( void ) { return (_totalAmount); }
int		Account::getNbDeposits( void ) { return (_totalNbDeposits); }
int		Account::getNbWithdrawals( void ) { return (_totalNbWithdrawals); }
int		Account::checkAmount( void ) const { return (_amount); }

void	Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout<<"accounts:"<< _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<<";withdrawls:"<<_totalNbWithdrawals << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";p_amount:" << _amount;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";deposit:" << deposit
				<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int Widthrawl)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";p_amount:" << _amount;
	if (Widthrawl > _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= Widthrawl;
	_nbWithdrawals++;
	Account::_totalAmount -= Widthrawl;
	Account::_totalNbWithdrawals++;
	std::cout << ";withdrawal:" << Widthrawl
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals << std::endl;
	return (true);
}
void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp( void )
{
	std::time_t now = std::time(0);
	std::tm* timeinfo = std::localtime(&now);

	std::cout << "["
			  << std::setfill('0') << std::setw(4) << (timeinfo->tm_year + 1900)
			  << std::setfill('0') << std::setw(2) << (timeinfo->tm_mon + 1)
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_mday
			  << "_"
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_hour
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_min
			  << std::setfill('0') << std::setw(2) << timeinfo->tm_sec
			  << "] ";
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 18:41:10 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/14 18:41:20 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap():_attackDamage(0),_energyPoints(10),_hitPoints(10),_name("")
{
	std::cout << "default claptrap constructer called\n";
};

ClapTrap::ClapTrap(std::string name): _attackDamage(0),_energyPoints(10),_hitPoints(10),_name(name)
{
	std::cout<< _name << ": this is "<< _name << " from the ClapTrap class\n";
};

ClapTrap::ClapTrap(ClapTrap &other)
{
	std::cout<< _name << ": this is "<< _name << " from the *copy* ClapTrap class\n";
	*this = other;
}

ClapTrap &ClapTrap::operator=(ClapTrap &other)
{
	this->_name = other.getName();
	this->_attackDamage = other.getATK();
	this->_energyPoints = other.getEP();
	this->_hitPoints = other.getHP();
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout<< _name << ": Change the world, my final message. goodbye.\n";
}

std::string ClapTrap::getName() const { return (_name);}
unsigned int ClapTrap::getEP() const {return (_energyPoints);}
unsigned int ClapTrap::getATK() const {return (_attackDamage);}
unsigned int ClapTrap::getHP() const {return (_hitPoints);}

void ClapTrap::attack(const std::string &target)
{
	if (this->isAlive() && this->isCharged())
	{
		std::cout << _name << " Attacks " << target << ", causing " << _attackDamage
		<< " points of damage!\n";
		_energyPoints--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
		std::cout <<"kicking a robot while they're down? straight up immoral.\n";
	_hitPoints -= amount;
	std::cout << _name << " was hit for " << amount <<" damage, HP: " << _hitPoints << "\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->isAlive() && this->isCharged())
	{
		_hitPoints += amount;
		std::cout << _name << "heals for " << amount << ", HP:" << _hitPoints <<"\n";
	}
}

bool ClapTrap::isAlive() const
{
	if (_hitPoints > 0)
		return (true);
	std::cout << _name << " is dead and can't do your request!\n";
	return (false);
}

bool ClapTrap::isCharged() const
{
	if (_energyPoints > 0)
		return (true);
	std::cout << _name << " is all outta gas!\n";
	return (false);
}
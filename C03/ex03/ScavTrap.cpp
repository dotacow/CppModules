/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:54:33 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/15 21:52:44 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap(), _mode(NORMAL)
{
	this->setHP(100);
	this->setEP(50);
	this->setATK(20);
	std::cout << "default scavtrap constructer called\n";
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name), _mode(NORMAL)
{
	this->setHP(100);
	this->setEP(50);
	this->setATK(20);
	std::cout << name << ": this is " << name << " from the ScavTrap class\n";
}

ScavTrap::ScavTrap(ScavTrap &other): ClapTrap(other)
{
	std::cout << this->getName() << ": this is " << this->getName() << " from the *copy* constructer ScavTrap class\n";
	*this = other;
}

ScavTrap &ScavTrap::operator=(ScavTrap &other)
{
	ClapTrap::operator=(other);
	this->_mode = other.getMode();
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << this->getName() << ": Guarding gates was a good time... goodbye.\n";
}

void ScavTrap::attack(const std::string &target)
{
	if (this->isAlive() && this->isCharged())
	{
		std::cout << this->getName() << " *Attacks " << target << ", with a savage force of "
				  << this->getATK() << " points of damage!*\n";
		_energyPoints--;
	}
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (this->isGuarding())
		ClapTrap::takeDamage(amount / 2);
	else
		ClapTrap::takeDamage(amount);
}

void ScavTrap::guardGate()
{
	if (this->isAlive())
	{
		if (this->_mode == ONGUARD)
		{
			std::cout << this->getName() << ": I am already gaurding your gate..."
			<< " it's bad manners to ask someone to do the same thing twice.\n";
			return ;
		}
		this->_mode = ONGUARD;
		std::cout << this->getName() << ": NONE SHALL PASS!\n";
	}
}

bool ScavTrap::isGuarding() const
{
	return (this->_mode == ONGUARD);
}

void ScavTrap::setMode(e_trapMode mode) {this->_mode = mode;}

ScavTrap::e_trapMode ScavTrap::getMode() const { return (this->_mode);}
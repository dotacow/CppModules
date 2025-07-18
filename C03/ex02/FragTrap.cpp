/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 22:41:36 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/15 23:56:50 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() :ClapTrap("")
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout<<_name << ":FragTrap default constructor called\n";
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout<< _name << ":FragTrap constructor called\n";
}

FragTrap::FragTrap(FragTrap &other) : ClapTrap(other)
{
	*this = other;
	std::cout<< _name << ":FragTrap copy constructor called\n";
}

FragTrap &FragTrap::operator=(FragTrap &other)
{
	ClapTrap::operator=(other);
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << this->getName() << " :time to blow up to a thaousand fragmented pieces..\n";
}

void FragTrap::highFivesGuys(void)
{
	std::string temp;
	std::cout << this->getName() << ": High five?[y/y]\n";
	std::cin >> temp;
	if (std::cin.eof())
	{
		std::cout <<"*sad FragTrap noises*\n";
		std::cin.clear();
		return ;
	}
	std::cout << this->getName() << ": *the crisp dap heals the robot*\n";
	_energyPoints++;
	ClapTrap::beRepaired(10);
}

void FragTrap::attack(const std::string &target)
{
	if (this->isAlive() && this->isCharged())
	{
		std::cout <<this->getName() << ": has attacked " << target << " with " << this->getATK() << " fragments\n";
		_energyPoints--;
	}
}


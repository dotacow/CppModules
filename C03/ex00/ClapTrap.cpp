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
	std::cout<< _name << ": Change the world, my final message. goodbye.";
}

std::string ClapTrap::getName() const { return (_name);}

unsigned int ClapTrap::getEP() const {return (_energyPoints);}

unsigned int ClapTrap::getATK() const {return (_attackDamage);}

unsigned int ClapTrap::getHP() const {return (_hitPoints);}


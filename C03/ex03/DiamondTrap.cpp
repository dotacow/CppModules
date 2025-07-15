/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 23:26:55 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/16 00:16:04 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap(), name("")
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "default diamondtrap constructor called\n";
}

DiamondTrap::DiamondTrap(const std::string &newname) : ClapTrap(newname + "_clap_name"), name(newname)
{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << name << ": this is " << name << " from the DiamondTrap class\n";
}

DiamondTrap::DiamondTrap(DiamondTrap &other) : ClapTrap(other._name + "_clap_name"), ScavTrap(other),FragTrap(other),name(other.name)
{
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	std::cout << this->getName() << ": this is " << this->getName() << " from the *copy* constructer DiamondTrap class\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	_name = other._name;
	name = other.name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << this->getName() << ": the little bird sharpened it's beak\n";
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::setName(const std::string &newname)
{
	this->name = newname;
	ClapTrap::setName(name + "_clap_name");
}

std::string DiamondTrap::getName() const
{
	return (this->name);
}

void DiamondTrap::whoAmI() const
{
	std::cout << "I am " << this->getName() << ", but people call me  " << ClapTrap::getName() << "\n";
}
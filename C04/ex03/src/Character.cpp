/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:00:29 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/17 00:25:41 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Character.hpp"

int Character::_playerCount = 0;
int Character::_materiaCount = 0;
AMateria* Character::_materiaPool[500] = {NULL};

Character::Character() : _name("some Dude")
{
	_playerCount++;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(std::string name) : _name(name)
{
	_playerCount++;
	for (int i = 0; i < 4; i++)
		_inventory[i] = NULL;
}

Character::Character(const Character& other) : _name(other._name)
{
	_playerCount++;
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
}

Character& Character::operator=(const Character &other)
{
	if (this == &other)
		return *this;
	clearInventory();
	_name = other._name;
	for (int i = 0; i < 4; i++)
	{
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
		else
			_inventory[i] = NULL;
	}
	return *this;
}

Character::~Character()
{
	_playerCount--;
	clearInventory();
	if (_playerCount == 0)
		clearPool();
}

std::string const & Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* materia)
{
	if (!materia)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (!_inventory[i])
		{
			_inventory[i] = materia;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return;
	addToPool(_inventory[idx]);
	_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || !_inventory[idx])
		return;
	_inventory[idx]->use(target);
}

void Character::clearPool()
{
	for (int i = 0; i < _materiaCount; i++)
	{
		if (_materiaPool[i])
			delete _materiaPool[i];
		_materiaPool[i] = NULL;
	}
	_materiaCount = 0;
}

void Character::clearInventory()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
		{
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}

void Character::addToPool(AMateria* materia)
{
	if (_materiaCount < 500)
	{
		_materiaPool[_materiaCount++] = materia;
	}
	else
	{
		std::cout << "the world cannot handle any more unleashed materia,deleting dropped materia...\n";
		delete materia;
	}
}
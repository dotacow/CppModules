/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:38:33 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/16 19:41:13 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("some otherwordly blank canvas of dna")
{
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::WrongAnimal(const std::string &ptype) : type(ptype)
{
	std::cout << "WrongAnimal parameterized constructor called with type: " << type << "\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type)
{
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called for type: " << type << "\n";
}

void WrongAnimal::makeSound() const
{
	std::cout << "*horrific wrong animal noises*\n";
}

void WrongAnimal::setType(const std::string &ptype)
{
	type = ptype;
}

std::string WrongAnimal::getType() const
{
	return type;
}
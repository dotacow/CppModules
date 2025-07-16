/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:03:14 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/16 19:40:41 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"
#include <iostream>

Animal::Animal() : type("blank canvas of dna")
{
	std::cout << "Animal default constructor called\n";
}

Animal::Animal(const std::string &ptype) : type(ptype)
{
	std::cout << "Animal parameterized constructor called with type: " << type << "\n";
}

Animal::Animal(const Animal &other) : type(other.type)
{
	std::cout << "Animal copy constructor called\n";
}

Animal &Animal::operator=(const Animal &other)
{
	type = other.type;
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called for type: " << type << "\n";
}

void Animal::makeSound() const
{
	std::cout << "*conceptual animal noises*\n";
}

void Animal::setType(const std::string &ptype)
{
	type = ptype;
}

std::string Animal::getType() const
{
	return type;
}
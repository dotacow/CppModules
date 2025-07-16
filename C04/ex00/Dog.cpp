/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:20:35 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/16 17:57:56 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called\n";
}

Dog & Dog::operator=(const Dog &other)
{
	Animal::operator=(other);
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}
void Dog::makeSound() const
{
	std::cout << "*Dog noises*\n";
}

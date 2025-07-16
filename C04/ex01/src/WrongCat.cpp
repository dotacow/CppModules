/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:41:26 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/16 19:41:16 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	WrongAnimal::operator=(other);
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

void WrongCat::makeSound() const
{
	std::cout << "*otherwordly meow noises*\n";
}
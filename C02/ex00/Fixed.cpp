/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:18:44 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/06 06:40:20 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed(void): _rawBits(0)
{
	std::cout << "Default Constructor called\n";
};

Fixed::Fixed(const Fixed *other)
{
	std::cout << "Copy Constructor called\n";
	*this = *other;
};

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy Assignment Operator called\n";
	this->_rawBits = other.getRawBits();
	return (*this);
};

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
};

int Fixed::getRawBits(void) const
{
	std::cout << "GetRawBits member function called\n";
	return (_rawBits);
};

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
};
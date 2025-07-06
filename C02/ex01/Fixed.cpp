/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:18:44 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/06 15:31:31 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): _rawBits(0)
{
	std::cout << "Default Constructor called\n";
};

Fixed::Fixed(const Fixed *other)
{
	std::cout << "Copy Constructor called\n";
	*this = *other;
};

Fixed::Fixed(const int &integer)
{
	std::cout << "Int Constructor called\n";
	this->_rawBits = integer << _fractionBits;
}

Fixed::Fixed(const float &flt)
{
	std::cout << "Float Constructor called\n";
	this->_rawBits = roundf((flt * (1 << _fractionBits)));
};

Fixed::~Fixed(void)
{
	std::cout << "Destructor called\n";
};
Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy Assignment Operator called\n";
	this->_rawBits = other.getRawBits();
	return (*this);
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixedPoint)
{
	o << fixedPoint.toInt();
	return (o);
};

int Fixed::getRawBits(void) const
{
	std::cout << "GetRawBits member function called\n";
	return (_rawBits);
};

void Fixed::setRawBits(int const raw)
{
	std::cout << "SetRawBits member function called\n";
	this->_rawBits = raw;
};

int Fixed::toInt() const
{
	return (_rawBits >> _fractionBits);
}

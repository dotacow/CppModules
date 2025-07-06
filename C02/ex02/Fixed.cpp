/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:18:44 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/06 16:45:27 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed(void): _rawBits(0)
{
};

Fixed::Fixed(const Fixed *other)
{
	*this = *other;
};

Fixed::Fixed(const int &integer)
{
	this->_rawBits = integer << _fractionBits;
}

Fixed::Fixed(const float &flt)
{
	this->_rawBits = roundf((flt * (1 << _fractionBits)));
};

Fixed::~Fixed(void)
{
};

Fixed &Fixed::operator=(const Fixed &other)
{
	this->_rawBits = other.getRawBits();
	return (*this);
};

bool Fixed::operator>(const Fixed &other) const
{
	return (this->_rawBits > other.getRawBits());
};

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->_rawBits >= other.getRawBits());
};

bool Fixed::operator<(const Fixed &other) const
{
	return (this->_rawBits < other.getRawBits());
};

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->_rawBits <= other.getRawBits());
};

bool Fixed::operator==(const Fixed &other) const
{
	return (this->_rawBits == other.getRawBits());
};

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->_rawBits != other.getRawBits());
};

std::ostream &operator<<(std::ostream &o, Fixed const &fixedPoint)
{
	o << fixedPoint.toInt();
	return (o);
};

int Fixed::getRawBits(void) const
{
	return (_rawBits);
};

void Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
};

int Fixed::toInt() const
{
	return (_rawBits >> _fractionBits);
}

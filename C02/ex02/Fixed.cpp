/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:18:44 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/06 17:16:34 by yokitane         ###   ########.fr       */
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

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_rawBits + other.getRawBits());
	return (result);
};

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed result;
	result.setRawBits(this->_rawBits - other.getRawBits());
	return (result);
};

Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed result;
	result.setRawBits((this->_rawBits * other.getRawBits()) >> _fractionBits);
	return (result);
};

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.getRawBits() == 0)
	{
		std::cerr << "Error: Division by zero" << std::endl;
		return (Fixed());
	}
	Fixed result;
	result.setRawBits((this->_rawBits << _fractionBits) / other.getRawBits());
	return (result);
};

Fixed &Fixed::operator++()
{
	this->_rawBits++;
	return (*this);
};

Fixed &Fixed::operator--()
{
	this->_rawBits--;
	return (*this);
};

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->_rawBits++;
	return (temp);
};

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->_rawBits--;
	return (temp);
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

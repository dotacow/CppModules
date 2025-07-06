/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 00:46:25 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/07 00:54:01 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void): _x(0), _y(0){};

Point::Point(Fixed x, Fixed y): _x(x), _y(y){};

Point::Point(const Point &other): _x(other._x), _y(other._y){};

Point::~Point(){};

Point &Point::operator=(const Point &other)
{
	const_cast<Fixed&>(this->_x) = other._x;
	const_cast<Fixed&>(this->_y) = other._y;
	return (*this);
}

bool Point::operator==(const Point &other) const
{
	return (this->_x == other._x && this->_y == other._y);
}

Fixed Point::getX(void) const
{
	return (this->_x);
}

Fixed Point::getY(void) const
{
	return (this->_y);
}

double Point::getXf(void) const
{
	return static_cast<double>((this->_x.toFloat()));
}

double Point::getYf(void) const
{
	return static_cast<double>((this->_y.toFloat()));
}

void Point::setX(Fixed x)
{
	const_cast<Fixed&>(this->_x) = x;
}

void Point::setY(Fixed y)
{
	const_cast<Fixed&>(this->_y) = y;
}
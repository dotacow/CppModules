/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:31:45 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/07 00:50:48 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

# include "Fixed.hpp"

class Point
{
private:
	const Fixed _x;
	const Fixed _y;
public:
	Point( void );
	Point(Fixed x,Fixed y);
	Point(const Point &other);
	~Point();
	Point &operator=(const Point &other);
	bool operator==(const Point &other) const;
	Fixed getX(void) const;
	Fixed getY(void) const;
	double getXf(void) const;
	double getYf(void) const;
	void setX(Fixed x);
	void setY(Fixed y);
};

namespace quickmafs
{
	bool bsp(Point const a, Point const b, Point const c, Point const point);
};

#endif //POINT_HPP
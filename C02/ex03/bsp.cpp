/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:42:40 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/07 01:08:00 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <iostream>

namespace quickmafs
{
	bool bsp(Point const a, Point const b, Point const c, Point const point)
	{
		//barycentric coordinates approach
		Fixed area = (b.getX() - a.getX()) * (c.getY() - a.getY()) -
						(c.getX() - a.getX()) * (b.getY() - a.getY());

		Fixed s = (a.getX() - point.getX()) * (b.getY() - point.getY()) -
						(b.getX() - point.getX()) * (a.getY() - point.getY());

		Fixed t = (b.getX() - point.getX()) * (c.getY() - point.getY()) -
						(c.getX() - point.getX()) * (b.getY() - point.getY());

		Fixed u = (c.getX() - point.getX()) * (a.getY() - point.getY()) -
					(a.getX() - point.getX()) * (c.getY() - point.getY());

		return ((s > 0 && t > 0 && u > 0) || (s < 0 && t < 0 && u < 0));
	};
}
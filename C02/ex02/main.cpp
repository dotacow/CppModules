/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:18:42 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/06 19:00:39 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	Fixed temp(5);
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << (temp=a--) << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << Fixed(Fixed(1.0f) / Fixed(3.0f)).toFloat()<< std::endl;
	std::cout << Fixed(Fixed(1.0f) / Fixed(0.0f)).toFloat()<< std::endl;
	return 0;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:18:45 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/06 13:48:48 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int					_rawBits;
	static const int	_fractionBits = 8;
public:
//constructers, destructors, and operator overloads
	Fixed( void );
	Fixed(const int &integer);
	Fixed(const float &flt);
	Fixed(const Fixed *other);
	Fixed &operator=(const Fixed &other);

	~Fixed( void );
	//member functions
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	int		toInt() const;
};
//non member overloads and functions
	std::ostream &operator<<(std::ostream &o,Fixed const &fixedPoint) ;

#endif
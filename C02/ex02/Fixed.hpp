/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:18:45 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/06 18:53:35 by yokitane         ###   ########.fr       */
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
//constructers and destructors
	Fixed( void );
	Fixed(const int &integer);
	Fixed(const float &flt);
	Fixed(const Fixed *other);
	~Fixed( void );
//operator overloads:
	Fixed &operator=(const Fixed &other);
	bool operator>(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;
	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;
	Fixed &operator++();
	Fixed &operator--();
	Fixed operator++(int);
	Fixed operator--(int);
//member functions
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
	int		toInt() const;
	float	toFloat() const;
//member function overloads
	static Fixed &min(Fixed &a, Fixed &b);
	static const Fixed &min(const Fixed &a, const Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static const Fixed &max(const Fixed &a, const Fixed &b);

};
//non member overloads and functions
	std::ostream &operator<<(std::ostream &o,Fixed const &fixedPoint) ;

#endif
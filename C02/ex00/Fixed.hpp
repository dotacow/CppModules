/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 05:18:45 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/06 06:39:38 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	int					_rawBits;
	static const int	_fractionBits = 8;
public:
	Fixed( void );
	Fixed(const Fixed *other);
	Fixed &operator=(const Fixed &other);
	~Fixed( void );
	int		getRawBits( void ) const;
	void	setRawBits( int const raw );
};

#endif
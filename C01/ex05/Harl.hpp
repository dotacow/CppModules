/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:01:10 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/06 05:32:31 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
	private:
	//data fields
		static const std::string	_messages[5];
		static const std::string	_headers[5];
		enum levels{
			DEBUG,
			INFO,
			WARNING,
			ERROR,
			INSIGNIFICANT
		};
	//member functions
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		void insignificant( void );
		levels getLevel(std::string level);
	public:
		Harl( void );
		~Harl( void );
	void complain( std::string level);
};


#endif
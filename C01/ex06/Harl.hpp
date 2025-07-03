/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:01:10 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/03 23:57:54 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <string>

class Harl
{
	private:
	//data fields
		std::string  _messages[5];
	//member functions
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		void insignificant( void );
	public:
		enum levels{
			DEBUG,
			INFO,
			WARNING,
			ERROR,
			INSIGNIFICANT
		};
		Harl( void );
		~Harl( void );
		levels getLevel(std::string level);
		void complain( std::string level);
};


#endif
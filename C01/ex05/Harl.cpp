/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:16:36 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/03 23:51:07 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"
# include <iostream>

Harl::Harl( void ) {
	_messages[0]= "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!";
	_messages[1] = "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	_messages[2] = "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.";
	_messages[3] = "This is unacceptable! I want to speak to the manager now.";
	_messages[4] = "[ Probably complaining about insignificant problems ]";

};
Harl::~Harl( void ) {};

void Harl::debug (void )
{
	std::cerr << _messages[DEBUG] << std::endl;
}
void Harl::info (void )
{
	std::cerr << _messages[INFO] << std::endl;
}
void Harl::warning (void )
{
	std::cerr << _messages[WARNING] << std::endl;
}
void Harl::error (void )
{
	std::cerr << _messages[ERROR] << std::endl;
}

void Harl::insignificant (void )
{
	std::cerr << _messages[INSIGNIFICANT] << std::endl;
}

Harl::levels Harl::getLevel(std::string level)
{
	if (level == "DEBUG")
		return (DEBUG);
	else if (level == "INFO")
		return (INFO);
	else if (level == "WARNING")
		return (WARNING);
	else if (level == "ERROR")
		return (ERROR);
	return (INSIGNIFICANT);
}

void Harl::complain(std::string level)
{
	typedef void (Harl::*HarlFunc)();

	HarlFunc horrors[5] = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
		&Harl::insignificant,
	};
	(this->*horrors[getLevel(level)])();
}
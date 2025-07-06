/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:16:36 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/06 05:42:13 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Harl.hpp"
# include <iostream>

const std::string Harl::_messages[5] = {
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger.\nI really do!",
	"I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!",
	"I think I deserve to have some extra bacon for free.\nI’ve been coming for years, whereas you started working here just last month.",
	"This is unacceptable! I want to speak to the manager now.",
	"[ Probably complaining about insignificant problems ]"
};

const std::string Harl::_headers[5] = {
	"DEBUG",
	"INFO",
	"WARNING",
	"ERROR",
	"INSIGNIFICANT"
};

Harl::Harl( void ) {};

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
	for (int i = 0; i < 5; i++)
	{
		if (level == _headers[i])
			return static_cast<levels>(i);
	}
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
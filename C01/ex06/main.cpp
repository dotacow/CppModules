/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:45:08 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/04 00:19:05 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main (int argc, char **argv)
{
	Harl harl;

	if (argc != 2)
	{
		harl.complain("*distant shouting*");
		return (0);
	}
	int level = harl.getLevel(std::string(argv[1]));
	while (level >= 0 && level < 5)
	{
		switch (level)
		{
			case Harl::DEBUG:
				harl.complain("DEBUG");
				break;
			case Harl::INFO:
				harl.complain("INFO");
				break;
			case Harl::WARNING:
				harl.complain("WARNING");
				break;
			case Harl::ERROR:
				harl.complain("ERROR");
				return (0);
			default:
				harl.complain("INSIGNIFICANT");
				return (0);
		}
		level++;
	}
	return (0);
}

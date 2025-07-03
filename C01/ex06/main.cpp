/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 23:45:08 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/03 23:59:59 by yokitane         ###   ########.fr       */
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
		switch (level)
		{
			case Harl::DEBUG:
				harl.complain("DEBUG");
			case Harl::INFO:
				harl.complain("INFO");
			case Harl::WARNING:
				harl.complain("WARNING");
			case Harl::ERROR:
				harl.complain("ERROR");
				break;
			default:
				harl.complain("INSIGNIFICANT");
				break;
		}
	return (0);
}

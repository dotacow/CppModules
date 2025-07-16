/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:42:48 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/16 17:30:13 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap robo1 ("CL4P-TP");
	ClapTrap robo2 ("ROBO2");
	for (int i = 0; i < 9; i++)
	{
		robo1.attack(robo2.getName());
		robo2.takeDamage(1);
	}
	ClapTrap robo3(robo2);
	robo3.setName("ROBO3");
	robo1.attack(robo2.getName());
	robo2.takeDamage(1);
	robo2.takeDamage(1);
	robo3.beRepaired(5);
	robo1.beRepaired(5);
	robo2.beRepaired(10);
	return (0);
}
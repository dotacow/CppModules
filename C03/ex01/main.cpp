/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:42:48 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/15 21:53:56 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main (void)
{
	ClapTrap claptrap("Clap");
	ScavTrap scavtrap("Scav");

	claptrap.attack("Scavvy");
	scavtrap.attack("Clappy");

	claptrap.takeDamage(10);
	scavtrap.takeDamage(10);

	claptrap.beRepaired(5);
	scavtrap.beRepaired(5);

	scavtrap.guardGate();
	scavtrap.attack("Clappy");
	scavtrap.takeDamage(10);
	return (0);
}
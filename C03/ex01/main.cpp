/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:42:48 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/15 22:29:34 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main (void)
{
	ClapTrap claptrap("Clap");
	ScavTrap scavtrap("Scav");

	claptrap.attack("Scav");
	scavtrap.attack("Clap");

	claptrap.takeDamage(10);
	scavtrap.takeDamage(10);

	claptrap.beRepaired(5);
	scavtrap.beRepaired(5);

	scavtrap.guardGate();
	scavtrap.attack("Clappy");
	scavtrap.takeDamage(10);
	return (0);
}
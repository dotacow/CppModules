/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:42:48 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/15 23:08:46 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main (void)
{
	ClapTrap claptrap("Clap");
	ScavTrap scavtrap("Scav");
	FragTrap fragtrap("Frag");
	
	fragtrap.highFivesGuys();
	fragtrap.attack("Scav");
	return (0);
}
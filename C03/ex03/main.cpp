/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:42:48 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/16 00:07:50 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main (void)
{
	ClapTrap claptrap("Clap");
	ScavTrap scavtrap("Scav");
	FragTrap fragtrap("Frag");
	DiamondTrap diamondtrap("Diamond");

	diamondtrap.whoAmI();
	return (0);
}
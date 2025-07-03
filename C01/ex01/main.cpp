/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:21:50 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/03 17:00:11 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main (void)
{
	Zombie *zombie;
	zombie = ZUtils::zombieHorde(30, "member of the undying horde");
	delete [] zombie;
}
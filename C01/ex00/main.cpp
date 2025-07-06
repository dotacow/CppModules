/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:21:50 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/06 05:13:45 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main (void)
{
	Zombie *zombie = ZUtils::newZombie("Real Zombie");
	ZUtils::randomChump("Abo 7meed");
	delete (zombie);
	return (0);
}
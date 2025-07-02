/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 23:19:41 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/03 00:59:59 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

namespace ZUtils
{
	Zombie* newZombie(std::string name)
	{
		Zombie* zombie = new Zombie(name);
		return (zombie);
	}
	void randomChump(std::string name)
	{
		Zombie zombie(name);
	}
	Zombie *zombieHorde(int N, std::string name)
	{
		Zombie* horde = new Zombie[N];
		for (int i = 0; i < N; ++i)
		{
			horde[i].setName(name);
			horde[i].announce();
		}
		return (horde);
	}
}
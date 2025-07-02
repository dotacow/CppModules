/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 23:19:41 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/03 00:42:59 by yokitane         ###   ########.fr       */
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
}
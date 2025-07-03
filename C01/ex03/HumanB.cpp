/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:42:17 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/03 20:55:29 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanB.hpp"
# include <iostream>

HumanB::HumanB(const std::string name): _name(name)
{
	this->_weapon = NULL;
};
HumanB::~HumanB() {};

void HumanB::attack() const
{
	if (!this->_weapon)
	{
		std::cout << this->_name << " is unarmed!" << std::endl;
		return ;
	}
	std::cout << this->_name << " attacks with their "
				<< this->_weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &weapon){ this->_weapon = &weapon;}
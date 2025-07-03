/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:27:01 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/03 20:48:45 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "HumanA.hpp"
# include <iostream>

HumanA::HumanA(const std::string name, Weapon &weapon): _name(name), _weapon(weapon) {};
HumanA::~HumanA() {};

void HumanA::setWeapon(Weapon weapon)
{
	this->_weapon = weapon;
}

void HumanA::attack() const
{
	std::cout << this->_name << " attacks with their "
				<< this->_weapon.getType() << std::endl;
}

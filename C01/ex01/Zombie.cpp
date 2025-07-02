/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:45:53 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/03 00:21:26 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void): _name("")
{
	std::cout << "Zombie is no one. default constructor called" << std::endl;
};

Zombie::Zombie(std::string name): _name(name)
{
	this->announce();
};

Zombie::~Zombie(void)
{
	std::cout << this->getName() << " has seen the light of day"
				<< " and has been destoryed" << std::endl;
}

std::string Zombie::getName(void) const {return (this->_name); }

void Zombie::setName(std::string name) { this->_name = name; }

void Zombie::announce(void) const
{
	std::cout << this->getName() <<": BraiiiiiiinnnzzzZ..." << std::endl;
}


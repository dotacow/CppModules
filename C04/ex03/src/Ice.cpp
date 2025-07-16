/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:49:21 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/17 00:37:44 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Ice.hpp"
#include "../includes/ICharacter.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice &other) : AMateria(other) {
	this->type = other.getType();
}

Ice &Ice::operator=(const Ice &other)
{
	(void)other;
	return *this;
}

Ice::~Ice() {}

Ice *Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}
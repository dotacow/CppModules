/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:56:47 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/17 00:38:01 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Cure.hpp"
#include "../includes/ICharacter.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &other) : AMateria(other) {
	this->type = other.getType();
}

Cure &Cure::operator=(const Cure &other)
{
	(void)other;
	return *this;
}

Cure::~Cure() {}

Cure *Cure::clone() const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 21:37:34 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/17 00:35:42 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AMateria.hpp"

AMateria::AMateria() : type("voidstone")
{
}

AMateria::AMateria(const std::string &ptype) : type(ptype)
{
}
AMateria::AMateria(const AMateria &other) : type(other.type)
{
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}
	return *this;
}

AMateria::~AMateria(){};

const std::string &AMateria::getType() const {return type;}

void AMateria::use(ICharacter &target)
{
	(void)target;
	std::cout <<"Voidstone used, No effect\n";
};
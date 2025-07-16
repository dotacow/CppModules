/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 22:49:33 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/16 22:55:33 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria
{
	public:
		Ice();
		Ice(const Ice &other);
		Ice &operator=(const Ice &other);
		~Ice();

		Ice *clone() const;
		void use(ICharacter &target);
};
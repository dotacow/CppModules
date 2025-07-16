/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:05:33 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/16 21:07:11 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Animal.hpp"
#include <string>

class Animal
{
	public:
		Animal();
		Animal(const std::string &ptype);
		Animal(const Animal &other);
		Animal &operator=(const Animal &other);
		virtual ~Animal();
		virtual void	makeSound() const = 0;
		void			setType(const std::string &ptype);
		std::string		getType() const;
	protected:
		std::string type;
};
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:36:02 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/16 18:38:34 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>

class WrongAnimal{

	public:
		WrongAnimal();
		WrongAnimal(const std::string &ptype);
		WrongAnimal(const WrongAnimal &other);
		WrongAnimal &operator=(const WrongAnimal &other);
		virtual ~WrongAnimal();
		virtual void	makeSound() const;
		void			setType(const std::string &ptype);
		std::string		getType() const;
	protected:
		std::string type;
};
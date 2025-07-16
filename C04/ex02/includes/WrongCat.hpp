/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:40:44 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/16 19:41:31 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "WrongAnimal.hpp"


class WrongCat : public WrongAnimal
{
	public:
		WrongCat();
		WrongCat(const WrongCat &other);
		WrongCat &operator=(const WrongCat &other);
		virtual ~WrongCat();
		virtual void makeSound() const;
};

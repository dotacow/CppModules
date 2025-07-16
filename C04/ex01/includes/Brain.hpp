/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:44:57 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/16 20:46:27 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>
#include "Animal.hpp"
class Brain
{
	public:
		Brain();
		Brain(const Brain &other);
		~Brain();
		Brain &operator=(const Brain &other);
		void		setIdeas(const std::string &idea, int index);
		std::string	getIdea(int index) const;

	protected:
		std::string ideas[100];
};

namespace brainstem
{
	void brainDump(Brain &brain);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 19:44:56 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/16 20:28:37 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"
#include <iostream>

Brain::Brain()
{
	for (int i = 0; i < 100; ++i)
		ideas[i] = "empty thought";
	std::cout << "Default Brain constructor called.\n";
}

Brain::Brain(const Brain &other)
{
	for (int i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];
	std::cout << "Copy Brain constructor called.\n";
}

Brain::~Brain()
{
	std::cout << "Lobotomy initiated.\n";
}

Brain &Brain::operator=(const Brain &other)
{
	for (int i = 0; i < 100; ++i)
		ideas[i] = other.ideas[i];
	return *this;
}

void Brain::setIdeas(const std::string &idea, int index)
{
	if (index >= 0 && index < 100)
		ideas[index] = idea;
	else
		std::cerr << "no thought with such index";
}

std::string Brain::getIdea(int index) const
{
	if (index >= 0 && index < 100)
		return ideas[index];
	std::cerr << "no thought with such index";
	return "";
}

void brainstem::brainDump(Brain &brain)
{
	for (int i = 0; i < 100; ++i)
	{
		std::cout << "Thought " << i << ": "
				<< brain.getIdea(i) << std::endl;
	}
}
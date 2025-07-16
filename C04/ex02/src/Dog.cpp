/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:20:35 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/16 20:47:27 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Dog default constructor called\n";
	brain = new Brain();
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog copy constructor called\n";
	brain = new Brain(*other.brain);
}

Dog & Dog::operator=(const Dog &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
	delete brain;
}
void Dog::makeSound() const
{
	std::cout << "*Dog noises*\n";
}


void Dog::setBrain(Brain *newBrain)
{
	if (brain)
		delete brain;
	brain = newBrain;
}

Brain *Dog::getBrain() const
{
	return brain;
}
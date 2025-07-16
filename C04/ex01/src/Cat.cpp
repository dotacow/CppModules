/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:58:10 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/16 20:47:04 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called\n";
	brain = new Brain();
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called\n";
	brain = new Brain(*other.brain);
}

Cat::~Cat()
{
	std::cout <<"Cat deconstructor called\n";
	delete brain;
}
Cat & Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		Animal::operator=(other);
		delete brain;
		brain = new Brain(*other.brain);
	}
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "*Cat noises*\n";
}

void Cat::setBrain(Brain *newBrain)
{
	if (brain)
		delete brain;
	brain = newBrain;
}

Brain *Cat::getBrain() const
{
	return brain;
}
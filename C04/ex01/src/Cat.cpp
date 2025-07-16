/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:58:10 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/16 19:40:52 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Cat.hpp"

Cat::Cat() : Animal("Cat")
{
	std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat copy constructor called\n";
}

Cat::~Cat()
{
	std::cout <<"Cat deconstructor called\n";
}
Cat & Cat::operator=(const Cat &other)
{
	Animal::operator=(other);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "*Cat noises*\n";
}
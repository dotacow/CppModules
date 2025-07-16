/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:07:39 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/16 21:07:30 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/Animal.hpp"
#include <iostream>

int main()
{
	Animal *animals[5];
	for (int i = 0; i < 4; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}
	std::cout << "Copying tests begin:\n\n";
	// Animal x = Animal(*animals[0]);
	// x.setType("bird");
	// std::cout << "Animal type: " << x.getType() << std::endl;
	std::cout << "Animal type: " << animals[0]->getType() << std::endl;
	Dog dog = Dog(static_cast<Dog &>(*animals[0]));
	dog.getBrain()->setIdeas("Fetch the ball", 0);
	std::cout << "Dog's first idea: " << dog.getBrain()->getIdea(0) << std::endl;
	std::cout << "original dog's first idea: "
				<< static_cast<Dog &>(*animals[0]).getBrain()->getIdea(0) << std::endl;
	for(int i = 0; i < 4; i++)
		delete animals[i];
	return (0);
}

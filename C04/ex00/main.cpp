/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:07:39 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/16 18:44:18 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include <iostream>
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		const Animal* meta = new Animal();
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		Animal			animal = *dog;
		std::cout << dog->getType() << " " << std::endl;
		std::cout << cat->getType() << " " << std::endl;
		cat->makeSound();
		dog->makeSound();
		meta->makeSound();
		animal.setType("bird");
		std::cout << "Animal type after assignment: " << animal.getType() << std::endl;
		delete meta;
		delete cat;
		delete dog;
	}
	std::cout <<"\n\nBEGIN WRONG ANIMAL TEST\n\n";
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* wrongCat = new WrongCat();
		std::cout << "WrongAnimal type: " << meta->getType() << std::endl;
		std::cout << "WrongCat type: " << wrongCat->getType() << std::endl;
		wrongCat->makeSound();
		meta->makeSound();
		delete meta;
		delete wrongCat;
	}

	return 0;
}
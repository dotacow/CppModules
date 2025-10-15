/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 15:13:07 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/15 14:19:30 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "../includes/Base.hpp"
#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"

Base *generate(void)
{
	int	seed = rand() % (3);

	switch (seed)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "the mystery is A\n";
		return ;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "the mystery is B\n";
		return ;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "the mystery is C\n";
		return ;
	}
	catch (...) {}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "the mystery is A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "the mystery is B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "the mystery is C\n";
}

int main (void)
{
	srand(time(NULL));
	Base	*base1;
	Base	*base2;

	base1 = generate();
	base2 = generate();
	std::cout << "Identify by pointer:\n";
	identify(base1);
	identify(base2);
	std::cout << "Identify by reference:\n";
	identify(*base1);
	identify(*base2);
	return (0);
}
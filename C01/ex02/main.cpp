/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:08:16 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/06 05:14:07 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main (void)
{
	std::string name = "HI THIS IS BRAIN";
	std::string *stringPTR = &name;
	std::string &stringREF = name;

	std::cout << "Memory address of the string variable: " << &name << std::endl
				<< "Memory address held by stringPTR: " << stringPTR << std::endl
				<< "Memory address held by stringREF: " << &stringREF << std::endl;
	std::cout << "value of the string variable: " << name << std::endl
				<< "value pointed to by stringPTR: " << *stringPTR << std::endl
				<< "value pointed to by stringREF: " << stringREF << std::endl;
	return (0);
}
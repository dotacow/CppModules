/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:22:13 by yokitane          #+#    #+#             */
/*   Updated: 2025/09/29 19:39:57 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main (void)
{
	Bureaucrat b1("osama",1);
	std::cout << b1 << std::endl;
	b1.gpp();
	b1.gpp();
	b1.gmm();
	std::cout << b1 << std::endl;
	Bureaucrat b2("yousef",25225);
	Bureaucrat b3;
	b3 = b2;
	std::cout<< "B2: " << b2 << std::endl;
	std::cout<< "B3: " << b3 << std::endl;
	try
	{
		b3.setGrade(12312312);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
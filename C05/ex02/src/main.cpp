/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:22:13 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/01 17:34:01 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
int main (void)
{
	try
	{
		try
		{
			Bureaucrat b1("b1", 1);
			Bureaucrat b2("b2", 150);
			Form f1("f1", 10, 10);
			Form f2("f2", 150, 150);
			try
			{
				b1.signForm(f1);
				b2.signForm(f2);
				b2.signForm(f1);
				b1.signForm(f2);
				b1.signForm(f1);
				std::cout << b1 << std::endl;
				std::cout << b2 << std::endl;
				std::cout << f1 << std::endl;
				std::cout << f2 << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
		Form f3("f3", 0, 10);
		std::cout << "go to floor 31 desk 7." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
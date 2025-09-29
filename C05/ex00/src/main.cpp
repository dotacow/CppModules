/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:22:13 by yokitane          #+#    #+#             */
/*   Updated: 2025/09/29 20:01:24 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

int main (void)
{
	try
	{
		Bureaucrat b1("osama",1);
		std::cout << b1 << std::endl;
		b1.gpp(); //throws execption
		b1.gmm();
		std::cout << b1 << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b2("yousef",1500);
		std::cout << b2 << std::endl;
		b2.gmm(); //throws execption
		b2.gpp();
		try
		{
			Bureaucrat b3;
			b3 = b2;
			b3.gmm(); //throws execption
			std::cout<< "B2: " << b2 << std::endl;
			std::cout<< "B3: " << b3 << std::endl;
			b3.setGrade(12312312);//throws execption
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
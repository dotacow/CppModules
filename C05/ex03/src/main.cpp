/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:22:13 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/05 20:10:30 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Intern.hpp"

int main (void)
{
	try
	{
		Intern someRandomIntern;
		AForm* pdf;
		pdf = someRandomIntern.makeForm("robotomy request", "The ENIAC");
		Bureaucrat b("Bureaucrat", 1);
		std::cout << *pdf;
		b.signForm(*pdf);
		b.executeForm(*pdf);
		delete pdf;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
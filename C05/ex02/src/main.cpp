/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 19:22:13 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/07 14:52:30 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
int main (void)
{
	try
	{
		Bureaucrat boss("The Boss", 1);
		Bureaucrat intern("The Intern", 150);
		Bureaucrat supervisor("The Supervisor", 25);
		ShrubberyCreationForm shrub("my_home");
		PresidentialPardonForm pardon("The convict");
		RobotomyRequestForm robosurgery("WALL-E");
		supervisor.signForm(shrub);
		supervisor.signForm(pardon);
		supervisor.signForm(robosurgery);
		// intern.executeForm(shrub);
		boss.executeForm(shrub);
		boss.executeForm(robosurgery);
		boss.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
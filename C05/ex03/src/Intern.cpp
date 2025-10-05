/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 20:12:31 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/05 20:30:34 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::FormNotFoundException::FormNotFoundException(const std::string& formName, const std::string& target)
{
	this->msg = "Intern failed to create form: " + formName + " with target: " + target;
}

Intern::FormNotFoundException::~FormNotFoundException() throw() {}

const char* Intern::FormNotFoundException::what() const throw()
{
	return (this->msg.data());
}

static std::string allCaps(const std::string& str)
{
	std::string result = str;
	for (size_t i = 0; i < result.length(); i++)
	{
		result[i] = toupper(result[i]);
	}
	return (result);
}

static int getFormType(const std::string& formName)
{
	std::string temp = allCaps(formName);
	std::string formTypes[3] = {
		"SHRUBBERY CREATION",
		"ROBOTOMY REQUEST",
		"PRESIDENTIAL PARDON"
	};
	for (int i = 0; i < 3; i++)
	{
		if (temp == formTypes[i])
			return (i);
	}
	return (-1);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	int type = getFormType(formName);
	switch (type)
	{
		case 0:
			return (new ShrubberyCreationForm(target));
		case 1:
			return (new RobotomyRequestForm(target));
		case 2:
			return (new PresidentialPardonForm(target));
		default:
			throw FormNotFoundException(formName, target);
	}
}
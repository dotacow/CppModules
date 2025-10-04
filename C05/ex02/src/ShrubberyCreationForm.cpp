/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:36:22 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/04 19:07:50 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
				AForm("ShrubberyCreationForm", 145, 137),
				_target("Home of the supreme leader")
{};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
				AForm("ShrubberyCreationForm", 145, 137),
				_target(target)
{};
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
				AForm(other), _target(other.getTarget())
{};

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void ShrubberyCreationForm::execAction() const
{

};

std::ostream& operator<<(std::ostream &os, const ShrubberyCreationForm &shrubberyCreationForm)
{
	os << (static_cast<const AForm&>(shrubberyCreationForm)) << "*shrubbery section* target: " << shrubberyCreationForm.getTarget();
	return (os);
}
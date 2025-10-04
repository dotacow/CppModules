/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:36:22 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/04 19:07:41 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
				AForm("PresidentialPardonForm", 145, 137),
				_target("general pardon")
{};

PresidentialPardonForm::PresidentialPardonForm(const std::string target) :
				AForm("PresidentialPardonForm", 145, 137),
				_target(target)
{};
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) :
				AForm(other), _target(other.getTarget())
{};

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

const std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void PresidentialPardonForm::execAction() const
{

};

std::ostream& operator<<(std::ostream &os, const PresidentialPardonForm &pdf)
{
	os << (static_cast<const AForm&>(pdf)) << "*pardon section* target: " << pdf.getTarget();
	return (os);
}
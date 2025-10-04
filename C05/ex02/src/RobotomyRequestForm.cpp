/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:36:22 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/04 19:07:45 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() :
				AForm("RobotomyRequestForm", 145, 137),
				_target("Home of the supreme leader")
{};

RobotomyRequestForm::RobotomyRequestForm(const std::string target) :
				AForm("RobotomyRequestForm", 145, 137),
				_target(target)
{};
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
				AForm(other), _target(other.getTarget())
{};

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

const std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void RobotomyRequestForm::execAction() const
{

};

std::ostream& operator<<(std::ostream &os, const RobotomyRequestForm &rqf)
{
	os << (static_cast<const AForm&>(rqf)) << "*robot surgery section* target: " << rqf.getTarget();
	return (os);
}
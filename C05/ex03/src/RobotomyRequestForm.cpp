/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:36:22 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/05 20:31:12 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/randUtils.hpp"

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
	srand(time(0));
	std::cout << "*BRRRRRRRRRRRRRZZZZZZ*" << std::endl;
	if (rollDie(0,100) > 50)
		std::cout << _target << " has been robotomized successfully.";
	else
		std::cout << "robotomy failed, " << _target << "metallic's exterior proved too tough.";
	std::cout << std::endl;
};

std::ostream& operator<<(std::ostream &os, const RobotomyRequestForm &rqf)
{
	os << (static_cast<const AForm&>(rqf)) << "*robot surgery section* target: " << rqf.getTarget();
	return (os);
}
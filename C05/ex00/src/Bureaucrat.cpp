/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:17:44 by yokitane          #+#    #+#             */
/*   Updated: 2025/09/29 19:21:22 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Just another cog in the machine"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, unsigned char grade): _name(name), _grade(150)
{
	try
	{
		setGrade(grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		throw std::out_of_range("Grade is out of range");
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()), _grade(150)
{
	setGrade(other.getGrade());
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	setGrade(other.getGrade());
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	getName();
}

const std::string Bureaucrat::getName() const
{
	return (_name);
}

int Bureaucrat::getGrade() const
{
	return (static_cast<int>(_grade));
}

void Bureaucrat::setGrade(unsigned char grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

void Bureaucrat::gpp()
{
	setGrade(_grade - 1);
}

void Bureaucrat::gmm()
{
	setGrade(_grade + 1);
}
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low");
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
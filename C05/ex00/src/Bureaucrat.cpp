/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:17:44 by yokitane          #+#    #+#             */
/*   Updated: 2025/09/29 19:36:35 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Just another cog in the machine"), _grade(150)
{
}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(150)
{
	try
	{
		setGrade(grade);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()), _grade(150)
{
	try
	{
		setGrade(other.getGrade());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	try
	{
		setGrade(other.getGrade());
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
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
	return (_grade);
}

void Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	_grade = grade;
}

void Bureaucrat::gpp()
{
	try
	{
		setGrade(_grade - 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void Bureaucrat::gmm()
{
	try
	{
		setGrade(_grade + 1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
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
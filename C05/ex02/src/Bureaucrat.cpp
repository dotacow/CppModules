/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:17:44 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/05 18:11:20 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"

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
		throw;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other.getName()), _grade(150)
{
	setGrade(other.getGrade());
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
		return (*this);
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
		throw;
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
		throw;
	}
}

void Bureaucrat::signForm(AForm &form) const
{
	if (_grade <= form.getSignreq() && !form.isSigned())
	{
		std::cout << _name << " signed " << form.getName() << std::endl;
		form.beSigned(*this);
	}
	else
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because ";
		if (_grade > form.getSignreq())
			std::cout << "their grade is too low." << std::endl;
		else
			std::cout << "the form is already signed." << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << _name << " couldn't execute " << form.getName()
				  << " because " << e.what();
	}
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("grade is too high");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("grade is too low");
}

std::ostream& operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (os);
}
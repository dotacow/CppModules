/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:36:46 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/04 15:59:07 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm() :
		_name("some boring Aform"), _signreq(150), _execreq(150), _signed(false), _executed(false)
{};

AForm::AForm(const std::string name, int signreq, int execreq) :
		_name(name), _signreq(signreq), _execreq(execreq), _signed(false), _executed(false)
{
	if (signreq < 1 || execreq < 1)
		throw GradeTooHighException();
	if (signreq > 150 || execreq > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) :
		_name(other.getName()), _signreq(other.getSignreq()),
		_execreq(other.getExecreq()), _signed(other.isSigned()), _executed(other.isExecuted())
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		return (*this);
	_signed = other.isSigned();
	_executed = other.isExecuted();
	return (*this);
}

AForm::~AForm()
{
	std::cout<<"*Paper shredder noise*"<<std::endl;
}
const std::string AForm::getName() const
{
	return (_name);
}

int AForm::getSignreq() const
{
	return (_signreq);
}

int AForm::getExecreq() const
{
	return (_execreq);
}

bool AForm::isSigned() const
{
	return (_signed);
}

bool AForm::isExecuted() const
{
	return (_executed);
}

void AForm::setExecuted(bool val)
{
	_executed = val;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() <= _signreq)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::execute(const Bureaucrat &executer)
{
	if (!_signed)
	{
		std::cout << "Form " << _name << " is not signed, cannot be executed"
		<< std::endl;
		return ;
	}
	if (executer.getGrade() > _execreq)
		throw GradeTooLowException();
	this->execAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("AForm Exception: Grade Too High");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("AForm Exception: Grade Too Low");
}
std::ostream& operator<<(std::ostream &os, const AForm &Aform)
{
	os << "AForm: " << Aform.getName() << ", Sign grade requirement: "
	<< Aform.getSignreq() << ", Execute grade requirement: "
	<< Aform.getExecreq() << ", Signed: " << (Aform.isSigned() ? "Yes" : "No")
	<< std::endl;

	return (os);
}
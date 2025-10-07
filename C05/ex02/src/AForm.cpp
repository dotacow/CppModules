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
		_name("some boring Aform"), _signreq(150), _execreq(150), _signed(false)
{};

AForm::AForm(const std::string name, int signreq, int execreq) :
		_name(name), _signreq(signreq), _execreq(execreq), _signed(false)
{
	if (signreq < 1 || execreq < 1)
		throw GradeTooHighException(_name);
	if (signreq > 150 || execreq > 150)
		throw GradeTooLowException(_name);
}

AForm::AForm(const AForm &other) :
		_name(other.getName()), _signreq(other.getSignreq()),
		_execreq(other.getExecreq()), _signed(other.isSigned())
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		return (*this);
	_signed = other.isSigned();
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

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() >= _signreq)
		throw GradeTooLowException(_name);
	_signed = true;
}

void AForm::execute(const Bureaucrat &executer) const
{
	if (!_signed)
		throw FormNotSignedException(_name);
	if (executer.getGrade() > _execreq)
		throw GradeTooLowException(_name);
	try
	{
		this->execAction();
	}
	catch(const std::exception& e)
	{
		throw;
	}
}

AForm::GradeTooHighException::GradeTooHighException(const std::string &formname)
{
	_msg = "AForm exception: " + formname + ": Grade too high.\n";
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return (_msg.c_str());
}

AForm::GradeTooLowException::GradeTooLowException(const std::string &formname)
{
	_msg = "AForm exception: " + formname + ": Grade too low.\n";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return (_msg.data());
}

AForm::FormNotSignedException::FormNotSignedException(const std::string &formname)
{
	_msg = "AForm exception: " + formname + ": Form not signed.\n";
}

const char* AForm::FormNotSignedException::what() const throw()
{
	return (_msg.c_str());
}
std::ostream& operator<<(std::ostream &os, const AForm &Aform)
{
	os << "AForm: " << Aform.getName() << ", Sign grade requirement: "
	<< Aform.getSignreq() << ", Execute grade requirement: "
	<< Aform.getExecreq() << ", Signed: " << (Aform.isSigned() ? "Yes" : "No");
	return (os);
}
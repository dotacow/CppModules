/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:36:46 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/07 14:33:48 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"

Form::Form() :
		_name("some boring form"), _signreq(150), _execreq(150), _signed(false)
{};

Form::Form(const std::string name, int signreq, int execreq) :
		_name(name), _signreq(signreq), _execreq(execreq), _signed(false)
{
	if (signreq < 1 || execreq < 1)
		throw GradeTooHighException();
	if (signreq > 150 || execreq > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other) :
		_name(other.getName()), _signreq(other.getSignreq()),
		_execreq(other.getExecreq()), _signed(other.isSigned())
{
}

Form &Form::operator=(const Form &other)
{
	if (this == &other)
		return (*this);
	_signed = other.isSigned();
	return (*this);
}

Form::~Form()
{
	std::cout<<"*Paper shredder noise*"<<std::endl;
}
const std::string Form::getName() const
{
	return (_name);
}

int Form::getSignreq() const
{
	return (_signreq);
}

int Form::getExecreq() const
{
	return (_execreq);
}

bool Form::isSigned() const
{
	return (_signed);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() >= _signreq)
		throw GradeTooLowException();
	_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form Exception: Grade Too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Form Exception: Grade Too Low");
}
std::ostream& operator<<(std::ostream &os, const Form &form)
{
	os << "Form: " << form.getName() << ", Sign grade requirement: "
	<< form.getSignreq() << ", Execute grade requirement: "
	<< form.getExecreq() << ", Signed: " << (form.isSigned() ? "Yes" : "No");
	
	return (os);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:36:51 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/01 17:33:05 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		const int	_signreq;
		const int	_execreq;
		bool		_signed;
	public:
		Form();
		Form(const std::string name, int signreq, int execreq);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form();
		//getters
		const std::string	getName() const;
		int					getSignreq() const;
		int					getExecreq() const;
		bool				isSigned() const;
		//setters
		void				beSigned(const Bureaucrat &bureaucrat);
		//exceptions
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

};

std::ostream& operator<<(std::ostream &os, const Form &form);
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:36:51 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/04 15:59:27 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		const int	_signreq;
		const int	_execreq;
		bool		_signed;
	public:
		AForm();
		AForm(const std::string name, int signreq, int execreq);
		AForm(const AForm &other);
		AForm &operator=(const AForm &other);
		virtual ~AForm();
		//getters
		const std::string	getName() const;
		int					getSignreq() const;
		int					getExecreq() const;
		bool				isSigned() const;
		bool				isExecuted() const;
		//member methods
		void				beSigned(const Bureaucrat &bureaucrat);
		void				execute(const Bureaucrat &executer) const;
		virtual void		execAction() const = 0 ;
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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream &os, const AForm &Aform);
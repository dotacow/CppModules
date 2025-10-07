/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 19:49:43 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/07 14:54:03 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <string>

class Intern
{
	public:
		AForm* makeForm(std::string formName, std::string target);
		class FormNotFoundException : public std::exception
		{
			std::string msg;
			public:
				FormNotFoundException(const std::string& formName, const std::string& target);
				~FormNotFoundException() throw();
				virtual const char* what() const throw();
		};
};
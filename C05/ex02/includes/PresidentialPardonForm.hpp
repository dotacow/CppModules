/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:01:27 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/04 19:05:02 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <string>
#include <iostream>

class PresidentialPardonForm : public AForm
{
	private:
		const std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
		virtual ~PresidentialPardonForm();
		//getter(s)
		const std::string	getTarget() const;
		//member methods
		void				execAction() const;
};
std::ostream& operator<<(std::ostream &os, const PresidentialPardonForm &PresidentialPardonForm);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:01:27 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/04 18:36:14 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <string>
#include <iostream>


class ShrubberyCreationForm : public AForm
{
	private:
		const std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
		virtual ~ShrubberyCreationForm();
		//getter(s)
		const std::string	getTarget() const;
		//member methods
		void				execAction() const;
};
std::ostream& operator<<(std::ostream &os, const ShrubberyCreationForm &shrubberyCreationForm);

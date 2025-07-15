/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:57:29 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/15 23:43:24 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "ClapTrap.hpp"

class  ScavTrap : virtual public ClapTrap
{
	enum e_trapMode {NORMAL, ONGUARD};
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap &operator=(ScavTrap &other);
		ScavTrap(ScavTrap &other);
		~ScavTrap();
		void			attack(const std::string &target);
		void			takeDamage(unsigned int amount);
		void			guardGate();
		bool			isGuarding() const;
		void			setMode(e_trapMode mode);
		e_trapMode		getMode() const;
	private:
		e_trapMode	_mode;
};
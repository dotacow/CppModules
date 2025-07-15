/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 17:42:53 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/15 21:46:52 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap &operator=(ClapTrap &other);
		ClapTrap(ClapTrap &other);
		~ClapTrap();
		virtual void	attack(const std::string &target);
		virtual void	takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
		std::string		getName() const;
		unsigned int	getHP() const;
		unsigned int	getEP() const;
		unsigned int	getATK() const;
		bool			isAlive() const;
		bool			isCharged() const;
		void			setName(std::string name);
		void			setHP(unsigned int hp);
		void			setEP(unsigned int ep);
		void			setATK(unsigned int atk);
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
};

#endif//CLAPTRAP_HPP
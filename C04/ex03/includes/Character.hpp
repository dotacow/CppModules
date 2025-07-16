/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 23:01:11 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/16 23:28:54 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter
{
	public:
		Character();
		Character(std::string name);
		Character(const Character& other);
		Character& operator=(const Character& other);
		~Character();

		std::string const & getName() const;
		void equip(AMateria* materia);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

	private:
		std::string			_name;
		AMateria*			_inventory[4];
		static int			_playerCount;
		static AMateria*	_materiaPool[500];
		static int			_materiaCount;
		void				clearPool();
		void				clearInventory();
		void				addToPool(AMateria* materia);
};
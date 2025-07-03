/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:15:14 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/03 20:54:38 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB
{
	private:
		std::string _name;
		Weapon *_weapon;
	public:
		HumanB(const std::string name);
		~HumanB();
		void attack() const;
		void setWeapon(Weapon &weapon) ;
};
#endif //HUMANB_HPP
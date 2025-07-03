/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 20:27:07 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/03 20:48:44 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <string>
# include "Weapon.hpp"

class HumanA
{
	private:
		std::string _name;
		Weapon &_weapon;
	public:
		HumanA(const std::string name,Weapon &weapon);
		~HumanA();
		void attack() const;
		void setWeapon(Weapon weapon);
};
#endif //HUMANA_HPP
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:15:37 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/03 19:00:04 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP
# include <string>

class Weapon
{
	private:
		std::string _type;
	public:
		Weapon(const std::string type);
		~Weapon();
		const std::string &getType() const;
		void setType(const std::string type);
};


#endif //WEAPON_HPP
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:45:52 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/03 00:55:24 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# include <string>

class Zombie
{
	private:
		std::string _name;
	public:
		///constructors and destructors:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		///setters and getters
		std::string	getName(void) const;
		void		setName(std::string name);
		///member functions
		void		announce(void) const;
};

namespace ZUtils
{
	/**
	 * @brief
	 * Creates a new Zombie instance on the heap with the given name.
	 * @param name
	 * @return Zombie*
	 */
	Zombie *newZombie(std::string name);
	/**
	 * @brief
	 * Creates a Zombie instance on the stack, announces it, and then destroys it
	 * @param name
	 */
	void randomChump(std::string name);

	/**
	 * @brief
	 * summons the horde of the undead
	 * @param N :number of zombies in the horde
	 * @param name : name of the zombies
	 * @return Zombie* pointer to n array of zombies.
	 */
	Zombie *zombieHorde(int N, std::string name);

}
#endif // ZOMBIE_HPP
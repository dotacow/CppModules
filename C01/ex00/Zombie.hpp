/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:45:52 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/02 23:16:42 by yokitane         ###   ########.fr       */
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
		Zombie(std::string name);
		~Zombie(void);
		///setters and getters
		std::string	getName(void) const;
		void		setName(std::string name);
		///member functions
		void		announce(void) const;
};
namespace zmb
{
	/**
	 * @brief
	 * Creates a new Zombie instance on the heap with the given name.
	 * @param name
	 * @return Zombie*
	 */
	Zombie* newZombie(std::string name);
	/**
	 * @brief
	 * Creates a Zombie instance on the stack, announces it, and then destroys it
	 * @param name
	 */
	void randomChump(std::string name);
}
#endif // ZOMBIE_HPP
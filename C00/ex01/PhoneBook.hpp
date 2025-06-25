/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 01:46:51 by yokitane          #+#    #+#             */
/*   Updated: 2025/06/26 02:21:01 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_index;
		int		_size;
	public:
		PhoneBook(void);
		void		addContact(const Contact &contact);
		Contact		getContact(int index) const;
		int			getSize(void) const;
};

#endif // PHONEBOOK_HPP
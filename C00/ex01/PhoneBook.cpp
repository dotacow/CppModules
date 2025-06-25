/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 21:21:42 by yokitane          #+#    #+#             */
/*   Updated: 2025/06/26 02:18:10 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief this class serves as a container for Contact objects, maximum of 8 contacts.
*/

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : _index(0), _size(0){};

/**
 * @brief Adds a contact to the phonebook.
 * If the phonebook is full, it replaces the oldest contact.
 * @param contact The contact to add.
*/
void PhoneBook::addContact(const Contact &contact)
{
	if (_size < 8)
	{
		_contacts[_index] = contact;
		_size++;
	}
	else
		_contacts[_index] = contact;
	_index = (_index + 1) % 8; // Circular index
}
/**
 * @brief Retrieves a contact by index.
 * @param index The index of the contact to retrieve.
 * @return The contact at the specified index for valid index,default Contact is returned otherwise.
*/
Contact PhoneBook::getContact(int index) const
{
	if (index < 0 || index >= _size)
		return Contact();
	return _contacts[index];
}

int PhoneBook::getSize() const { return(_size); }
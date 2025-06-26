/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 02:22:00 by yokitane          #+#    #+#             */
/*   Updated: 2025/06/26 03:44:46 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_HPP
#define COMMANDS_HPP
# include <iostream>
# include <string>
# include <iomanip>
# include "PhoneBook.hpp"
# include <cctype>
# include <cstdlib>
/**
 * @brief Validates a phone number.
 * Checks if the phone number is in a valid format.
 * A valid phone number is either 10 digits or starts with '+' and has 13 characters.
 * @param phoneNumber The phone number to validate.
 * @return 1 if valid, 0 otherwise.
 */
int isPhoneNumberValid(const std::string phoneNumber);

/**
 * @brief save a new contact
 * Prompts the user for contact details and adds the contact.
 * If the phonebook is full, it replaces the oldest contact.
 * no field can be empty, has some basic validation.
 * @param phonebook The phonebook to add the contact to.
 */
void addContact(PhoneBook &phonebook);

/**
 * @brief display a specific contact
 * Displays a list of contacts with their index, first name, last name, and nickname.
 * Prompts the user to select a contact by index to view more details.
 * @param phonebook The phonebook to search contacts in.
 */
void searchContacts(PhoneBook &phonebook);
#endif // COMMANDS_HPP
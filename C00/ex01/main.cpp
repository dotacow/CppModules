/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 02:22:05 by yokitane          #+#    #+#             */
/*   Updated: 2025/06/26 03:02:35 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "PhoneBook.hpp"
# include "commands.hpp"

int main(void)
{
	PhoneBook phonebook = PhoneBook();
	std::string command;

	std::cout << "Welcome to the highly sophisticated MACPBook!" << std::endl;
	while (true)
	{
		std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
		std::cin>> command;
		if (command == "ADD")
			addContact(phonebook);
		else if (command == "SEARCH")
			searchContacts(phonebook);
		else if (command == "EXIT")
		{
			std::cout << "Terminating the one of a kind MACPBook. Goodbye!" << std::endl;
			break;
		}
		else
			std::cout << "Invalid command. Please try again." << std::endl;
	}
	return 0;
}
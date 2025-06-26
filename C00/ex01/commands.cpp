/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 02:50:58 by yokitane          #+#    #+#             */
/*   Updated: 2025/06/26 03:55:44 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "commands.hpp"

int isPhoneNumberValid(const std::string phoneNumber)
{
	if (phoneNumber.length() != 10 && phoneNumber.at(0) != '+')
		return 0;
	if (phoneNumber.at(0) == '+' && phoneNumber.length() != 13)
	 		return 0;
	for(size_t i = ((phoneNumber.at(0) == '+'));i < phoneNumber.length(); i++)
		if (!isdigit(phoneNumber.at(i)))
			return 0;
	return 1;
}

void addContact(PhoneBook &phonebook)
{
	std::string firstName, lastName, nickName, phoneNumber, darkestSecret;

	std::cout << "Enter first name: ";
	std::cin >> firstName;
	if (firstName == "")
	{
		std::cout << "First name cannot be empty." << std::endl;
		 return ;
	}
	std::cout << "Enter last name: ";
	std::cin >> lastName;
	if (lastName == "")
	{
		std::cout << "Last name cannot be empty." << std::endl;
		 return ;
	}
	std::cout << "Enter Nickname: ";
	std::cin >> nickName;
	if (nickName == "")
	{
		std::cout << "Nickname cannot be empty." << std::endl;
		 return ;
	}
	std::cout << "Enter phone number: ";
	std::cin >> phoneNumber;
	if (phoneNumber == "")
	{
		std::cout << "Phone number cannot be empty." << std::endl;
		return ;
	}
	if (!isPhoneNumberValid(phoneNumber))
	{
		std::cout << "invalid phone number" << std::endl;
		return ;
	}
	std::cout << "Enter darkest secret: ";
	std::cin >> darkestSecret;
	if(darkestSecret == "")
	{
		std::cout << "You have to say it. no running away." << std::endl;
		return ;
	}
	Contact newContact = Contact(firstName, lastName, nickName, phoneNumber, darkestSecret);
	phonebook.addContact(newContact);
}

void formatString(std::string &str)
{
		if (str.length() > 9)
		{
			str = str.substr(0, 9);
			str[8] = '.';
		}
}

void displayContacts(PhoneBook &phonebook)
{
	std::cout << std::right << std::setw(10) << "Index";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "First Name";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "Last Name";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "Nickname" << std::endl;
	std::cout << "----------|----------|----------|----------" << std::endl;
	for (int i = 0; i < phonebook.getSize(); i++)
	{
		Contact contact = phonebook.getContact(i);
		std::cout << std::right << std::setw(10) << i << "|";
		std::string firstName = contact.getFirstName();
		formatString(firstName);
		std::cout << std::right << std::setw(10) << firstName << "|";
		std::string lastName = contact.getLastName();
		formatString(lastName);
		std::cout << std::right << std::setw(10) << lastName << "|";
		std::string nickname = contact.getNickName();
		formatString(nickname);
		std::cout << std::right << std::setw(10) << nickname << std::endl;
	}
}

int isNumeric(const std::string &str)
{
	for (size_t i = 0; i < str.length();i++)
	{
		if (!isdigit(str.at(i)))
			return 0;
	}
	return 1;
}

void searchContacts(PhoneBook &phonebook)
{
	std::string input;
	int index;

	if (phonebook.getSize() == 0)
	{
		std::cout << "PhoneBook is empty. No contacts to display." << std::endl;
		return;
	}
	displayContacts(phonebook);
	while (true)
	{
		std::cout << "Enter the index of the contact to display (or ':q' to quit): ";
		std::cin >> input;
		if (input == ":q")
			return;
		if (input.empty() || !isNumeric(input))
		{
			std::cout << "Error: Please enter a valid index or ':q' to quit." << std::endl;
			continue;
		}
		index = std::atoi(input.c_str());
		if (index < 0 || index >= phonebook.getSize())
		{
			std::cout << "Error: Index out of range. Please enter a valid index (0-"
					  << phonebook.getSize() - 1 << ") or ':q' to quit." << std::endl;
			continue;
		}
		Contact selectedContact = phonebook.getContact(index);
		std::cout << std::endl << "Contact Details:" << std::endl;
		std::cout << "First Name: " << selectedContact.getFirstName() << std::endl;
		std::cout << "Last Name: " << selectedContact.getLastName() << std::endl;
		std::cout << "Nickname: " << selectedContact.getNickName() << std::endl;
		std::cout << "Phone Number: " << selectedContact.getPhoneNumber() << std::endl;
		std::cout << "Darkest Secret: " << selectedContact.getDarkestSecret() << std::endl;
		std::cout << std::endl;
		break;
	}
}

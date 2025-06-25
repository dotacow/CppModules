/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 21:35:32 by yokitane          #+#    #+#             */
/*   Updated: 2025/06/26 01:45:28 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Contact.hpp"

	/*CANONINCAL FORM*/
	Contact::Contact( void ) :
		_firstName(""),_lastName(""), _nickName(""), _phoneNumber(""),
		_darkestSecret(""){};
	Contact::Contact(std::string firstName, std::string lastName, std::string nickName,
					 std::string phoneNumber, std::string darkestSecret) :
		_firstName(firstName), _lastName(lastName), _nickName(nickName),
		_phoneNumber(phoneNumber), _darkestSecret(darkestSecret){};
	Contact::Contact(const Contact &other) :
		_firstName(other._firstName), _lastName(other._lastName),
		_nickName(other._nickName), _phoneNumber(other._phoneNumber),
		_darkestSecret(other._darkestSecret){};
	Contact &Contact::operator=(const Contact &other)
	{
		if (this != &other)
		{
			_firstName = other._firstName;
			_lastName = other._lastName;
			_nickName = other._nickName;
			_phoneNumber = other._phoneNumber;
			_darkestSecret = other._darkestSecret;
		}
		return (*this);
	}
	Contact::~Contact( void ){};
			/*GETTERS*/
	std::string	Contact::getFirstName() const { return (_firstName); }
	std::string	Contact::getLastName() const { return (_lastName); }
	std::string	Contact::getNickName() const { return (_nickName); }
	std::string	Contact::getPhoneNumber() const { return (_phoneNumber); }
	std::string Contact::getDarkestSecret() const{ return (_darkestSecret); }
			/*SETTERS*/
	void	Contact::setFirstName(std::string firstName) { this->_firstName = firstName; }
	void	Contact::setLastName(std::string lastName){ this->_lastName = lastName; }
	void	Contact::setNickName(std::string nickName){ this->_nickName = nickName; }
	void	Contact::setPhoneNumber(std::string phoneNumber){ this->_phoneNumber = phoneNumber; }
	void	Contact::setDarkestSecret(std::string darkestSecret){ this->_darkestSecret = darkestSecret; }
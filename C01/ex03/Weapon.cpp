/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:15:35 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/03 20:48:46 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Weapon.hpp"

Weapon::Weapon(const std::string type): _type(type){};
Weapon::~Weapon(){};
const std::string &Weapon::getType() const { return (this->_type);}
void Weapon::setType(const std::string type) {this->_type = type;}
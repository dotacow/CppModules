/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:08:32 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/13 14:58:46 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include <limits>
#include <errno.h>
#include <iostream>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other){}
ScalarConverter::~ScalarConverter() {}


static e_LiteralType getLiteralType(std::string str)
{

	char *endptr;

	if (str.length() == 1 && !isdigit(str[0]))
		return CHAR;
	if (str == "-inff" || str == "+inff" || str == "nan")
		return PSEUDO;
	{
		long val = strtol(str.c_str(), &endptr, 10);
		if (errno != ERANGE && val <= std::numeric_limits<int>::max() &&
			val >= std::numeric_limits<int>::min() && *endptr == '\0')
				return INT;
	}
	{
		float val = strtof(str.c_str(), &endptr);
		if ( errno != ERANGE && val <= std::numeric_limits<float>::max() &&
			val >= std::numeric_limits<float>::min() &&
			*endptr == 'f' && *(endptr + 1) == '\0')
				return FLOAT;
	}
	{
		double val = strtod(str.c_str(), &endptr);
		if (errno != ERANGE && *endptr == '\0' && val <= std::numeric_limits<double>::max()
			&& val >= std::numeric_limits<double>::min())
				return DOUBLE;
	}
	return NON_LITERAL;
}
static void toChar(std::string str, e_LiteralType type)
{
	if (type == NON_LITERAL || type == PSEUDO)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	double val = strtod(str.c_str(), NULL);
	if (val != static_cast<int>(val) || val < 0 || val > 127)
	{
		std::cout << "char: impossible" << std::endl;
		return ;
	}
	if(val < 32 || val == 127)
	{
		std::cout << "char: Non displayable" << std::endl;
		return ;
	}
	std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
}
static void toInt(std::string str, e_LiteralType type);
static void toFloat(std::string str, e_LiteralType type);
static void toDouble(std::string str, e_LiteralType type);

void ScalarConverter::convert(std::string str)
{

}
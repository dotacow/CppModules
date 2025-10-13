/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:08:32 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/13 15:58:56 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"
#include <limits>
#include <errno.h>
#include <iostream>
#include <cstdlib>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &other){(void)other;}
ScalarConverter::~ScalarConverter() {}

static e_LiteralType getLiteralType(std::string str)
{

	char *endptr;

	if (str.length() == 1 && str[0] >= 32 && str[0] <= 126)
		return CHAR;
	if (str == "-inf" || str == "+inf" || str == "nan")
		return PSEUDO;
	{
		int len = str.length();
		if ((str[0] == '-' || str[0] == '+') && len > 1)
			len--;
		long long val = strtol(str.c_str(), &endptr, 10);
		if (errno != ERANGE && val <= std::numeric_limits<int>::max() &&
			val >= std::numeric_limits<int>::min() && *endptr == '\0')
				return INT;
	}
	{
		 float val = strtof(str.c_str(), &endptr);
		if (errno != ERANGE && val <= std::numeric_limits<float>::max() &&
			val >= std::numeric_limits<float>::min() &&
			*endptr == 'f' && *(endptr + 1) == '\0')
				return FLOAT;
	}
	{
		long double val = strtod(str.c_str(), &endptr);
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
		std::cout << "char: impossible\n";
		return ;
	}
	errno = 0;
	double val = strtod(str.c_str(), NULL);
	if (val != static_cast<int>(val) || val < 0 || val > 127)
	{
		std::cout << "char: impossible\n";
		return ;
	}
	if(val < 32 || val == 127)
	{
		std::cout << "char: Non displayable\n";
		return ;
	}
	std::cout << "char: '" << static_cast<char>(val) << "'\n";
}
static void toInt(std::string str, e_LiteralType type)
{
	if (type == NON_LITERAL || type == PSEUDO)
	{
		std::cout << "int: impossible\n";
		return ;
	}
	errno = 0;
	long long val = strtol(str.c_str(), NULL, 10);
	if (errno == ERANGE)
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << val << "\n";
}
static void toFloat(std::string str, e_LiteralType type)
{
	if (type == NON_LITERAL)
	{
		std::cout << "float: impossible\n";
		return ;
	}
	if (type == PSEUDO)
		std::cout << "float: " << str << "f\n";
	else
	{
		errno = 0;
		float val = strtof(str.c_str(), NULL);
		if (errno == ERANGE)
			std::cout << "float: impossible\n";
		else
		{
			if (val == static_cast<int>(val))
				std::cout << "float: " << val << ".0";
			else
				std::cout << "float: " << val;
			std::cout << "f\n";
		}
	}
}
static void toDouble(std::string str, e_LiteralType type)
{
	if (type == NON_LITERAL)
	{
		std::cout << "double: impossible\n";
		return ;
	}
	if (type == PSEUDO)
		std::cout << "double: " << str << "\n";
	else
	{
		errno = 0;
		double val = strtod(str.c_str(), NULL);
		if (errno == ERANGE)
			std::cout << "double: impossible\n";
		else
		{
			if (val == static_cast<int>(val))
				std::cout << "double: " << val << ".0\n";
			else
				std::cout << "double: " << val << "\n";
		}
	}
}

void ScalarConverter::convert(std::string str)
{
	e_LiteralType type = getLiteralType(str);
	toChar(str, type);
	toInt(str, type);
	toFloat(str, type);
	toDouble(str, type);
}
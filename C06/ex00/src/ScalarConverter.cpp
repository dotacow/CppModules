/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:51:47 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/15 14:26:12 by yokitane         ###   ########.fr       */
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
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

static e_LiteralType getLiteralType(std::string str)
{
	char	*endptr;

	if (str.empty())
		return NON_LITERAL;
	if (str.length() == 1 && !isdigit(str[0]))
		return CHAR;
	if (str == "-inf" || str == "+inf" || str == "nan")
		return PSEUDOD;
	if (str == "-inff" || str == "+inff" || str == "nanf")
		return PSEUDOF;
	{
		errno = 0;
		long val = strtol(str.c_str(), &endptr, 10);
		if (errno != ERANGE && val <= std::numeric_limits<int>::max() &&
			val >= std::numeric_limits<int>::min() && *endptr == '\0' && endptr != str.c_str())
				return INT;
	}
	{
		errno = 0;
		float val = strtof(str.c_str(), &endptr);
		if (errno != ERANGE && val <= std::numeric_limits<float>::max() &&
			val >= -std::numeric_limits<float>::max() &&
			*endptr == 'f' && *(endptr + 1) == '\0' && endptr != str.c_str())
				return FLOAT;
	}
	{
		errno = 0;
		long double val = strtod(str.c_str(), &endptr);
		if (errno != ERANGE && *endptr == '\0' && val <= std::numeric_limits<double>::max()
			&& val >= -std::numeric_limits<double>::max() && endptr != str.c_str())
				return DOUBLE;
	}
	return NON_LITERAL;
}

static void toChar(std::string str, e_LiteralType type)
{
	if (type == NON_LITERAL || type == PSEUDOF || type == PSEUDOD)
	{
		std::cout << "char: impossible\n";
		return ;
	}
	if (type == CHAR)
	{
		char c = str[0];
		if (c < 32 || c == 127)
			std::cout << "char: Non displayable\n";
		else
			std::cout << "char: '" << c << "'\n";
		return;
	}
	errno = 0;
	double val = strtod(str.c_str(), NULL);
	if (errno == ERANGE || val != static_cast<int>(val) || val < 0 || val > 127)
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
	if (type == NON_LITERAL || type == PSEUDOF || type == PSEUDOD)
	{
		std::cout << "int: impossible\n";
		return ;
	}
	if (type == CHAR)
	{
		std::cout << "int: " << static_cast<int>(str[0]) << "\n";
		return;
	}
	errno = 0;
	char *endptr;
	long val = strtol(str.c_str(), &endptr, 10);
	if (errno == ERANGE || val > std::numeric_limits<int>::max() ||
		val < std::numeric_limits<int>::min())
	{
		std::cout << "int: impossible\n";
	}
	else
	{
		std::cout << "int: " << static_cast<int>(val) << "\n";
	}
}

static void toFloat(std::string str, e_LiteralType type)
{
	if (type == NON_LITERAL)
	{
		std::cout << "float: impossible\n";
		return ;
	}
	if (type == PSEUDOF)
	{
		std::cout << "float: " << str << "\n";
		return;
	}
	if (type == PSEUDOD)
	{
		std::cout << "float: " << str << "f\n";
		return;
	}
	if (type == CHAR)
	{
		std::cout << "float: " << static_cast<float>(str[0]) << ".0f\n";
		return;
	}
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

static void toDouble(std::string str, e_LiteralType type)
{
	if (type == NON_LITERAL || type == PSEUDOF)
	{
		std::cout << "double: impossible\n";
		return ;
	}
	if (type == PSEUDOD)
	{
		std::cout << "double: " << str << "\n";
		return;
	}
	if (type == CHAR)
	{
		std::cout << "double: " << static_cast<double>(str[0]) << ".0\n";
		return;
	}
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

void ScalarConverter::convert(std::string str)
{
	e_LiteralType type = getLiteralType(str);
	toChar(str, type);
	toInt(str, type);
	toFloat(str, type);
	toDouble(str, type);
}
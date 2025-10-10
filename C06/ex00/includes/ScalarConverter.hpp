/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 17:27:29 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/10 18:23:38 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>


enum e_LiteralType
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	NON_LITERAL = -1,
};

typedef struct s_data
{
	char	c;
	int		i;
	float	f;
	double	d;
} t_data;

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		~ScalarConverter();
		e_LiteralType identifyType(std::string str);
		char	toChar(std::string str);
		int		toInt(std::string str);
		float	toFlt(std::string str);
		double	toDbl(std::string str);
	public:
		static void convert(std::string str);
};
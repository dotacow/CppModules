/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 17:06:56 by yokitane          #+#    #+#             */
/*   Updated: 2025/06/22 17:51:27 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <cctype>

int main(int argc, char **argv)
{
	std::string str;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE * \n";
	else
	{
		for (int i = 1; i < argc; i++)
		{
			str = argv[i];
			for(int j = 0; j <(int)str.length();j++)
				std::cout <<(char)toupper(str.at(j));
		}
	}
	std::cout<<"\n";
	return (0);
}

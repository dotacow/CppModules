/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 21:25:52 by yokitane          #+#    #+#             */
/*   Updated: 2025/07/06 05:13:34 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

int main (int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr	<< "usage:./sed++ \"filename\" \"s1\" \"s2\" \n";
		return (1);
	}
	std::string filename = argv[1];
	std::ifstream inFile(filename.c_str());
	if (!inFile.is_open() || !inFile.good())
	{
		std::cerr	<< "Error: Could not open file " << argv[1] << std::endl;
		return (1);
	}
	std::ofstream outFile(std::string(filename + ".replace").c_str());
	if (!outFile.is_open() || !outFile.good())
	{
		std::cerr	<< "Error: Could not create output file "
					<< filename << ".replace" << std::endl;
		inFile.close();
		return (1);
	}
	std::string word = argv[2];
	std::string filter = argv[3];
	std::string temp;
	size_t width = word.length();
	while (!inFile.eof() && inFile.good())
	{
		std::string result;
		std::getline(inFile,temp);
		if (temp.empty())
		{
			outFile << "\n";
			continue;
		}
		size_t i = 0;
		while (i < temp.length())
		{
			if (temp.substr(i, width) == word)
			{
				result += filter;
				i += width;
			}
			else
			{
				result += temp[i];
				i++;
			}
		}
		outFile << result;
		if (inFile.peek() != EOF)
			outFile << "\n";
	}
	inFile.close();
	outFile.close();
	return (0);
}
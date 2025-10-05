/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:36:22 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/05 18:21:40 by yokitane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ShrubberyCreationForm.hpp"
#include <fstream>
#include <cstdlib>
#include "../includes/randUtils.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() :
				AForm("ShrubberyCreationForm", 145, 137),
				_target("Home of the supreme leader")
{};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) :
				AForm("ShrubberyCreationForm", 145, 137),
				_target(target)
{};
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
				AForm(other), _target(other.getTarget())
{};

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

const std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void ShrubberyCreationForm::execAction() const
{
	srand(time(0));
	std::string filename = _target + "_shrubbery";
	std::ofstream outfile(filename.c_str());
	if (!outfile)
		throw std::ios_base::failure("Error: Could not create file.");

	int numTrees = rollDie(3, 6);

	for (int t = 0; t < numTrees; t++)
	{
		int treeType = rollDie(0, 2);

		if (treeType == 0)
		{
			outfile << "      *\n";
			outfile << "     ***\n";
			outfile << "    *****\n";
			outfile << "   *******\n";
			outfile << "  *********\n";
			outfile << " ***********\n";
			outfile << "      |||\n";
			outfile << "      |||\n";
		}
		else if (treeType == 1)
		{
			outfile << "      /\\\n";
			outfile << "     /*o\\\n";
			outfile << "    /o*o*\\\n";
			outfile << "   /*o*o*o\\\n";
			outfile << "  /o*o*o*o*\\\n";
			outfile << " /*o*o*o*o*o\\\n";
			outfile << "       |\n";
		}
		else
		{
			outfile << "     /\\\n";
			outfile << "    /^&\\\n";
			outfile << "   /^@&^\\\n";
			outfile << "  /&^@^&@\\\n";
			outfile << " /@^&@^&@^\\\n";
			outfile << "/^&@^&@^&@&\\\n";
			outfile << "     | |\n";
			outfile << "     | |\n";
		}
		if (t < numTrees - 1)
			outfile << "\n";
	}

	outfile.close();
}
std::ostream& operator<<(std::ostream &os, const ShrubberyCreationForm &shrubberyCreationForm)
{
	os << (static_cast<const AForm&>(shrubberyCreationForm)) << "*shrubbery section* target: " << shrubberyCreationForm.getTarget();
	return (os);
}
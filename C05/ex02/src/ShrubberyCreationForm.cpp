/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokitane <yokitane@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 18:36:22 by yokitane          #+#    #+#             */
/*   Updated: 2025/10/07 14:37:26 by yokitane         ###   ########.fr       */
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
	int numTrees = rollDie(2, 4);

	for (int i = 0; i < numTrees; i++)
	{
		int treeType = rollDie(0, 2);
		if (treeType == 0)
		{
			outfile << "                     ; ; ;\n";
			outfile << "                   ;        ;  ;     ;;    ;\n";
			outfile << "                ;                 ;         ;  ;\n";
			outfile << "                                ;\n";
			outfile << "                               ;                ;;\n";
			outfile << "               ;          ;            ;              ;\n";
			outfile << "               ;            ';,        ;               ;\n";
			outfile << "               ;              'b      *\n";
			outfile << "                ;              '$    ;;                ;;\n";
			outfile << "               ;    ;           $:   ;:               ;\n";
			outfile << "             ;;      ;  ;;      *;  @):        ;   ; ;\n";
			outfile << "                          ;     :@,@):   ,;**:'   ;\n";
			outfile << "              ;      ;,         :@@*: ;;**'      ;   ;\n";
			outfile << "                       ';o;    ;:(@';@*\"'  ;\n";
			outfile << "               ;  ;       'bq,;;:,@@*'   ,*      ;  ;\n";
			outfile << "                          ,p$q8,:@)'  ;p*'      ;\n";
			outfile << "                   ;     '  ; '@@Pp@@*'    ;  ;\n";
			outfile << "                    ;  ; ;;    Y7'.'     ;  ;\n";
			outfile << "                              :@):.\n";
			outfile << "                             .:@:'.\n";
			outfile << "                           .::(@:.      \n";
		}
		else if (treeType == 1)
		{
			outfile << "                      ___\n";
			outfile << "                _,-'\"\"   \"\"\"\"`.--.\n";
			outfile << "             ,-'          __,,-- \\\n";
			outfile << "           ,'    __,--\"\"\"\"dF      )\n";
			outfile << "          /   .-\"Hb_,--\"\"dF      /\n";
			outfile << "        ,'       _Hb ___dF\"-._,-'\n";
			outfile << "      ,'      _,-\"\"\"\"\"   \"\"--..__\n";
			outfile << "     (     ,-'                  `.\n";
			outfile << "      `._,'     _   _             ;\n";
			outfile << "       ,'     ,' `-'Hb-.___..._,-'\n";
			outfile << "       \\    ,'\"Hb.-'HH`-.dHF\"\n";
			outfile << "        `--'   \"Hb  HH  dF\"\n";
			outfile << "                \"Hb HH dF\n";
			outfile << "                 \"HbHHdF\n";
			outfile << "                  |HHHF\n";
			outfile << "                  |HHH|\n";
			outfile << "                  |HHH|\n";
			outfile << "                  |HHH|\n";
			outfile << "                  |HHH|\n";
			outfile << "                  dHHHb\n";
			outfile << "                .dFd|bHb.\n";
			outfile << "      o       .dHFdH|HbTHb.          o\n";
			outfile << "\\  Y  |  \\__,dHHFdHH|HHhoHHb.__     Y\n";
		}
		else if (treeType == 2)
		{
			outfile << "              _{\\ _{\\{\\/)}/}/}__\n";
			outfile << "             {/{/\\}{/{/\\}(\\}{/\\} _\n";
			outfile << "            {/{/\\}{/{/\\}(_)\\}{/{/\\}  _\n";
			outfile << "         {\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\} /\\}\n";
			outfile << "        {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}\n";
			outfile << "       _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}\n";
			outfile << "      {/{/{\\{\\{\\(/}{\\{\\/}/}{\\}(_){\\/}\\}\n";
			outfile << "      _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}\n";
			outfile << "     {/{/{\\{\\(/}{/{\\{\\{\\/})}/}{\\(_)/}/}\\}\n";
			outfile << "      {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/})/}\n";
			outfile << "       {/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)\n";
			outfile << "      {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\n";
			outfile << "       {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}\n";
			outfile << "         {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}\n";
			outfile << "          (_){/{\\/)}{\\{\\/}/}{\\{\\)/}/}(_)\n";
			outfile << "            {/{/{\\{\\/}{/{\\{\\{\\(_)/}\n";
			outfile << "             {/{\\{\\{\\/}/}{\\{\\\\}/}\n";
			outfile << "              {){/ {\\/}{\\/} \\}\\}\n";
			outfile << "              (_)  \\.-'.-/\n";
			outfile << "          __...--- |'-.-'| --...__\n";
			outfile << "   _...--\"   .-'   |'-.-'|  ' -.  \"\"--..__\n";
			outfile << " -\"    ' .  . '    |.'-._| '  . .  '\n";
			outfile << " .  '-  '    .--'  | '-.'|    .  '  . '\n";
			outfile << "          ' ..     |'-_.-|\n";
			outfile << "  .  '  .       _.-|-._ -|-._  .  '  .\n";
			outfile << "              .'   |'- .-|   '.\n";
			outfile << "  ..-'   ' .  '.   `-._.-'   .'  '  - .\n";
			outfile << "   .-' '        '-._______.-'     '  .\n";
			outfile << "        .      ~,\n";
			outfile << "    .       .   |\\   .    ' '-.\n";
		}
		if (i < numTrees - 1)
			outfile << "\n\n";
	}
	outfile.close();
}
std::ostream& operator<<(std::ostream &os, const ShrubberyCreationForm &shrubberyCreationForm)
{
	os << (static_cast<const AForm&>(shrubberyCreationForm)) << "*shrubbery section* target: " << shrubberyCreationForm.getTarget();
	return (os);
}
#include <iostream>
#include "../includes/RPN.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " \"RPN expression\"\n";
		return (1);
	}
	try
	{
		RPN rpn(argv[1]);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}
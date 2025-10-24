#include "../includes/MutantStack.hpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
int main(void)
{
	std::srand(time(NULL));
	MutantStack<int> stack;
	std::vector<int>	vec;

	for (int i = 0; i < 50; i++)
	{
		int value = std::rand() % 500;
		stack.push(value);
		vec.push_back(value);
	}
	std::sort(stack.begin(), stack.end());
	std::sort(vec.begin(), vec.end());
	MutantStack<int>::const_iterator it_stack = stack.cbegin();
	MutantStack<int>::const_iterator ite_stack = stack.cend();
	std::vector<int>::const_iterator it_vec = vec.begin();
	std::vector<int>::const_iterator ite_vec = vec.end();
	while((it_stack != ite_stack) && (it_vec != ite_vec))
	{
		std::cout << "stack: " << *it_stack << " | vec: " << *it_vec << std::endl;
		if (*it_stack != *it_vec)
		{
			std::cout << "Error: values do not match!" << std::endl;
			return (1);
		}
		++it_stack;
		++it_vec;
	}
	return (0);
};
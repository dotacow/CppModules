#include "../includes/Span.hpp"
#include "../includes/VecSpan.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

#define N_LIMIT 9000000l

int main(int argc, char** argv)
{
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout<< "END PROOF OF CONCEPT\n";
	}
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <n>\n";
		return 1;
	}
	std::srand(time(NULL));
	long size = (std::atoi(argv[1]));
	if (size >= N_LIMIT || size <= 1)
	{
		std::cerr << "n valid range > 1, < " << N_LIMIT <<"\n";
		return 1;
	}
	VecSpan sp(size);
	for (long i = 0; i < size / 2; i++)
	{
		if (i % 2)
			sp.addNumber(std::rand());
		else
			sp.addNumber(-std::rand());
	}
	clock_t start = clock();
	std::cout << "Shortest Span: " << sp.shortestSpan() << "\n";
	std::cout << "Longest Span: " << sp.longestSpan() << "\n";
	for (long i = size / 2; i < size; i++)
	{
		if (i % 2)
			sp.addNumber(std::rand());
		else
			sp.addNumber(-std::rand());
	}
	std::cout << "Second shortest Span: " << sp.shortestSpan() << "\n";
	std::cout << "Second longest Span: " << sp.longestSpan() << "\n";
	clock_t end = clock();
	double time_taken = double(end - start) / CLOCKS_PER_SEC;
	std::cout << "Time taken by program is : " << time_taken << "seconds\n";
	return (0);
}
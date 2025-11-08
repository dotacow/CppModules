#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <vector>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Usage: " << argv[0] << " <list of integers>" << std::endl;
		return 1;
	}
	std::deque<int> dq;
	std::vector<int> vc;
	for (int i = 1; i < argc; ++i)
	{
		if (!std::isdigit(argv[i][0]) && !(argv[i][0] == '-' && std::isdigit(argv[i][1])))
		{
			std::cerr << "Error: Invalid input '" << argv[i] << "'. Only integers are allowed." << std::endl;
			return 1;
		}
		int num = std::atoi(argv[i]);
		dq.push_back(num);
		vc.push_back(num);
	}
	std::cout << "Before sorting:" << std::endl;
	for (std::vector<int>::iterator it = vc.begin(); it != vc.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	clock_t startdq = clock();
	PmergeMe pms2(dq);
	clock_t enddq = clock();
	clock_t startvc = clock();
	PmergeMe pms3(vc);
	clock_t endvc = clock();
	std::cout << "After sorting:" << std::endl;
	for (std::vector<int>::iterator it = vc.begin(); it != vc.end(); it++)
		std::cout << *it << " ";
	std::cout << "\n";
	std::cout << "Time taken to sort std::deque: "
				<< static_cast<double>(enddq - startdq) / CLOCKS_PER_SEC  << " sec\n";
	std::cout << "Time taken to sort std::vector: "
				<< static_cast<double>(endvc - startvc) / CLOCKS_PER_SEC << " sec\n";
	return (0);
}
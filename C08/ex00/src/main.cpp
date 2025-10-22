#include "../includes/easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main(int argc, char **argv)
{
	if (argc < 3)
	{
		std::cerr << "Usage: ./easyfind target numbers_to_find\n";
		return 1;
	}
	std::vector<int> vec;
	std::list<int> lst;
	std::deque<int> deq;
	int needle = std::atoi(argv[1]);
	for (int i = 2; i < argc; ++i)
	{
		int num = std::atoi(argv[i]);
		vec.push_back(num);
		lst.push_back(num);
		deq.push_back(num);
	}
	std::cout << "Searching in vector:\n";
	std::vector<int>::iterator vecIt = easyfind(vec, needle);
	if (vecIt != vec.end())
		std::cout << "vecIt points to value: " << *vecIt << "\n";

	std::cout << "Searching in list:\n";
	std::list<int>::iterator lstIt = easyfind(lst, needle + 2);
	if (lstIt != lst.end())
		std::cout << "lstIt points to value: " << *lstIt << "\n";

	std::cout << "Searching in deque:\n";
	std::deque<int>::iterator deqIt = easyfind(deq, needle - 2);
	if (deqIt != deq.end())
		std::cout << "deqIt points to value: " << *deqIt << "\n";
}
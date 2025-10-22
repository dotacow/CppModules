
#include <algorithm>
#include <iostream>
#include <iterator>

template<typename T> typename T::iterrator easyfind(const T& haystack, int needle)
{
		typename T::iterator it = std::find(haystack.begin(), haystack.end(), needle);
		if (it == haystack.end())
			std::cerr << "Value " << needle << " does not exist.\n";
		std::cout << "Value " << needle << " found at [" << std::distance(haystack.begin(), it)<< "] index.\n";
		return it;
};
#include "../includes/iter.hpp"
#include <iostream>


int main (void)
{

	int		IntArray[] = {1, 2, 3};
	const float	FloatArray[] = {1.1f, 2.2f, 3.3f};


	std::cout << "----- Original IntArray -----" << std::endl;
	iterator<int>::iter(IntArray, 3, iterator<int>::printType);
	iterator<int>::iter(IntArray, 3, iterator<int>::multiplyByTwo);
	std::cout << "----- After multiplyByTwo -----" <<  std::endl;
	iterator<int>::iter(IntArray, 3, iterator<int>::printType);
	std::cout << "----- Original FloatArray -----" << std::endl;
	iterator<float>::iter(FloatArray, 3, iterator<float>::printType);
	return (0);
}

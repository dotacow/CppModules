#include "../includes/whatever.hpp"
#include <iostream>

int main( void )
{
	int a = 2;
	int b = 3;

	whatever<int>::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << whatever<int>::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << whatever<int>::max( a, b ) << std::endl;

	std::string d = "chaine2";
	std::string c = "chaine1";

	whatever<std::string>::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << whatever<std::string>::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << whatever<std::string>::max( c, d ) << std::endl;
	
	return 0;
}

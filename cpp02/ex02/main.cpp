#include "Fixed.hpp"
#include <iostream>

int main( void ) { 
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << Fixed::min( a, b ) << std::endl;

	Fixed x(3);
	Fixed y(7);
	x = 10;
	std::cout << Fixed::min(x, y) << std::endl;
	std::cout << Fixed::max(x, y) << std::endl;

	Fixed const c(3);
	Fixed const d(7);
	//c = 10;
	std::cout << Fixed::min(c, d) << std::endl;
	std::cout << Fixed::max(c, d) << std::endl;
	return 0; 
}
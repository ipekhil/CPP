#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;

	std::cout << "DEBUG :  ";
    harl.complain("debug");
	std::cout << "INFO :  ";
    harl.complain("info");
	std::cout << "WARNING :  ";
    harl.complain("warning");
	std::cout << "ERROR :  ";
    harl.complain("error");
    
    return 0;
}
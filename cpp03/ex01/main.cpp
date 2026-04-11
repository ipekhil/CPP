#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap ali("Ali");
	ali.attack("Ahmet");
	ali.takeDamage(5);
	ali.beRepaired(3);

	std::cout << std::endl;

	ScavTrap veli("Veli");
	veli.attack("Mehmet");
	veli.takeDamage(50);
	veli.beRepaired(20);
	veli.guardGate();

	std::cout << std::endl;

	ScavTrap copy(veli);
	copy.attack("someone");

	return 0;
}

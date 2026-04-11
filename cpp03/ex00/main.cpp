#include "ClapTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap ali("Ali");
	ali.attack("Ahmet");
	ali.takeDamage(5);
	ali.beRepaired(3);

	std::cout << std::endl;
	ClapTrap veli("Veli");
	veli.takeDamage(10);
	veli.attack("someone");
	veli.beRepaired(5);

	std::cout << std::endl;
	ClapTrap zeynep("Zeynep");
	for (int i = 0; i < 10; i++)
		zeynep.attack("İpek");
	zeynep.attack("İpek");
	zeynep.takeDamage(10);
	zeynep.takeDamage(10);
	zeynep.beRepaired(5);

	std::cout << std::endl;
	ClapTrap copy(ali);
	copy.attack("someone");

	return 0;
}

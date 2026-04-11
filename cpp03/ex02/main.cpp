#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	std::cout << "FragTrap" << std::endl;
	{
		FragTrap ali("Ali");
		ali.attack("Ahmet");
		ali.takeDamage(50);
		ali.beRepaired(20);
		ali.highFivesGuys();
	}

	std::cout << std::endl;

	std::cout << "ScavTrap" << std::endl;
	{
		ScavTrap veli("Veli");
		veli.attack("Mehmet");
		veli.guardGate();
	}

	std::cout << std::endl;

	FragTrap zeynep("Zeynep");
	FragTrap copy(zeynep);
	copy.highFivesGuys();

	return 0;
}

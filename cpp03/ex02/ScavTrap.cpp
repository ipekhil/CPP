#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap default constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(std::string const &name_) : ClapTrap(name_)
{
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 20;
	std::cout << "ScavTrap constructor called for " << name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src)
{
	std::cout << "ScavTrap copy constructor called for " << src.name << std::endl;
	*this = src;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called for " << name << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (hitPoints == 0)
	{
		std::cout << "ScavTrap " << name << " can't attack because it has no hit points!" << std::endl;
		return;
	}
	if (energyPoints == 0)
	{
		std::cout << "ScavTrap " << name << " can't attack because it has no energy points!" << std::endl;
		return;
	}
	energyPoints--;
	std::cout << "ScavTrap " << name << " attacks " << target
			  << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}

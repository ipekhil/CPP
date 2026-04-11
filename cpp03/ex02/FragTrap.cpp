#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap default constructor called for " << name << std::endl;
}

FragTrap::FragTrap(std::string const &name_) : ClapTrap(name_)
{
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;
	std::cout << "FragTrap constructor called for " << name << std::endl;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src)
{
	std::cout << "FragTrap copy constructor called for " << src.name << std::endl;
	*this = src;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called for " << name << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	if (this != &rhs)
		ClapTrap::operator=(rhs);
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " requests a positive high five!" << std::endl;
}

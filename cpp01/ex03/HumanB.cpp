#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = 0;
}
void HumanB::setWeapon(Weapon& weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack()
{
	if (this->weapon)
	{
		std::cout << name << " attacks with their " << this->weapon->getType() << std::endl;
	}
	
}


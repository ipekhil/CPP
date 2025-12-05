#include "Weapon.hpp"
#include <iostream>

Weapon::Weapon(std::string str)
{
	this->type = str;
}

const std::string& Weapon::getType() const
{
	return type;
}
void Weapon::setType(std::string type)
{
	this->type = type;
}
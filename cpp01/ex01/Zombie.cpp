#include "Zombie.hpp"

Zombie::Zombie()
{
	std::cout << "Constructure çalıştı" << std::endl;
}

Zombie::~Zombie()
{
	std::cout << "Zombie Destructure çalıştı" << std::endl; 

}
void Zombie::announce()
{
	std::cout << name << " : BraiiiiiiinnnzzzZ" << std::endl; 
}

void Zombie::set_name(std::string name)
{
	this->name = name;
}
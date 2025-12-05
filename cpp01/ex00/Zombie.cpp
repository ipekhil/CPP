#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << "Zombie Constructor çalıştı"<< std::endl; 
}
Zombie::~Zombie()
{
	std::cout << "Zombie Destructure çalıştı" << std::endl; 

}
void Zombie::announce()
{
	std::cout << name << " : BraiiiiiiinnnzzzZ" << std::endl; 
}

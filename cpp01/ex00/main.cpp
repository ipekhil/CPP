#include "Zombie.hpp"

void randomChump(std::string name);
Zombie *newZombie(std::string name);

int main()
{
	randomChump("hilal");
	Zombie *newzombie;
	newzombie = newZombie("ipek");
	delete newzombie;
}
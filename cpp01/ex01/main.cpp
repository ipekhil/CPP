#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name );

int main()
{
	Zombie *horde;
	int n;
	n = 5;
	horde = zombieHorde(n, "ZomBiE");
	for (int i = 0; i < n; i++)
	{
		std::cout << i + 1 << ".";
		horde->announce();
	}
	
	delete[] horde;
}
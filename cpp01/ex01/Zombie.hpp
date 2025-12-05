#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
private:
	std::string name;
public:
	Zombie();
	void set_name(std::string name);
	~Zombie();
	void announce();
};

#endif
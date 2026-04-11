#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string const &name_);
		ScavTrap(ScavTrap const &src);
		~ScavTrap();

		ScavTrap	&operator=(ScavTrap const &rhs);

		void	attack(const std::string &target);
		void	guardGate();
};

#endif

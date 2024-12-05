#ifndef SCAVTRAP
# define SCAVTRAP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap{
	public:
		ScavTrap();
		ScavTrap(ScavTrap &scavTrap);
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap &scavTrap);
		void guardGate();
		std::string type() const;
		void attack(const std::string& target);
		void showStats();
};

#endif

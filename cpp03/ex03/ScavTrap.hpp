#ifndef SCAVTRAP
# define SCAVTRAP

#include "ClapTrap.hpp"

/*We make ClapTrap virtual so that, when one class inherits
from multiple ClapTrap subclasses, there is only one instance
of ClapTrap, avoiding the diamond problem.*/
class ScavTrap: public virtual ClapTrap{
	public:
		ScavTrap();
		ScavTrap(ScavTrap &scavTrap);
		ScavTrap(std::string name);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap &scavTrap);
		void guardGate();
		std::string type() const;
		void attack(const std::string& target);

};

#endif
#ifndef CLAPTRAP
# define CLAPTRAP

#include <iostream>
#include <cstring>
#include <iomanip>

class ClapTrap{
	protected:
		std::string _name;
		unsigned int _hitPoints;
		unsigned int _energyPoints;
		unsigned int _attackDamage;

	public:
		ClapTrap();
		ClapTrap(ClapTrap &clapTrap);
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &clapTrap);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		virtual void showStats();
		virtual std::string type() const;
};

#endif

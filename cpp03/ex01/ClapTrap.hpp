#ifndef CLAPTRAP
# define CLAPTRAP

#include <iostream>
#include <cstring>
#include <iomanip>

class ClapTrap{
	private:
		std::string _name;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;

	public:
		ClapTrap();
		ClapTrap(ClapTrap &clapTrap);
		ClapTrap(std::string name);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &clapTrap);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void showStats();
};



#endif

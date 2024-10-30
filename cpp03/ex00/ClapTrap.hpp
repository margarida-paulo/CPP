#ifndef CLAPTRAP
# define CLAPTRAP

#include <iostream>
#include <cstring>

class ClapTrap{
	private:
		std::string name;
		int hitPoints = 10;
		int energyPoints = 10;
		int attackDamage = 0;

	public:
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};



#endif

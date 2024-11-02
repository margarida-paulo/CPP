#ifndef DIAMONDTRAP
# define DIAMONDTRAP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap: public FragTrap, public ScavTrap{
	private:
		std::string _name;

	public:
	DiamondTrap();
	DiamondTrap(std::string name);
	DiamondTrap(DiamondTrap &other);
	~DiamondTrap();
	DiamondTrap &operator=(DiamondTrap &toCopy);
	std::string type() const;
	void attack(const std::string& target);
	void whoAmI();
};

#endif
#ifndef FRAGTRAP
# define FRAGTRAP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap{
	public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap &other);
	FragTrap &operator=(const FragTrap &toCopy);
	~FragTrap();
	void highFivesGuys(void);
	std::string type() const;
	void showStats();
};

#endif

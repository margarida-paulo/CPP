#ifndef FRAGTRAP
# define FRAGTRAP

#include "ClapTrap.hpp"

/*We make ClapTrap virtual so that, when one class inherits
from multiple ClapTrap subclasses, there is only one instance
of ClapTrap, avoiding the diamond problem.*/
class FragTrap: public virtual ClapTrap{
	protected:
		int _fragAttackDamage;

	public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap &other);
	FragTrap &operator=(const FragTrap &toCopy);
	~FragTrap();
	void highFivesGuys(void);
	std::string type() const;
	virtual void showStats();
};

#endif

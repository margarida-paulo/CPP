#include "ClapTrap.hpp"
#include <stdlib.h>

int main(void){

	ClapTrap rita("Rita");

	rita.showStats();

	for (int i = 0; i < 13; i++)
		rita.attack("John");
	rita.beRepaired(3);
	rita.takeDamage(5);

	rita.showStats();
}
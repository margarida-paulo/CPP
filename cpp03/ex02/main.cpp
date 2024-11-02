#include "ClapTrap.hpp"
#include <stdlib.h>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"


int main(void){

	ClapTrap rita;
	ScavTrap john("John");
	FragTrap adam("Adam");

	rita.showStats();
	john.showStats();
	adam.showStats();
	john.guardGate();
	adam.highFivesGuys();
}
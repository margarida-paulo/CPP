#include "ClapTrap.hpp"
#include <stdlib.h>
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(void){

	DiamondTrap joana("Joana");
	joana.whoAmI();
	joana.attack("João");
}
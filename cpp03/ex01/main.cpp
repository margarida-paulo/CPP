#include "ClapTrap.hpp"
#include <stdlib.h>
#include "ScavTrap.hpp"

void showHelp(){
	std::cout << "-----------" << std::endl;
	std::cout << "OPTIONS:" << std::endl;
	std::cout << "Attack" << std::endl;
	std::cout << "Repair" << std::endl;
	std::cout << "TakeDamage" << std::endl;
	std::cout << "GuardGate" << std::endl;
	std::cout << "Stats" << std::endl;
	std::cout << "Help" << std::endl;
	std::cout << "Exit" << std::endl;
	std::cout << "-----------" << std::endl << std::endl;
}
int main(void){

	ScavTrap john("John");
	john.showStats();
	showHelp();
	while(true){
		std::string buffer;
		std::cout << "Enter your option:" << std::endl;
		std::cin >> buffer;
		if (buffer == "Attack")
		{
			std::cout << "Who do you want to attack?" << std::endl;
			buffer.clear();
			std::cin >> buffer;
			john.attack(buffer);
			john.showStats();
		} else if (buffer == "Repair"){
			int points;
			std::cout << "How many Hit Points do you want to get?" << std::endl;
			buffer.clear();
			std::cin >> points;
			john.beRepaired(points);
			john.showStats();
		} else if (buffer == "TakeDamage"){
			int points;
			std::cout << "How many Hit Points are you losing?" << std::endl;
			std::cin >> points;
			john.takeDamage(points);
			john.showStats();
		} else if (buffer == "GuardGate"){
			john.guardGate();
		} else if (buffer == "Stats"){
			john.showStats();
		} else if (buffer == "Help"){
			showHelp();
		} else if (buffer == "Exit"){
			return 0;
		}
		buffer.clear();
	}
	john.showStats();
}

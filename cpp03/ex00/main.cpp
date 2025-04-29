#include "ClapTrap.hpp"
#include <stdlib.h>

void showHelp(){
	std::cout << "-----------" << std::endl;
	std::cout << "OPTIONS:" << std::endl;
	std::cout << "Attack" << std::endl;
	std::cout << "Repair" << std::endl;
	std::cout << "TakeDamage" << std::endl;
	std::cout << "Stats" << std::endl;
	std::cout << "Help" << std::endl;
	std::cout << "Exit" << std::endl;
	std::cout << "-----------" << std::endl << std::endl;
}

int main(void){

	ClapTrap rita("Rita");

	rita.showStats();
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
			rita.attack(buffer);
			rita.showStats();
		} else if (buffer == "Repair"){
			int points;
			std::cout << "How many Hit Points do you want to get?" << std::endl;
			buffer.clear();
			std::cin >> points;
			rita.beRepaired(points);
			rita.showStats();
		} else if (buffer == "TakeDamage"){
			int points;
			std::cout << "How many Hit Points are you losing?" << std::endl;
			std::cin >> points;
			rita.takeDamage(points);
			rita.showStats();
		} else if (buffer == "Stats"){
			rita.showStats();
		} else if (buffer == "Help"){
			showHelp();
		} else if (buffer == "Exit"){
			return 0;
		}
		buffer.clear();
	}
}

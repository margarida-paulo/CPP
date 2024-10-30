#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "ClapTrap's default constructor was called" << std::endl;
	_name = "Default name";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(std::string name){
	std::cout << "ClapTrap's name constructor was called" << std::endl;
	this->_name = name;
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(ClapTrap &clapTrap){
	std::cout << "ClapTrap's copy constructor was called" << std::endl;
	this->_name = clapTrap._name;
	this->_hitPoints = clapTrap._hitPoints;
	this->_energyPoints = clapTrap._energyPoints;
	this->_attackDamage = clapTrap._attackDamage;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap's destructor was called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &clapTrap) {
	this->_name = clapTrap._name;
	this->_hitPoints = clapTrap._hitPoints;
	this->_energyPoints = clapTrap._energyPoints;
	this->_attackDamage = clapTrap._attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string& target){
	if (_energyPoints > 0 && _hitPoints > 0){
		std::cout << "ClapTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage! " << std::endl;
		_energyPoints--;
	} else if (_hitPoints == 0){
			std::cout << "ClapTrap is dead, attack not performed!" << std::endl;
	} else
		std::cout << "ClapTrap doesn't have energy, attack not performed!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if(_hitPoints - amount < 0)
		_hitPoints = 0;
	else
		_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " got a damage of " << amount << " hit points, having now " << _hitPoints << " points of health! " << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount){
	if (_energyPoints > 0 && _hitPoints > 0){
		_hitPoints += amount;
		std::cout << "ClapTrap " << _name << " repaired itself by " << amount << " hit points, having now " << _hitPoints << " hit points! " << std::endl;
		_energyPoints--;
	} else if (_hitPoints == 0){
			std::cout << "ClapTrap is dead, reparation not possible!" << std::endl;
	} else
		std::cout << "ClapTrap doesn't have energy, reparation not possible!" << std::endl;
}

void ClapTrap::showStats(){

	//Calculate maximum width
	unsigned long width = ("ClapTrap " + _name).size() + 1;
	if (("Hit points: " + std::to_string(_hitPoints)).size() > width)
		width = ("Hit points: " + std::to_string(_hitPoints)).size() + 1;
	else if (("Energy points: " + std::to_string(_energyPoints)).size() > width)
		width = ("Energy points: " + std::to_string(_energyPoints)).size() + 1;
	else if (("Attack damage: " + std::to_string(_attackDamage)).size() > width)
		width = ("Attack damage: " + std::to_string(_attackDamage)).size() + 1;

	std::cout << std::endl;
	std::cout << "|" << std::left << std::setw(width) << "ClapTrap " + _name << "|" << std::endl;
	std::cout << "|"  << std::left << std::setw(width) << "Hit points: " + std::to_string(_hitPoints) << "|" << std::endl;
	std::cout << "|" << std::left << std::setw(width) <<"Energy points: " + std::to_string(_energyPoints) << "|" << std::endl;
	std::cout << "|" << std::left << std::setw(width) <<"Attack damage: " + std::to_string(_attackDamage) << "|" << std::endl;
	std::cout << std::right << std::endl;

}
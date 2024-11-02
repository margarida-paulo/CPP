#include "ScavTrap.hpp"

std::string ScavTrap:: type() const{
	return "ScavTrap";
}

ScavTrap::ScavTrap(): ClapTrap(){
	std::cout << "ScavTrap's default constructor was called" << std::endl;
	this->_hitPoints = 100;
	this -> _energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap &scavTrap): ClapTrap(scavTrap._name){
	std::cout << "ScavTrap's copy constructor was called" << std::endl;
	this->_hitPoints = scavTrap._hitPoints;
	this -> _energyPoints = scavTrap._energyPoints;
	this->_attackDamage = scavTrap._attackDamage;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	std::cout << "ScavTrap's name constructor was called (" << name << ")" << std::endl;
	this->_hitPoints = 100;
	this -> _energyPoints = 50;
	this->_attackDamage = 20;	
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap's destructor was called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavTrap){
	this->_name = scavTrap._name;
	this->_hitPoints = scavTrap._hitPoints;
	this -> _energyPoints = scavTrap._energyPoints;
	this->_attackDamage = scavTrap._attackDamage;
	return *this;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode" << std::endl;
}

void ScavTrap::attack(const std::string& target){
	if (_energyPoints > 0 && _hitPoints > 0){
		std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _attackDamage << " points of damage! " << std::endl;
		_energyPoints--;
	} else if (_hitPoints == 0){
			std::cout << "ScavTrap " << _name << " is dead, attack not performed!" << std::endl;
	} else
		std::cout << "ScavTrap " << _name << " doesn't have energy, attack not performed!" << std::endl;
}
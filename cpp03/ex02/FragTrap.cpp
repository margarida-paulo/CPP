#include "FragTrap.hpp"

FragTrap::FragTrap(){
	std::cout << "FragTrap's default constructor was called" << std::endl;
	this->_name = "Default name";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
	std::cout << "FragTrap's name constructor was called (" << name << ")" << std::endl;
	this->_name = name;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
}

FragTrap::FragTrap(FragTrap &other){
	std::cout << "FragTrap's copy constructor was called" << std::endl;
	this->_name = other._name;
	this->_hitPoints = other._hitPoints;
	this->_energyPoints = other._energyPoints;
	this->_attackDamage = other._attackDamage;
}

FragTrap &FragTrap:: operator=(const FragTrap &toCopy){
	this->_name = toCopy._name;
	this->_hitPoints = toCopy._hitPoints;
	this->_energyPoints = toCopy._energyPoints;
	this->_attackDamage = toCopy._attackDamage;
	return *this;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap's destructor was called" << std::endl;
}

void FragTrap::highFivesGuys(void){
	std::cout << "FragTrap " << _name << " wants a high five!" << std::endl;
}

std::string FragTrap:: type() const{
	return "FragTrap";
}

void FragTrap::showStats(){
	std::cout << std::endl;
	std::cout << "FragTrap " + _name<< std::endl;
	std::cout << "Hit points: " << _hitPoints <<std::endl;
	std::cout <<"Energy points: " << _energyPoints << std::endl;
	std::cout <<"Attack damage: " << _attackDamage << std::endl;
	std::cout << std::endl;
}

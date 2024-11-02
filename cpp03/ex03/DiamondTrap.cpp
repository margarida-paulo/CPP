#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default DiamondTrap_clap_name"), FragTrap(), ScavTrap(), _name("Default DiamondTrap")
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

std::string DiamondTrap::type() const{
	return "DiamondTrap";
}

DiamondTrap::DiamondTrap(std::string name) : FragTrap(name + "_clap_name"), ScavTrap() {
    _name = name;
	std::cout << "DiamondTrap's name constructor was called (" << name << ")" << std::endl;
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap &other){
	std::cout << "DiamondTrap's copy constructor was called" << std::endl;
	_name = other._name;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	ClapTrap::_name = other.ClapTrap::_name;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap's destructor was called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &toCopy){
	_name = toCopy._name;
	_hitPoints = toCopy._hitPoints;
	_energyPoints = toCopy._energyPoints;
	_attackDamage = toCopy._attackDamage;
	ClapTrap::_name = toCopy.ClapTrap::_name;	
	return *this;
}

void DiamondTrap::attack(const std::string& target){
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(){
	std::cout << "I am DiamondTrap " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
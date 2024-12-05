#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("Default DiamondTrap_clap_name"), FragTrap("Default DiamondTrap_clap_name"), ScavTrap("Default DiamondTrap_clap_name"), _name("Default DiamondTrap")
{
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_fragAttackDamage;
	std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

std::string DiamondTrap::type() const{
	return "DiamondTrap";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name"), _name(name) {
	std::cout << "DiamondTrap's name constructor was called (" << name << ")" << std::endl;
    _hitPoints = FragTrap::_hitPoints;
    _energyPoints = ScavTrap::_energyPoints;
    _attackDamage = FragTrap::_fragAttackDamage;
}

DiamondTrap::DiamondTrap(DiamondTrap &other) : ClapTrap(other.ClapTrap::_name), FragTrap(other.ClapTrap::_name), ScavTrap(other.ClapTrap::_name), _name(other._name) {
	std::cout << "DiamondTrap's copy constructor was called" << std::endl;
	_hitPoints = other._hitPoints;
	_energyPoints = other._energyPoints;
	_attackDamage = other._attackDamage;
	ClapTrap::_name = other.ClapTrap::_name;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap's destructor was called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap &toCopy) {
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


void DiamondTrap::showStats(){
	std::cout << std::endl;
	std::cout << "DiamondTrap " + _name << std::endl;
	std::cout << "Clap_name " + ClapTrap::_name << std::endl;
	std::cout << "Hit points: " << _hitPoints <<std::endl;
	std::cout <<"Energy points: " << _energyPoints << std::endl;
	std::cout <<"Attack damage: " << _attackDamage << std::endl;
	std::cout << std::endl;
}

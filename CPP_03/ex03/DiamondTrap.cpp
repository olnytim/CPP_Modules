#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap() {
	cout << "DiamondTrap: Default constructor called" << endl;
	this->_name = "NoName";
	ClapTrap::_name = this->_name + "_clap_name";
	_attack = FragTrap::getAttack();
	_energy = ScavTrap::getEnergy();
	_health = FragTrap::getHealth();
}

DiamondTrap::~DiamondTrap() {
	cout << "DiamondTrap: Destructor called" << endl;
}

DiamondTrap::DiamondTrap(string name) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	cout << "DiamondTrap: Name constructor called" << endl;
	this->_name = name;
	ClapTrap::_name = this->_name + "_clap_name";
	_attack = FragTrap::getAttack();
	_energy = ScavTrap::getEnergy();
	_health = FragTrap::getHealth();
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap &toCopy) {
	cout << "ScavTrap: Copy assignment operator called" << endl;
	ClapTrap::operator=(toCopy);
	return *this;
}

DiamondTrap::DiamondTrap(const DiamondTrap &toCopy) : ScavTrap(toCopy), FragTrap(toCopy) {
	cout << "ScavTrap: Copy constructor called" << endl;
	*this = toCopy;
}

void DiamondTrap::whoAmI() {
	cout << "DiamondTrap name is: " << this->_name << " and his ClapTrap name is: " << ClapTrap::_name << endl;
}

void DiamondTrap::attack(const string &target) {
	ScavTrap::attack(target);
}
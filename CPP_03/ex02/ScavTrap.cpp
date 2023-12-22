#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	cout << "ScavTrap: Default constructor called" << endl;
	_name = "NoName";
	_attack = 20;
	_energy = 50;
	_health = 100;
}

ScavTrap::~ScavTrap() {
	cout << "ScavTrap: Destructor called" << endl;
}

ScavTrap::ScavTrap(string name) : ClapTrap(name) {
	cout << "ScavTrap: Name constructor called" << endl;
	_attack = 20;
	_energy = 50;
	_health = 100;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &toCopy) {
	cout << "ScavTrap: Copy assignment operator called" << endl;
	ClapTrap::operator=(toCopy);
	return *this;
}

ScavTrap::ScavTrap(const ScavTrap &toCopy) : ClapTrap(toCopy) {
	cout << "ScavTrap: Copy constructor called" << endl;
	*this = toCopy;
}

void ScavTrap::guardGate() {
	cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << endl;
}

void ScavTrap::attack(const string &target) {
	if (_health > 0 && _energy > 0) {
		cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attack << " points of damage!" << endl;
		_energy--;
	}
	else { cout << "ScavTrap " << _name << " can't do this!" << endl; }
}
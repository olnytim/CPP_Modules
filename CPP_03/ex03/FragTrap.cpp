#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	cout << "FragTrap: Default constructor called" << endl;
	_name = "NoName";
	_attack = 30;
	_energy = 100;
	_health = 100;
}

FragTrap::FragTrap(string name) : ClapTrap(name) {
	cout << "FragTrap: Name constructor called" << endl;
	_name = name;
	_attack = 30;
	_energy = 100;
	_health = 100;
}

FragTrap::~FragTrap() { cout << "FragTrap: Destructor called" << endl; }

FragTrap::FragTrap(const FragTrap &toCopy) {
	cout << "FragTrap: Copy constructor called" << endl;
	*this = toCopy;
}

FragTrap& FragTrap::operator=(const FragTrap &toCopy) {
	cout << "FragTrap: Copy assignment operator called" << endl;
	ClapTrap::operator=(toCopy);
	return *this;
}

void FragTrap::highFivesGuys() {
	cout << "FragTrap " << _name << " gave high five" << endl;
}